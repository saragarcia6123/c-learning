#include <stdio.h>
#include <stdlib.h>

# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX_LENGTH 255

typedef struct {
	char *name;
	int age;
} person;

void birthday(person *p) {
	p->age++;
}

int main(int argc, char **argv) {

	if (argc != 3) {
		printf("You must specify 2 arguments.\n");
		return 1;
	}

	int age;

	if (sscanf (argv[2], "%i", &age) != 1) {
		fprintf(stderr, "Arg 2 must be an integer\n");
		return 1;
	}

	char *name;
	name = malloc(MIN(*argv[1], MAX_LENGTH)*sizeof(int));

	sscanf(argv[1], "%[a-zA-Z] ", name);

	person *myPerson;
	myPerson = (person *) malloc(sizeof(person));

	myPerson->name = name;
	myPerson->age = age;

	printf("%s is %d\n", myPerson->name, myPerson->age);

	free(name);
	free(myPerson);

	return 0;
}
