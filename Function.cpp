#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Swap(int* array, int a, int b) {
	int change;
	change = array[a];
	array[a] = array[b];
	array[b] = change;
}

void Array_Generate(int** array, int size) {
	srand(time(0));
	(*array) = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		(*array)[i] = rand() % 100;
	}
}

void Array_Show(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%2d ", array[i]);
	}
	printf("\n\n");
}

void Quick_Sort_Random_Pivot(int* array, int start, int last) {
	srand(time(0));
	int pivot;
	pivot = start + (rand() % (start - last));
	Swap(array, start, pivot);
}

int Quick_Sort_First(int* array, int start, int last, int size) {
	if (start >= last) {
		return 0;
	}
	int pivot = start;
	int lesser = last;
	for (int i = last; i > start; i--) {
		if (array[pivot] <= array[i]) {
			Swap(array, i, lesser);
			lesser--;
		}
	}
	Swap(array, pivot, lesser);
	printf("Pivot: %d\nMoved to: %d\n\n", array[lesser], lesser);
	Array_Show(array, size);
	Quick_Sort_First(array, start, lesser - 1, size);
	Quick_Sort_First(array, lesser + 1, last, size);
}

int Quick_Sort_Last(int* array, int start, int last, int size) {
	if (start >= last) {
		return 0;
	}
	int pivot = last;
	int greater = start;
	for (int i = start; i < last; i++) {
		if (array[pivot] >= array[i]) {
			Swap(array, i, greater);
			greater++;
		}
	}
	Swap(array, pivot, greater);
	printf("Pivot: %d\nMoved to: %d\n\n", array[greater], greater);
	Array_Show(array, size);
	Quick_Sort_Last(array, start, greater - 1, size);
	Quick_Sort_Last(array, greater + 1, last, size);
}


int Quick_Sort_Random(int* array, int start, int last, int size) {
	if (start >= last) {
		return 0;
	}
	Quick_Sort_Random_Pivot(array, start, last);
	int pivot = start;
	int lesser = last;
	for (int i = last; i > start; i--) {
		if (array[pivot] <= array[i]) {
			Swap(array, i, lesser);
			lesser--;
		}
	}
	Swap(array, pivot, lesser);
	printf("Pivot: %d\nMoved to: %d\n\n", array[lesser], lesser);
	Array_Show(array, size);
	Quick_Sort_Random(array, start, lesser - 1, size);
	Quick_Sort_Random(array, lesser + 1, last, size);
}