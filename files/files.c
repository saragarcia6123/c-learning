#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FIELD_LENGTH 255

int main() {
	FILE *fp;
	char filename[MAX_FILE_NAME];

	printf("Enter filename: ");
	scanf("%s", filename);

	printf("\nReading %s...\n", filename);

	fp = fopen(filename, "r");
	
	if (fp == NULL) {
		printf("File not found: %s\n", filename);	
		return -1;
	}

	char ch;
	int lines = 0;

	while((ch = fgetc(fp)) != EOF) {
		ch = fgetc(fp);
		if (ch == '\n') {
			lines++;
		}
	}
	rewind(fp);

	printf("Entries: %d\n", lines);

	if (lines == 0) {
		fclose(fp);
		return 0;
	}

	lines++;

	char (*names)[MAX_FIELD_LENGTH] = malloc(lines * sizeof(*names));
	int *ages = malloc(lines * sizeof(*ages));

	int row = 0;

	char name[MAX_FIELD_LENGTH];
	int age;

	while (fscanf(fp, "%[^,],%d\n", name, &age) == 2) {
		strcpy(names[row], name);
		ages[row] = age;
		row++;
	}

	fclose(fp);

	for (int i = 0; i < lines; i++) {
		printf("%s is %d\n", names[i], ages[i]);
	}
	
	return 0;
}
