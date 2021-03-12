#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1
// converts from string to int
int str_to_int(char *input){ 
    int number = 0; 
    int position = 0; 
    while(input[position] != '\0'){ 
        number = (10 * number) + (input[position] - '0'); 
        position++; 
    } 
    return number; 
} 
// converts from int to char
int int_to_char(char* str,int input){
    sprintf(str,"%d",input);
    return (strlen(str));
}
// checks if the passed variable is a number
int check_if_number(char input){
    int number = (int) input;
    if(input >= (int)'0' && input <= (int)'9'){
        return number;
    }
    return 0;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf(" too many arguments passed");
        return 1;
    }
// opens file passed through arugments and checks if it exists    
    int readFile = open(argv[1], O_RDONLY);
    if(readFile == -1){
        printf("File Error: cannot open file");
        return 1;
    }

    int writeFile = open("bar",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

    char buffer[BUFFER_SIZE];
    char input[80];
    int temp;
    int pos = 0;

    while((temp=read(readFile,buffer,BUFFER_SIZE)>0)){
        if(check_if_number(buffer[0])){
            input[pos] = buffer[0];
            pos++;
        } 
    }

    int output = str_to_int(input);

    output += 10;

    char newInput[pos];

    int_to_char(newInput, output);
    write(writeFile,newInput,pos);

    close(readFile);
    return 1;
}