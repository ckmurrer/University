#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    FILE *filePointer;
    char* input;
    char buffer[BUFSIZ];
    input = malloc((argc-1)*sizeof(char));

    for(int i=1; i<argc; i++ ){
        sprintf(input, "%s %s", input, argv[i]);
    }

    if((filePointer=popen(input,"r")) != NULL){
        while(fgets(buffer,BUFSIZ,filePointer)!= NULL){
            (void)printf("%s",buffer);
        }
    }
    pclose(filePointer);
    printf("\n");
    return 0;
}