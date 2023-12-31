// main function and basic GUI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generate.h"
#include "io.h"
#include "sort.h"
#include "tablegen.h"

// global variables
char** firstNames;
char** lastNames;
char** countries;
char** emailSuffixes;

int main(int argc, char** argv) {
	// initialize random number generator  with current time
	time_t t;
	srand((unsigned)time(&t));

	// initialize global variables
	firstNames = readFile(FIRST_NAMES_COUNT, FIRST_NAMES_FILE);
	lastNames = readFile(LAST_NAMES_COUNT, LAST_NAMES_FILE);
	countries = readFile(COUNTRIES_COUNT, COUNTRIES_FILE);
	emailSuffixes = readFile(EMAIL_SUFFIXES_COUNT, EMAIL_SUFFIXES_FILE);

	int selection;

	do {
		// main menu
		system("clear");
		printf("TableGen Menu\n");
		printf("-------------\n");
		printf("1. Generate new table\n");
		printf("2. Exit\n");
		printf("\n");
		printf("Selection: ");
		scanf("%d", &selection);
		system("clear");

		if (selection == 1) {
			char* columnsSelection = columnsPrompt();
			int rowSelection = rowsPrompt();
			char* fileSelection = filePrompt();

			printf("\nSummary of properties:\n");
			printf(" Columns: %s\n", columnsSelection);
			printf(" Row count: %d\n", rowSelection);
			printf(" File name: %s\n\n", fileSelection);

			// generate users
			struct user* users = generateUsers(columnsSelection, rowSelection);
			// sort users
			sortUsers(users, rowSelection, columnsSelection[0]);

			// write file
			writeTable(rowSelection, users, columnsSelection, fileSelection);
			printf("Table written successfully to %s.csv\n", fileSelection);

			// free users
			for (int i = 0; i < rowSelection; i++) {
				freeUser(&users[i]);
			}
			free(users);

			// free selections
			free(columnsSelection);
			free(fileSelection);

			// continue
			char proceed;
			printf("\nPress 'c' or 'C' to continue ");
			do {
				scanf("%c", &proceed);
			} while ((proceed != 'c') && (proceed != 'C'));
		} else if (selection != 2) {
			printf("Invalid selection\n");
			break;
		}
	} while (selection != 2);

	freeStrings(firstNames, FIRST_NAMES_COUNT);
	freeStrings(lastNames, LAST_NAMES_COUNT);
	freeStrings(countries, COUNTRIES_COUNT);
	freeStrings(emailSuffixes, EMAIL_SUFFIXES_COUNT);

	printf("Goodbye and thanks for using TableGen.\n");
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
	char* columns = strdup(string);

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
	char* file = strdup(string);

	return file;
}