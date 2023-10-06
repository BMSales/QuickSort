#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Function.hpp"
	
int main() {
	int size, type;
	printf("Determine the size of the array (1 - 2000):\n");
	while (1) {
		scanf_s("%d", &size);
		if (size < 1 || size > 2000) {
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
	Array_Populate(&array, size);
	Array_Show(array, size);
	if (type == 1) {
		Quicksort_First(array, 0, size - 1, size);
	}
	else if (type == 2) {
		Quicksort_Last(array, 0, size - 1, size);
	}
	else {
		Quicksort_Random(array, 0, size - 1, size);
	}
	Array_Show(array, size);
	free(array);
	return 0;
}