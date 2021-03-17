from socket import *
import os
import sys
import struct
import time
import select
import binascii

import math

ICMP_ECHO_REQUEST = 8

def checksum(string): 
    csum = 0
    countTo = (len(string) // 2) * 2 
    count = 0

    while count < countTo:
        thisVal = string[count+1] * 256 + string[count] 
        csum = csum + thisVal 
        csum = csum & 0xffffffff 
        count = count + 2
    
    if countTo < len(string):
        csum = csum + string[len(string) - 1]
        csum = csum & 0xffffffff 

    csum = (csum >> 16) + (csum & 0xffff)
    csum = csum + (csum >> 16)
    answer = ~csum 
    answer = answer & 0xffff 
    answer = answer >> 8 | (answer << 8 & 0xff00)
    return answer

def receiveOnePing(mySocket, ID, timeout, destAddr):
    global roundTTCount
    global roundTTSum
    global roundTTMax
    global roundTTMin

    timeLeft = timeout
   
    while 1: 
        startedSelect = time.time()
        whatReady = select.select([mySocket], [], [], timeLeft)
        howLongInSelect = (time.time() - startedSelect)
        if whatReady[0] == []: # Timeout
            return "Request timed out."

        timeReceived = time.time() 
        recPacket, addr = mySocket.recvfrom(1024)
        
		# 20 because 160 / 8 for each byte is 20
		# And ICMP header starts after bit 160
        icmpHeader = recPacket[20:28]
		# Now that we have the header unpack the rest
        icmpType, code, mychecksum, packetID, sequence = struct.unpack("bbHHh", icmpHeader)

		# Type must be set to 8 
        if type != 8 and packetID == ID:
            bytesRec = struct.calcsize("d") # d for double
            timeToSend = struct.unpack("d", recPacket[28:28 + bytesRec])[0] 

            roundTT = (timeReceived - timeToSend) * 1000 # Change milliseconds to seconds
            roundTTCount += 1 # Count for average
            roundTTSum += roundTT # Add up each round trip time
            roundTTMax = max(roundTTMax, roundTT) # Get the max from current round trip time compared to current max
            roundTTMin = min(roundTTMin, roundTT) # Get the min from current round trip time compare to current min

            return timeReceived - timeToSend 

        #Fill in start

        #Fetch the ICMP header from the IP packet

        #Fill in end

        timeLeft = timeLeft - howLongInSelect

        if timeLeft <= 0:
            return "Request timed out."

def sendOnePing(mySocket, destAddr, ID):
    # Header is type (8), code (8), checksum (16), id (16), sequence (16)

    myChecksum = 0
    # Make a dummy header with a 0 checksum
    # struct -- Interpret strings as packed binary data
    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
    data = struct.pack("d", time.time())
    # Calculate the checksum on the data and the dummy header.
    #myChecksum = checksum(str(header + data))
    myChecksum = checksum(header + data)

    # Get the right checksum, and put in the header
    if sys.platform == 'darwin':
    # Convert 16-bit integers from host to network byte order
        myChecksum = htons(myChecksum) & 0xffff
    else:
        myChecksum = htons(myChecksum)

    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
    packet = header + data

    mySocket.sendto(packet, (destAddr, 1)) # AF_INET address must be tuple, not str
    # Both LISTS and TUPLES consist of a number of objects
    # which can be referenced by their position number within the object.

def doOnePing(destAddr, timeout): 
    icmp = getprotobyname("icmp")
    # SOCK_RAW is a powerful socket type. For more details: http://sockraw.org/papers/sock_raw

    mySocket = socket(AF_INET, SOCK_RAW, icmp)

    myID = os.getpid() & 0xFFFF # Return the current process id
    sendOnePing(mySocket, destAddr, myID)
    delay = receiveOnePing(mySocket, myID, timeout, destAddr)
    mySocket.close()
    return delay

def ping(host, timeout=1):
    global roundTTCount
    global roundTTSum
    global roundTTMax
    global roundTTMin
	
    #if (roundTTMin == math.inf):
        #roundTTMin = 0
    # timeout=1 means: If one second goes by without a reply from the server,
    # the client assumes that either the client's ping or the server's pong is lost
    dest = gethostbyname(host)
    print("Pinging " + dest + " using Python:")
    print("")
    # Send ping requests to a server separated by approximately one second
    count = 0
	# Ping a total of 5 times - chosen from standard UNIX amount
    while count < 5:
        delay = doOnePing(dest, timeout)
        print("Delay: ", delay)
        time.sleep(1) # one second
        count += 1

    if (roundTTMin == math.inf):
        roundTTMin = 0
    packLoss = 100 - roundTTCount * 100 / count
    print("\nMAX round trip time: {:.2f}".format(roundTTMax))
    print("MIN round trip time: {:.2f}".format(roundTTMin))
    print("SUM round trip time: {:.2f}".format(roundTTSum))
    if (roundTTCount != 0):
        print("Average round trip time: {:.2f}".format(roundTTSum / roundTTCount))
    else:
        print("Average round trip time: 0")
    print("Packet Loss: ",packLoss)

    return delay

def main():
    global roundTTCount
    global roundTTSum
    global roundTTMax
    global roundTTMin
    roundTTCount, roundTTSum, roundTTMax, roundTTMin = 0, 0, 0, math.inf # math.inf to find min

    userInput = str(input("Enter a place to ping: "))
    print("Pinging " + userInput)
    ping(userInput)

if __name__ == "__main__":
    main()