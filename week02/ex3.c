#include <stdio.h>

int main(int argc, char *argv[]){

	int n = 0, i, j, count = 1, begin, end;
	sscanf(argv[1], "%d", &n);
	begin = n;
	end = n;
	for(i = 0; i < n; i++){
		for(j = 0; j <= (2 * n - 1); j++){
			if (j >= begin && j <= end){
				printf("*");
			} else{
				printf(" ");
			}
		}
		printf("\n");
		count += 2;
		begin--;
		end++;
	}
	return 0;
}
