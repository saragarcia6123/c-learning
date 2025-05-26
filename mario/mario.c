#include<stdio.h>

void make_stairs(int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num-i-1; j > 0; --j) {
			printf(" ");
		}
		for (int j = 0; j < i+1; j++) {
			printf("#");
		}
		printf("\n");
	}
}

int main() {
	// ask for a number
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	make_stairs(num);
	return 0;
}


