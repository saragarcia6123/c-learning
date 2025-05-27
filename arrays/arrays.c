#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

int main(void) {

	int cells = 100;

	int *ptr = malloc(cells * sizeof(int));

	for (int i = 0; i < cells; i++) {
		ptr[i] = i + 1;
	}

	int curr;
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			curr = i * GRID_SIZE + j;
			if (curr < 9) {
				printf(" ");
			}
			printf("%d ", ptr[curr]);
		}
		printf("\n");
	}
	
	return 0;
}
