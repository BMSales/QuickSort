#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Function.hpp"
	
int main() {
	int size, type;
	printf("Determine the size of the array (1 - 1000):\n");
	while (1) {
		scanf_s("%d", &size);
		if (size < 1 || size > 100) {
			printf("Invalid input\n");
		}
		else {
			break;
		}
	}
	printf("Choose the pivot: First Element(1), Last Element(2), Random Element(3)\n");
	while (1) {
		scanf_s("%d", &type);
		if (type < 1 || type > 3) {
			printf("Invalid input\n");
		}
		else {
			break;
		}
	}
	int* array;
	GenArray(&array, size);
	ShowArray(array, size);
	if (type == 1) {
		FirstQuick(array, 0, size - 1, size);
	}
	else if (type == 2) {
		LastQuick(array, 0, size - 1, size);
	}
	else {
		RandQuick(array, 0, size - 1, size);
	}
	ShowArray(array, size);
	free(array);
	return 0;
}