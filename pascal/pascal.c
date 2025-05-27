#include <stdio.h>
#include <stdlib.h>

// ie 5+4+3+2+1=15
int decumsum(int n) {
	int result = n;
	for (int curr = n; curr > 0; --curr) {
		result += curr;
	}
	return result;
}

int factorial(int n) {
	int result = n;
	for (int curr = n-1; curr > 0; curr--) {
		result *= curr;
	}
	return result;
}

int ncr(int n, int r) {
	if ((n-r) == 0 || n == 0 || r == 0) {
		return 1;
	}
	int result = factorial(n) / (factorial(r) * factorial(n-r));
	return result;
}

int main(void) {
	int nrows, i, j;
	printf("Enter number of rows: ");
	scanf("%d", &nrows);
	
	int nums = decumsum(nrows);
	char *tri = malloc(nums * sizeof(int));

	for (i = 0; i < nrows; i++)	{
		for (j = 0; j <= i; j++) {
			tri[j + decumsum(i)] = ncr(i, j);
		}
	}

	for (i = 0; i < nrows; i++) {
		for (j = 0; j <= i; j++) {
			printf("%d ", tri[j + decumsum(i)]);
		}
		printf("\n");
	}

	free(tri);

	return 0;
}
