#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

long sum(int *nums, int length) {
	long total = 0;
	for (int i = 0; i < length; i++) {
		total += nums[i];
	}
	return total;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Must pass in at least 1 argument!\n");
		return 1;
	}

	int nums[argc-1];
	long int curr;

	for (int i = 1; i < argc; i++) {

		char *endptr;
		curr = strtol(argv[i], &endptr, 10);

		if (endptr == argv[i] || *endptr != '\0') {
			printf("arg %d is not a valid number!\n", i);
			return 1;	
		}
		if (errno == ERANGE && (curr < INT_MIN || curr > INT_MAX)) {
			printf("arg &d integer overflow!\n", argv[i]);
			return 1;
		}

		nums[i-1] = curr;	
	}
	
	long result = sum(nums, sizeof(nums) / sizeof(nums[0]));

	printf("Total: %ld\n", result);

	return 0;
}
