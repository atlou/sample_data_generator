// any code used to read input files
// or write the final table

// int *buffer = (int *)malloc(10 * sizeof(int));
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

// reads a text file and returns an array of string
// expects one string per line
// expects to read exactly n number of lines
char** readFile(int n, char filePath[]) {
    printf("Attempting to read file: %s\n", filePath);

    // opening the file in read mode
    FILE* fptr = fopen(filePath, "r");
    if (fptr == NULL) {
        printf("Could not open the file: %s\n", filePath);
        printf("Program terminating.\n");
        exit(0);
    }

    // array of strings
    char** strings;
    // temporary storage
    char buffer[64];

    // allocating memory for n number of strings
    strings = (char**)malloc(n * sizeof(char*));
    if (strings == NULL) {
        printf("Could not allocate memory for main array.\n");
        printf("Program terminating.\n");
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        // read line
        fgets(buffer, sizeof(buffer), fptr);

        // allocate memory for the string
        // memory needed = string length - new line char + terminating char
        size_t len = strlen(buffer);
        strings[i] = (char*)malloc(len * sizeof(char));
        if (strings[i] == NULL) {
            printf("Could not allocate memory for string at index %d.\n", i);
            printf("Program terminating.\n");
            exit(0);
        }

        // copying string from buffer
        strings[i] = strndup(buffer, len - 1);
    }

    return strings;
}

void writeTable(char** rows, char filePath[]) {}