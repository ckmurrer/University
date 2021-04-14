#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLINE 256
void err_sys(char *);
int main(void){
    char line[MAXLINE];
    FILE *fpin;
    int arg1,arg2,temp;
    if ( (fpin = popen("./anyinput", "r")) == NULL)
        err_sys("popen error");

    for ( ; ; ){
        printf("Enter Two Integers: ");
        fflush(stdout);

        if (fgets(line, MAXLINE, fpin) == NULL) /* read from pipe */
            break;
        if(sscanf(line,"%d%d",&arg1,&arg2)==2){
            if (fputs(line, stdout) == EOF) /* write to stdout */
                err_sys("fputs error to pipe");
            printf("The product is: %d\n",(arg1*arg2));
        }
    }

    if (pclose(fpin) == -1)
        err_sys("pclose error");

    putchar('\n');
    exit(0);
}
void err_sys(char *s)
{
printf ("%s \n", s);
exit (1);
}