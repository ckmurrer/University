#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1
int main(){
    umask(0);
// the different paths needed     
    char *path1 = "/home/cmurrer/Dir1";
    char *path2 = "/home/cmurrer/Dir2";
    char *path21 = "/home/cmurrer/Dir2/Dir21";
    char buffer[BUFFER_SIZE];
    int temp;
// creates all three directories needed
    if(mkdir(path1,0777)<0){
        printf("Directory Error: unable to make directory or it already exist\n");
    }
    if(mkdir(path2,0777)<0){
        printf("Directory Error: unable to make directory or it already exist\n");
    }
    if(mkdir(path21,0777)<0){
        printf("Directory Error: unable to make directory or it already exist\n");
    }
// opens the hello executable file in the home directory
    int readFile = open("/home/cmurrer/hello",O_RDONLY);
    if(readFile == -1){
        printf("File Error: unable to open file\n");
        return 1;
    }
// creates a hello file in the Dir21 directory with the sale permissions as hello in the home directory    
    int writeFile = open("/home/cmurrer/Dir2/Dir21/hello",O_WRONLY|O_CREAT,S_IRWXU|S_IRWXG|S_IROTH|S_IWOTH);
    if(writeFile == -1){
        printf("File Error: unable to open or create file\n");
        close(readFile);
        return 1;
    }
// copies /home/cmurrer/hello into /home/cmurrer/Dir2/Dir21/hello
    while ((temp=read(readFile, buffer,1) == 1)){
        write(writeFile,buffer,temp);   
    }
    close(readFile);
    close(writeFile);

    if(symlink("/home/cmurrer/Dir2/Dir21","/home/cmurrer/Dir1/toDir21")<0){
        printf("Symbolic Link Error: unable to create link");
    }
    if(symlink("/home/cmurrer/Dir2/Dir21/hello","/home/cmurrer/Dir1/toHello")<0){
        printf("Symbolic Link Error: unable to create link");
    }
    return 0;
}