#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Switch(int* array, int a, int b) {
	int change;
	change = array[a];
	array[a] = array[b];
	array[b] = change;
}

void GenArray(int** array, int size) {
	srand(time(0));
	(*array) = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		(*array)[i] = rand() % 100;
	}
}

void ShowArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%2d ", array[i]);
	}
	printf("\n\n");
}

void RandPivot(int* array, int start, int last) {
	srand(time(0));
	int pivot;
	pivot = start + (rand() % (start - last));
	Switch(array, start, pivot);
}

int FirstQuick(int* array, int start, int last, int size) {
	if (start >= last) {
		return 0;
	}
	int pivot = start;
	int lesser = last;
	for (int i = last; i > start; i--) {
		if (array[pivot] <= array[i]) {
			Switch(array, i, lesser);
			lesser--;
		}
	}
	Switch(array, pivot, lesser);
	printf("Pivot: %d\nMoved to: %d\n\n", array[lesser], lesser);
	ShowArray(array, size);
	FirstQuick(array, start, lesser - 1, size);
	FirstQuick(array, lesser + 1, last, size);
}

int LastQuick(int* array, int start, int last, int size) {
	if (start >= last) {
		return 0;
	}
	int pivot = last;
	int greater = start;
	for (int i = start; i < last; i++) {
		if (array[pivot] >= array[i]) {
			Switch(array, i, greater);
			greater++;
		}
	}
	Switch(array, pivot, greater);
	printf("Pivot: %d\nMoved to: %d\n\n", array[greater], greater);
	ShowArray(array, size);
	LastQuick(array, start, greater - 1, size);
	LastQuick(array, greater + 1, last, size);
}


int RandQuick(int* array, int start, int last, int size) {
	if (start >= last) {
		return 0;
	}
	RandPivot(array, start, last);
	int pivot = start;
	int lesser = last;
	for (int i = last; i > start; i--) {
		if (array[pivot] <= array[i]) {
			Switch(array, i, lesser);
			lesser--;
		}
	}
	Switch(array, pivot, lesser);
	printf("Pivot: %d\nMoved to: %d\n\n", array[lesser], lesser);
	ShowArray(array, size);
	RandQuick(array, start, lesser - 1, size);
	RandQuick(array, lesser + 1, last, size);
}