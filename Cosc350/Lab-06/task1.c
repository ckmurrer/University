#include <stdlib.h>
#include <stdio.h>

extern char **environ; 

char *mygetenv(char *name){
    int i = 0 ,j = 0;
    while(environ[i] != NULL){
        while(environ[i][j] != NULL){
            if(environ[i][j] == '=' && name[j] == NULL){              
                return environ[i];
            }
            j++;
        }
        i++;
        j = 0;
    }
    return 0;
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Argument Error: Too many or too little arguments passed\n");
        return 1;
    }

    char *envTest = mygetenv(argv[1]);
    if(envTest == NULL){
        printf("mygetenv(): %s=(null)\n",argv[1]);
    }else{
        printf("mygetenv(): %s\n",envTest);
    }
    return 0;
}