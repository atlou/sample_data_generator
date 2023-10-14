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


	// TODO: add a while loop for the menu

	// main menu
	system("clear");

	printf("TableGen Menu\n");
	printf("-------------\n");
	printf("1. Generate new table\n");
	printf("2. Exit\n");
	printf("\n");
	printf("Selection: ");

	int selection;
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

		// TEST: generate Users
		struct user* users = generateUsers(columnsSelection, rowSelection);

		// TEST: sort users
		sortUsers(users, rowSelection, columnsSelection[0]);

		for (int i = 0; i < rowSelection; i++) {
			printf("User %d:\n", i);
			printf(" First name: %s\n", users[i].firstName);
			printf(" Last name: %s\n", users[i].lastName);
			printf(" User ID: %d\n", users[i].userID);
		}


		// TEST: generate users
		// for (int i = 0; i < rowSelection; i++) {
		// 	char* fname = generateFirstName();
		// 	char* lname = generateLastName();
		// 	printf("User %d:\n", i);
		// 	printf(" Name: %s %s\n", fname, lname);
		// 	printf(" Phone: %s\n", generatePhoneNumber());
		// 	printf(" Email: %s\n", generateEmailAddress(fname, lname));
		// }



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