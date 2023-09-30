#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size;
void genArray(int** array, int size) {
	srand(time(0));
	(*array) = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		(*array)[i] = rand() % 100;
	}
}

void showArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%2d ", array[i]);
	}
	printf("\n\n");
}

int Quick(int* array, int start, int pivot, int greater) {
	if (pivot <= start) {
		return 0;
	}
	int change;
	for (int i = start; i < pivot; i++) {
		if (array[pivot] >= array[i]) {
			change = array[i];
			array[i] = array[greater];
			array[greater] = change;
			greater++;
		}
	}
	change = array[pivot];
	array[pivot] = array[greater];
	array[greater] = change;
	printf("Pivot: %d\nMoved to: %d\n", array[greater], greater);
	showArray(array, size);
	Quick(array, start, greater - 1, start);
	Quick(array, greater + 1, pivot, greater + 1);
}

int main() {
	int* array;
	scanf_s("%d", &size);
	genArray(&array, size);
	showArray(array, size);
	Quick(array, 0, size - 1, 0);
	showArray(array, size);
	free(array);
	return 0;
}