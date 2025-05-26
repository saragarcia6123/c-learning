#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *name;
	unsigned int age;
} user;

user createUser(char * name, int age) {
	user newUser;

	newUser.name = malloc(strlen(name)*sizeof(char));
	strcpy(newUser.name, name);

	newUser.age = age;

	return newUser;	
}

int main(int argc, char **argv) {

	char *name;
	int age;

	if (argc != 3) {
		printf("Must pass exactly 2 arguments");
		return 0;
	}	

	if (sscanf (argv[2], "%i", &age) != 1) {
		fprintf(stderr, "Second argument must be an integer\n");	
		return 0;
	}

	name = malloc(strlen(argv[1]) * sizeof(char));
	strcpy(name, argv[1]);

	user newUser = createUser(name, age);
	printf("%s,%d", newUser.name, newUser.age);

	return 0;
}
