#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1
// checks to see if there are numbers
int check_if_number(char input){
    int number = (int) input;
    if(input >= (int)'0' && input <= (int)'9'){
        return number;
    }
    return 0;
}
// checks to see if there are characters
int check_if_char(char input){
    if((input>= (int)'a' && input<= (int)'z')||(input>=(int)'A'&&input<=(int)'Z')){
        return input;
    }
    return 0;
}
// checks to see if there are special characters
int check_if_other(char input){
    if((input>= (int)'!' && input<= (int)'/')||(input>=(int)':'&&input<=(int)'@')||(input>=(int)'['&&input<=(int)'`')||(input>=(int)'{'&&input<=(int)'~')){
        return input;
    }
    return 0;
}

int main(int argc, char* argv[]){
    if(argc != 6){
        printf("Not enough arguments passed\n");
        return 1;
    }
// ses the input file equal to the 1st argument passed through the command line
    int readFile = open(argv[1],O_RDONLY);
    if(readFile == -1){
        printf("File Error: could not open file\n");
        return 1;
    }
    umask(0);
// sets the alpha file equal to the 2nd argument passed through the command line with -rw-rw-rw permissions    
    int alphaFile = open(argv[2],O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(alphaFile == -1){
        printf("File Error: could not open or create file\n");
        close(readFile);
        return 1;
    }
// sets the num file equal to the 3rd argument passed through the command line with -rw-rw-rw permissions    
    int numFile = open(argv[3],O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(numFile == -1){
        printf("File Error: could not open or create file\n");
        close(readFile);
        close(alphaFile);
        return 1;
    }
// sets the other file equal to the 4th argument passed through the command line with -rw-rw-rw permissions    
    int otherFile = open(argv[4],O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(otherFile == -1){
        printf("File Error: could not open or create file\n");
        close(readFile);
        close(alphaFile);
        close(numFile);
        return 1;
    }
// sets the copy file equal to the 5th argument passed through the command line with -rw-rw-rw permissions
    int copyFile = open(argv[5],O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(copyFile == -1){
        printf("File Error: could not open or create file\n");
        close(readFile);
        close(alphaFile);
        close(numFile);
        close(otherFile);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int temp;
// reads the input file and write to the num file    
    while((temp=read(readFile,buffer,BUFFER_SIZE)>0)){
        if(check_if_number(buffer[0])){
            write(numFile, buffer, temp);
        }else if(buffer[0] == ' '){
            write(numFile," ",temp);
        }else if(buffer[0] == '\n'){
            write(numFile,"\n",temp);
        }else{
            write(numFile, " ",temp);
        }
    }
// reads the input file and write to the alpha file    
    lseek(readFile,0,SEEK_SET);
    while((temp=read(readFile,buffer,BUFFER_SIZE)>0)){
        if(check_if_char(buffer[0])){
            write(alphaFile, buffer, temp);
        }else if(buffer[0] == ' '){
            write(alphaFile," ",temp);
        }else if(buffer[0] == '\n'){
            write(alphaFile,"\n",temp);
        }else{
            write(alphaFile, " ",temp);
        }
    }
// reads the input file and write to the other file    
    lseek(readFile,0,SEEK_SET);
    while((temp=read(readFile,buffer,BUFFER_SIZE)>0)){
       if(check_if_other(buffer[0])){
            write (otherFile, buffer, temp);
        }else if(buffer[0] == ' '){
            write(otherFile," ",temp);
        }else if(buffer[0] == '\n'){
            write(otherFile,"\n",temp);
        }else{
            write(otherFile, " ",temp);
        }
    }
        int len = lseek(readFile,0,SEEK_END);
        char bufferAlpha;
        char bufferNum;
        char bufferOther;
        lseek(otherFile,0,SEEK_SET);
        lseek(numFile,0,SEEK_SET);
        lseek(alphaFile,0,SEEK_SET);
        while(len>0){
            read(alphaFile,&bufferAlpha,BUFFER_SIZE); // reads the alpha output file and sets the alpha buffer
            read(numFile,&bufferNum,BUFFER_SIZE); // reads the num output file and sets the num buffer
            read(otherFile,&bufferOther,BUFFER_SIZE); // reads the other file and sets the other buffer
            if(bufferOther == bufferAlpha == bufferNum){ // if other alpha and num are equal to eachother 
                write(copyFile,&bufferOther,BUFFER_SIZE); // then write the other buffer
            }else if(bufferOther == ' ' && bufferNum == ' ' && bufferAlpha == ' '){ // of other num and alpha are a space
                write(copyFile," ",BUFFER_SIZE); // then write a space
            }else if(bufferAlpha == '\n' && bufferNum == '\n' && bufferOther == '\n'){ // if alpha num and other are a new line
                write(copyFile,"\n",BUFFER_SIZE); // then write a new line
            }else if(bufferAlpha == bufferNum && bufferNum==' ' && bufferAlpha == ' '){ // if alpha and num are equal to eachother and num is a space and alpha is a space
                write(copyFile,&bufferOther,BUFFER_SIZE); // then write the other buffer
            }else if(bufferOther == bufferNum && bufferOther == ' ' && bufferNum == ' '){ // if other and num are equal to eachother and other is a space and num is a space
                write(copyFile,&bufferAlpha,BUFFER_SIZE); // then write the alpha buffer
            }else if(bufferAlpha == bufferOther && bufferAlpha == ' ' && bufferOther == ' '){ // if alpha and other are equal and alpha is a space
                write(copyFile,&bufferNum,BUFFER_SIZE); // then write in the number buffer
            }
            len--;
        }
        close(readFile);
        close(alphaFile);
        close(numFile);
        close(otherFile);
        close(copyFile);
        return 0;
}