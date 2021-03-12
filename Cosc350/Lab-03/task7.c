#include <stdio.h>
#include <stdlib.h>

int str_to_ascii_to_int(char* input){
    int trans = 0; 
    int pos = 0;
// checks to see if there is a char in the input stream
// that can be translated into ascii
    while(input[pos] != '\0'){
       trans = (10 * trans) + (input[pos]-'0');
       pos++;
    }
    return trans;
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Error missing integer argument\n");
        exit(1);
    }else{
        int sum= 0;
        for(int i=1;i<argc;i++){
            sum+=str_to_ascii_to_int(argv[i]);
        }
        printf("the sum is: %d\n",sum);
    }
    return 0;
    exit(0);
}