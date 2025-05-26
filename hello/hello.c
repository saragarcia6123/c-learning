#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// usage: ./hello.sh rick 42
int main(int argc, char **argv) {
 
	char *name;
	int age;
		
	if (argc != 3) {
		printf("You must pass in exactly 2 arguments!");
		return 0;
	}

	if(sscanf(argv[2], "%i", &age) != 1) {
		fprintf(stderr, "Second argument must be an integer\n");
		return 0;
	}

	name = malloc(strlen(argv[1]) * sizeof(char));
	strcpy(name, argv[1]);
	
	printf("%s is %d chars long.\n", name, strlen(name));
	bool isJohn = strncmp(name, "john", 4);

	if (isJohn == 0) {
		printf("Hello %s!\n", name);
	}

	else {
		printf("You are not john, %s!\n", name);
	}

	return 0;
}
