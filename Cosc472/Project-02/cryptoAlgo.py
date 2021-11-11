"""
    Project: Cryptography Algorithms Implementaion
    Name: Cody Murrer
    Date: 11/10/2021
    Class: Cosc-472 Netork Security
"""

import os
from typing import final

# input e to encrypt
# input d to decrypt
# input q to quit

# quality of life function
# clears console so it isnt cluttered
def clearConsole():
    command = 'clear'
    if os.name in ('nt','dos'):
        command = 'cls'
    os.system(command)

def readFile(filePath):
    with open(filePath,'r') as file:
        plainText = file.read()
    file.close
    clearConsole()
    return plainText

# Function 
def writeFile(fileName,encText, key):
    file = open(fileName+str(key)+".txt",'w')
    file.write(encText)
    file.close

# Caesar Cipher Encrytion
def caesar_cipher(filePath, key):
    if key < 0 or key > 25:
        clearConsole()
        print("Incorrect key size returning to start\n")
        return -1
    plainText = readFile(filePath)
    result = ""
    # 65-90 uppercase ascii
    # 97-122 lowercase ascii
    for i in range(len(plainText)):
        char = plainText[i]
        if(char.isupper()):
            result+=chr((ord(char)+ key-65)%26+65)
        elif(char == " "):
            result+=char
        elif(ord(char)>32 and ord(char)<48 or ord(char)>57 and ord(char)<65 or ord(char)>90 and ord(char)<97 or ord(char)>122):
            result+=char
        else:
            result+= chr((ord(char)+key-97)%26+97)

    encName = "caesar_cipher_"
    writeFile(result,key)

# Caesar Cipher Decryption
 
# Mono Alphabetic Cipher Encryption
def mono_alpha_cipher(filePath, key):
    plainText = readFile(filePath)
    plainTextDic = "abcdefghijklmnopqrstuvwxyz"
    key += plainTextDic
    buf = list(key)
    index = 0
    result = ""
    # Traverse through all characters
    for i in range(0, len(buf)):  
        for j in range(0, i + 1):
            if (buf[i] == buf[j]):
                break 
        if (j == i):
            buf[index] = buf[i]
            index += 1
    finalKey = "".join(buf[:index])

    for i in range(len(plainText)):
        char = plainText[i]
        if char.lower() in plainTextDic:
            keyIndex = plainTextDic.find(char.lower())
            if char.isupper():
                result+=finalKey[keyIndex].upper()
            else:
                result+=finalKey[keyIndex].lower()
        else:
            result+=char       

    encName = "mono_alpha_cipher_"
    writeFile(encName,result,key)

# Mono Alphabetic Cipher Decryption

# Poly Alphabetic Cipher Encryption
def poly_alpha_cipher(filePath, key):
    plainText = readFile(filePath)
    text = []
    result = ""
    buf = list(key)
    if(len(plainText) == len(buf)):
        finalKey = key
    else:
        for i in range(len(plainText)-len(buf)):
            buf.append(buf[i%len(buf)])
    finalKey = "".join(buf)
    
    for i in range(len(plainText)):
        temp = (ord(plainText[i])+ord(finalKey[i]))%26
        #temp += ord('a')
        text.append(chr(temp))
    result = "".join(text)
    print(result)
#    encName = "poly_alpha_cipher_"
#    writeFile(encName,result,key)

# Poly Alphabetic Cipher Decryption

# Toy Tetragraph Hash Encryption

# Toy Tetragraph Hash Decryption

# Main driver

def main():
    clearConsole()
    while True:
        print("Would you like to:")
        print("1) Encypt a file (e)\n2) Decrypt a file(d)\n3) Quit (q)")
        usrInput = input()
        if usrInput == 'e':
            clearConsole()
            print("Which algorithm would you like to use")
            print("1) Caesar Cipher (c)\n2) Mono Alphabetic Cipher (m)\n3) Poly alphabetic Cipher (p)\n4) Toy Tetragraph Hash (t)\n5) Back (b)")
            cipherChoice = input()
            if cipherChoice == 'c':
                encryptFile = input("Enter a file to encrypt: ")
                encryptKey = input("Enter the files encryption key (0-25): ")
                caesar_cipher(encryptFile,int(encryptKey))
            elif cipherChoice == 'm':
                encryptFile = input("Enter a file to encrypt: ")
                encryptKey = input("Enter the files encryption key (aphabetic string): ")
                mono_alpha_cipher(encryptFile,encryptKey)
            elif cipherChoice == 'p':
                encryptFile = input("Enter a file to encrypt: ")
                encryptKey = input("Enter the files encryption key (aphabetic string): ")
                poly_alpha_cipher(encryptFile,encryptKey)
            elif cipherChoice == 't':
                print("Using Toy Tetragraph Hash")
            elif cipherChoice == 'b':
                clearConsole()
                continue
            else:
                clearConsole()
                print("Incorrect input returning to main menu\n")
                continue
        elif usrInput == 'd':
            clearConsole()
            print("Which algorithm would you like to use")
            print("1) Caesar Cipher (c)\n2) Mono Alphabetic Cipher (m)\n3) Poly alphabetic Cipher (p)\n4) Toy Tetragraph Hash (t)\n5) Back (b)")
            cipherChoice = input()
            if cipherChoice == 'c':
                encryptFile = input("Enter a file to decrypt: ")
                encryptKey = input("Enter the files decryption key (0-25)")
            elif cipherChoice == 'm':
                print("Using Mono Alphabetic Cipher")
            elif cipherChoice == 'p':
                print("Using Poly alphabetic Cipher")
            elif cipherChoice == 't':
                print("Using Toy Tetragraph Hash")
            elif cipherChoice == 'b':
                clearConsole()
                continue
        elif usrInput == 'q':
            print("Quitting")
            break
        else:
            clearConsole()
            print("Incorrect input\n")
            continue

if __name__ == "__main__":
    main()