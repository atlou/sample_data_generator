// any code used to read input files
// or write the final table

// int *buffer = (int *)malloc(10 * sizeof(int));
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readFile(int n, char filePath[])
{
    printf("Attempting to read file: %s\n", filePath);

    // opening the file in read mode
    FILE *fptr = fopen(filePath, "r");
    if (fptr == NULL)
    {
        // error handling, possibly abort
        printf("Could not open the file: %s\n", filePath);
        printf("Program terminating.\n");
        exit(0);
    }

    char **strings;
    char buffer[64];

    strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL)
    {
        // error handling, possibly abort
        printf("Could not allocate main array.\n");
        printf("Program terminating.\n");
        exit(0);
    }
}