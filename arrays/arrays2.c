#include <stdio.h>
#include <stdlib.h>

int vowels[5] = {'a', 'e', 'i', 'o', 'u'};

// Nothing practical, just playing around with syntax
int main(void) {
	int rows = 2, cols = 5, i, j;

	char **arrptr = malloc(2 * sizeof(char *));

	char currchar;	
	for (i = 0; i < rows; i++) {
		arrptr[i] = malloc(cols * sizeof(char));
		for (j = 0; j < cols; j++) {
			currchar = vowels[j];
			if (i == 1) {
				currchar ^= 0x20;
			}
			arrptr[i][j] = currchar; 
		}
	}
	
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++)  {
			printf("%c ", arrptr[i][j]);
		}
		printf("\n");
	}

	free(arrptr);

	return 0;
}
