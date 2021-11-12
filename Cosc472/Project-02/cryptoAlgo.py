"""
    Project: Cryptography Algorithms Implementaion
    Name: Cody Murrer
    Date: 11/10/2021
    Class: Cosc-472 Netork Security
"""

import os
import os.path
import string
import numpy as np

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
    if os.path.isfile(filePath):
        with open(filePath,'r') as file:
            plainText = file.read()
        file.close
        clearConsole()
        return plainText
    else:
        return ""

# Function 
def writeFile(fileName,encText, key):
    file = open(fileName+str(key)+".txt",'w')
    file.write(encText)
    file.close

#gets the key for mono and poly alpha cipher
def key_gen(method, key, plainText):
    if(method == "poly"):
        key = list(key)
        if(len(plainText) == len(key)):
            return key
        else:
            for i in range(len(plainText)-len(key)):
                key.append(key[i%len(key)])
        return("".join(key))
    elif(method == "mono"):
        plainTextDic = "abcdefghijklmnopqrstuvwxyz"
        key += plainTextDic
        buf = list(key)
        index = 0
        for i in range(0, len(buf)):  
            for j in range(0, i + 1):
                if (buf[i] == buf[j]):
                    break 
            if (j == i):
                buf[index] = buf[i]
                index += 1
        finalKey = "".join(buf[:index])
        return finalKey

# Caesar Cipher Encrytion
def caesar_cipher(filePath, key):
    if key < 0 or key > 25:
        clearConsole()
        print("Incorrect key size returning to start\n")
        return -1
    if filePath == "":
        clearConsole()
        print("No file path was added returning to start")
        return -1
    plainText = readFile(filePath)
    if plainText == "":
        clearConsole()
        print("No file found returning to start")
        return -1

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

    encName = "caesar_encrypt_"
    writeFile(encName,result,key)

# Caesar Cipher Decryption
def caesar_cipher_decrypt(filePath, key):
    if key < 0 or key > 25:
        clearConsole()
        print("Incorrect key size returning to start\n")
        return -1
    if filePath == "":
        clearConsole()
        print("No file path was added returning to start")
        return -1

    encText = readFile(filePath)
    result = ""
    tempDic = string.ascii_lowercase
    for i in range(len(encText)):
        char = encText[i]
        if(char.isupper()):
            result+=chr((ord(char)- key-65)%26+65)
        elif(char == " "):
            result+=char
        elif(ord(char)>32 and ord(char)<48 or ord(char)>57 and ord(char)<65 or ord(char)>90 and ord(char)<97 or ord(char)>122):
            result+=char
        else:
            result+= chr((ord(char)-key-97)%26+97)
    decName = "caesar_decrypt_"
    writeFile(decName,result,key)

# Mono Alphabetic Cipher Encryption
def mono_alpha_cipher(filePath, key):
    if len(key) > 6:
        clearConsole()
        print("Key size is too large returning to start")
        return -1
    if filePath == "":
        clearConsole()
        print("No file path was added returning to start")
        return -1

    plainText = readFile(filePath)
    plainTextDic = "abcdefghijklmnopqrstuvwxyz"
    finalKey = key_gen("mono", key,"")
    result = ""

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

    encName = "mono_encrypt_"
    writeFile(encName,result,key)

# Mono Alphabetic Cipher Decryption
def mono_alpha_decrypt(filePath,key):
    if len(key) > 6:
            clearConsole()
            print("Key size is too large returning to start")
            return -1
    if filePath == "":
        clearConsole()
        print("No file path was added returning to start")
        return -1

    plainText = readFile(filePath)
    plainTextDic = "abcdefghijklmnopqrstuvwxyz"
    finalKey = key_gen("mono", key,"")
    result = ""

    for i in range(len(plainText)):
        char = plainText[i]
        if char.lower() in plainTextDic:
            keyIndex = finalKey.find(char.lower())
            if char.isupper():
                result+=plainTextDic[keyIndex].upper()
            else:
                result+=plainTextDic[keyIndex].lower()
        else:
            result+=char 
    print(result)

# Poly Alphabetic Cipher Encryption
def poly_alpha_cipher(filePath, key):
    if len(key) > 3:
        clearConsole()
        print("Key size is too large returning to start")
        return -1
    if filePath == "":
        clearConsole()
        print("No file path was added returning to start")
        return -1

    plainText = readFile(filePath)
    if plainText == "":
        clearConsole()
        print("Text file was not found or empty returning to start")
        return -1

    text = []
    result = ""
    finalKey = key_gen("poly", key, plainText)
    start = ord('a')

    for i,j in zip(plainText,finalKey):
        shift = ord(j) - start
        pos = start + (ord(i) - start + shift)%26
        text.append(chr(pos))
    result = ''.join(text)

    encName = "poly_encrypt_"
    writeFile(encName,result,key)

# Poly Alphabetic Cipher Decryption
def poly_alpha_decrypt(filePath,key):
    if len(key) > 3:
        clearConsole()
        print("Key size is too large returning to start")
        return -1
    if filePath == "":
        clearConsole()
        print("No file path was added returning to start")
        return -1

    encText = readFile(filePath)
    if encText == "":
        clearConsole()
        print("Text file was not found or empty returning to start")
        return -1

    if encText == "":
        clearConsole()
        print("Text file was not found or empty returning to start")
        return -1

    finalKey = key_gen("poly", key, encText)
    text = []
    result = ""
    for i in range(len(encText)):
        x = (ord(encText[i])-ord(finalKey[i])+26)%26
        x+= ord('a')
        text.append(chr(x))
    result+="".join(text)
    
    decName = "poly_decrypt_"
    writeFile(decName,result,key)

