#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int i, j;
	// print arguments
	printf("Arguments of program that runs in background: ");
	for(i = 0; i < argc; i++){
		printf("%s ", argv[i]);
	}	
	printf("\n");
	// sleep a little bit
	sleep(10);
	printf("Program test ended its work\n");

	return 0;
}