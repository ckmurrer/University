#include <stdio.h> 
#include <stdlib.h> 
int st_to_int(char *input){ 
    int number = 0; 
    int position = 0; 
    while(input[position] != '\0'){ 
        number = (10 * number) + (input[position] - '0'); 
        position++; 
    } 
    return number; 
} 

int main(int argc, char* argv[]){ 
    if(argc < 2){ 
        printf("Error not enough integer arguments");
        exit(1); 
    }else{ 
        int oddSum = 0; 
        int temp = 0;
        for(int i = 1; i < argc; i++){ 
            temp = st_to_int(argv[i]); 
            if(temp%2!=0){ 
                oddSum+=temp; 
            } 
        }
        printf("The sum of odd mnumbers is %d\n",oddSum); 
    } 
exit(0); 
}