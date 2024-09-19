#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int *a, int *b){
	int swapper;
	swapper = *a;
	*a = *b;
	*b = swapper;
}

void Array_Create(int **array, int size){
	(*array) = (int*)malloc(size * sizeof(int));
}

void Array_Fill_Random(int *array, int size){
	for(int i = 0; i < size; i++){
		array[i] = rand() % 501;
	}
}

void Array_Print(int *array, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}

	printf("\n\n");
}

void Quicksort(int *array, int start, int end){
	if(end - start < 1){
		return;
	}

	int pivot = end;
	int swap_marker = start - 1;

	for(int i = start; i <= end; i++){
		if(array[i] > array[pivot]){
			continue;
		}
		else{
			swap_marker++;
			if(i > swap_marker){
				Swap(&array[i], &array[swap_marker]);
			}
		}
	}

	Quicksort(array, start, swap_marker - 1);
	Quicksort(array, swap_marker + 1, end);
}

void main(){
	srand(clock());
	int *array = NULL;
	int size = 100;
  
	Array_Create(&array, size);
	Array_Fill_Random(array, size);

	Array_Print(array, size);

	Quicksort(array, 0, size - 1);
	Array_Print(array, size);
}
