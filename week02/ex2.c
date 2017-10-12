#include <stdio.h>
#include <string.h>

int main(){

	char str[1000];
	printf("Enter string: \n");
	fgets(str, 100, stdin);
	int i;
	printf("Reversed string: ");
	for(i = strlen(str) - 1; i >= 0; i--){
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}
