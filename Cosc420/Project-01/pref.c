#include<stdio.h>
int main(){

	char test[]="0000HOWDY";
	int i;
	
	for(i=0; i< 9999 ; i++){
	if(i<10){	
		printf("%s\n",(test)+1);
		test[3]++;
	}		
	}

	return 0;
}