# Toy Tetragraph Hash Encryption
def toy_tetra_hash(filePath):
    numToChar={0:'a',1:'b',2:'c',3:'d',4:'e',5:'f',6:'g',7:'h',8:'i',9:'j',10:'k',11:'l',12:'m',13:'n',14:'o',15:'p',16:'q',17:'r',18:'s',19:'t',20:'u',21:'v',22:'w',23:'x',24:'y',25:'z',26:' '}
    charToNum={'a':0,'b':1,'c':2,'d':3,'e':4,'f': 5,'g':6,'h':7,'i':8,'j':9,'k':10,'l':11,'m':12,'n':13,'o':14,'p':15,'q':16,'r':17,'s':18,'t':19,'u':20,'v':21,'w':22,'x':23,'y':24,'z':25,' ':26}
    plainText = readFile(filePath)
    if plainText == "":
        clearConsole()
        print("Text file was not found or empty returning to start")
        return -1
        
    txtLen = len(plainText)

    if(txtLen<16):
        for i in range(txtLen,16):
            plainText += 'a'
    buf=np.array([[]])
    buf2=np.array([[]])
    buf3=np.array([[]])
    buf4=np.array([[]])
    index = 0
    for i in plainText:
        if index<16:
            buf = np.append(buf,charToNum[i])
        elif index>16 and index < 33:
            buf2 = np.append(buf2,charToNum[i])
        elif index>32 and index < 49:
            buf3 = np.append(buf3,charToNum[i])
        elif index>48:
            buf4 = np.append(buf4,charToNum[i])

        index+=1
    if(buf4.size < 16):
        temp = 16 - buf4.size
        for i in range(6,16):
            buf4 = np.append(buf4,0)
    a = buf.reshape(4,4)
    b = buf2.reshape(4,4)
    c = buf3.reshape(4,4)
    d = buf4.reshape(4,4)

    passOne = a.sum(axis=0)%26
    passOne1 = b.sum(axis=0)%26
    passOne2 = c.sum(axis=0)%26
    passOne3 = d.sum(axis=0)%26

    col1 = col2 = col3 = col4 = a
    col1b = col2b = col3b = col4b = a
    col1c = col2c = col3c = col4c = a
    col1d = col2d = col3d = col4d = a
    col1 = np.roll(col1[0],3)
    col2 = np.roll(col2[1],2)
    col3 = np.roll(col3[2],1)
    col4 = np.fliplr(col4)
    col4 = np.roll(col1[3],4)

    col1b = np.roll(col1b[0],3)
    col2b = np.roll(col2b[1],2)
    col3b = np.roll(col3b[2],1)
    col4b = np.fliplr(col4b)
    col4b = np.roll(col1b[3],4)

    col1c = np.roll(col1c[0],3)
    col2c = np.roll(col2c[1],2)
    col3c = np.roll(col3c[2],1)
    col4c = np.fliplr(col4c)
    col4c = np.roll(col1c[3],4)

    col1d = np.roll(col1d[0],3)
    col2d = np.roll(col2d[1],2)
    col3d = np.roll(col3d[2],1)
    col4d = np.fliplr(col4d)
    col4d = np.roll(col1d[3],4)

    passTwo = (col1+col2+col3+col4)%26
    passTwo1 = (col1b+col2b+col3b+col4b)%26
    passTwo2 = (col1c+col2c+col3c+col4c)%26
    passTwo3 = (col1d+col2d+col3d+col4d)%26

    total = (passOne+passOne1+passOne2+passOne3+passTwo+passTwo1+passTwo2+passTwo3)%26
    tempTotal = np.array([])
    result = ""
    for i in total:
        tempTotal = np.append(tempTotal,numToChar[i])
    result+="".join(np.array_str(tempTotal))
    encName = "hash_encrypt_"
    writeFile(encName,result,0000)

# Main driver
def main():
    clearConsole()
    while True:
        print("Would you like to:")
        print("1) Encypt a file (e)\n2) Decrypt a file(d)\n3) Quit (q)")
        usrInput = input()
        if usrInput == 'e':
            clearConsole()
            print("Which encryption algorithm would you like to use")
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
                encryptFile = input("Enter a file to encrypt: ")
                toy_tetra_hash(encryptFile)
            elif cipherChoice == 'b':
                clearConsole()
                continue
            else:
                clearConsole()
                print("Incorrect input returning to main menu\n")
                continue
        elif usrInput == 'd':
            clearConsole()
            print("Which decryption algorithm would you like to use")
            print("1) Caesar Cipher (c)\n2) Mono Alphabetic Cipher (m)\n3) Poly alphabetic Cipher (p)\n4) Toy Tetragraph Hash (t)\n5) Back (b)")
            cipherChoice = input()
            if cipherChoice == 'c':
                decryptFile = input("Enter a file to decrypt: ")
                decryptKey = input("Enter the files decryption key (0-25)")
                caesar_cipher_decrypt(decryptFile,int(decryptKey))
            elif cipherChoice == 'm':
                decryptFile = input("Enter a file to encrypt: ")
                decryptKey = input("Enter the files encryption key (aphabetic string): ")
                mono_alpha_decrypt(decryptFile,decryptKey)
            elif cipherChoice == 'p':
                decryptFile = input("Enter a file to encrypt: ")
                decryptKey = input("Enter the files encryption key (aphabetic string): ")
                poly_alpha_decrypt(decryptFile,decryptKey)
            elif cipherChoice == 'b':
                clearConsole()
                continue
            else:
                clearConsole()
                print("Incorrect input returning to main menu\n")
        elif usrInput == 'q':
            clearConsole()
            print("Quitting")
            break
        else:
            clearConsole()
            print("Incorrect input\n")
            continue

if __name__ == "__main__":
    main()