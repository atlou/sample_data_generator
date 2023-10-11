// main function and basic GUI

#include <stdio.h>
#include <stdlib.h>

#include "generate.h"
#include "io.h"
#include "sort.h"
#include "tablegen.h"

int main(int argc, char **argv)
{
	// Main Menu
	int selection;
	printf("TableGen Menu\n");
	printf("-------------\n");
	printf("1. Generate new table\n");
	printf("2. Exit\n");
	printf("\n");
	printf("Selection: ");
	scanf("%d", &selection);

	system("clear");

	switch (selection)
	{
	case 1:
		/* code */
		printf("Generating a new table.\n");
		break;
	case 2:
		/* code */
		printf("Goodbye and thanks for using TableGen\n");
		break;
	default:
		printf("Invalid selection.\n");
		break;
	}

	return EXIT_SUCCESS;
}
