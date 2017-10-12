#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){

	printf("Enter 2 integers via space: \n");
	int i, j;
	scanf("%d", &i);
	scanf("%d", &j);
	swap(&i, &j);
	printf("Swapped integers: %d, %d\n", i, j);

	return 0;
}
