#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int * array, int size){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size - i; j++){
			if(array[j] > array[j + 1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void print_array(int * array, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
 printf("Please enter the number of elements of array: ");
 int size, i;
 scanf("%d", &size);
 printf("Please enter elements of an array via space: ");
 int * array = (int *) malloc(size);
 for(i = 0; i < size; i++){
 	scanf("%d", &array[i]);
 }
 bubble_sort(array, size);
 printf("Sorted array: ");
 print_array(array, size);
 free(array);
 return 0;
}
