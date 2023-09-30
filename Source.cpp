#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void genArray(int** array, int n) {
	srand(time(0));
	(*array) = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		(*array)[i] = rand() % 1000;
	}
}
void showArray(int* array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d ", array[i]);
	}
	printf("\n");
}

void firstQuick(int* array, int n) {
	int index = 0;
	int pivot = n - 1;
	int change;

	for (int i = 0; i < pivot; i++) {
		if (array[pivot] >= array[i]) {
			change = array[i];
			array[i] = array[index];
			array[index] = change;
			index++;
		}
	}
	change = array[pivot];
	array[pivot] = array[index];
	array[index] = change;
}

int main() {
	int n;
	int* array;
	scanf_s("%d", &n);
	genArray(&array, n);
	showArray(array, n);
	firstQuick(array, n);
	showArray(array, n);
	return 0;
}