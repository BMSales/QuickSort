#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void genArray(int** array, int n) {
	srand(time(0));
	(*array) = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		(*array)[i] = rand() % 100;
	}
}

void showArray(int* array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d ", array[i]);
	}
	printf("\n");
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

	Quick(array, start, greater - 1, start);
	Quick(array, greater + 1, pivot, greater + 1);
}

int main() {
	int n;
	int* array;
	scanf_s("%d", &n);
	genArray(&array, n);
	showArray(array, n);
	Quick(array, 0, n - 1, 0);
	showArray(array, n);
	free(array);
	return 0;
}