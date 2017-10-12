#include <stdio.h>
#include <stdlib.h>

int main(){

	char input[500];
	while(fgets(input, sizeof(input), stdin)){
		if(strncmp(input, "exit", 4) == 0){
			break;
		}
		system(input);
		fflush(stdin);
	}

	return 0;
}
