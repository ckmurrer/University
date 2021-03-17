#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int char_to_int(char *input){ 
    int number = 0; 
    int position = 0; 
    while(input[position] != '\0'){ 
        number = (10 * number) + (input[position] - '0'); 
        position++; 
    } 
    return number; 
} 

int main(int argc, char* argv[])
{
    char *message = argv[1];
	int Nc = char_to_int(argv[2]);
	int Tc = char_to_int(argv[3]);

	for(; Nc > 0; Nc--)
    {
        printf("%s PID: %d\n",message, getpid());
        sleep(Tc);
    }
	exit(37);
}