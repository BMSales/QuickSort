#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Function.hpp"
	
int main() {
	int size, type;
	printf("Determine the size of the array (1 - 200):\n");
	while (1) {
		scanf_s("%d", &size);
		if (size < 1 || size > 200) {
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
	Array_Generate(&array, size);
	Array_Show(array, size);
	if (type == 1) {
		Quick_Sort_First(array, 0, size - 1, size);
	}
	else if (type == 2) {
		Quick_Sort_Last(array, 0, size - 1, size);
	}
	else {
		Quick_Sort_Random(array, 0, size - 1, size);
	}
	Array_Show(array, size);
	free(array);
	return 0;
}