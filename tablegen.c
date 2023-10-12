// main function and basic GUI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "generate.h"
#include "io.h"
#include "sort.h"
#include "tablegen.h"

int main(int argc, char** argv) {
	// TODO: add a while loop for the menu

	// main menu
	int selection;
	printf("TableGen Menu\n");
	printf("-------------\n");
	printf("1. Generate new table\n");
	printf("2. Exit\n");
	printf("\n");
	printf("Selection: ");
	scanf("%d", &selection);

	system("clear");

	switch (selection) {
	case 1:
		char* columnsSelection = columnsPrompt();
		int rowSelection = rowsPrompt();
		char* fileSelection = filePrompt();

		printf("\nSummary of properties:\n");
		printf(" Columns: %s\n", columnsSelection);
		printf(" Row count: %d\n", rowSelection);
		printf(" File name: %s\n", fileSelection);

		// TODO: Write file.csv

		// int n = 10;
		// char** strings = readFile(n, "./first_names.txt");
		// printf("First Names:\n");
		// for (int i = 0; i < n; i++) {
		// 	printf("\t%s\n", strings[i]);
		// }
		break;
	case 2:
		printf("Goodbye and thanks for using TableGen.\n");
		break;
	default:
		printf("Invalid selection.\n");
		break;
	}

	return EXIT_SUCCESS;
}

// prompts the user for a list of columns
// returns the user input as a string
// expected format: "1,2,3,4"
char* columnsPrompt() {
	// display menu
	printf("Column Options\n");
	printf("--------------\n");
	printf("1. User ID");
	printf("\t\t5. Phone number\n");
	printf("2. First name");
	printf("\t\t6. Email address\n");
	printf("3. Last name");
	printf("\t\t7. SIN\n");
	printf("4. Country");
	printf("\t\t8. Password\n");
	printf("\nEnter column list (comma-separated, no spaces): ");

	// temporary storage
	char string[16];
	scanf("%s", string);

	// allocate memory
	char* columns = (char*)malloc(strlen(string) * sizeof(char));
	if (columns == NULL) {
		printf("Could not allocate memory for columns input.\n");
		printf("Program terminating.\n");
		exit(0);
	}

	// copying string from buffer
	columns = strdup(string);

	return columns;
}

// prompts the user for a number of rows
// returns the user input as an integer
int rowsPrompt() {
	int rows;
	printf("Enter row count (1 < n < 1M): ");
	scanf("%d", &rows);

	return rows;
}

// prompts the user for a file name
// returns the user input as a string
char* filePrompt() {
	printf("Enter output file name (no suffix): ");
	char string[16];
	scanf("%s", string);

	// allocate memory
	char* file = (char*)malloc(strlen(string) * sizeof(char));
	if (file == NULL) {
		printf("Could not allocate memory for file name.\n");
		printf("Program terminating.\n");
		exit(0);
	}

	// copying string from buffer
	file = strdup(string);

	return file;
}