// any code used to read input files
// or write the final table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablegen.h"
#include "generate.h"
#include "io.h"

void freeStrings(char** strings, int n) {
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
}

// reads a text file and returns an array of string
// expects one string per line
// expects to read exactly n number of lines
char** readFile(int n, char filePath[]) {
    // opening the file in read mode
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
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
        fgets(buffer, sizeof(buffer), file);

        // allocate memory for the string
        // memory needed = string length - new line char + terminating char
        size_t len = strlen(buffer);

        // copying string from buffer
        strings[i] = strndup(buffer, len - 1);
    }

    fclose(file);

    return strings;
}

void writeRow(struct user user, const char* columns, FILE* file) {
    int first = 1;
    char buffer[strlen(columns) + 1]; // +1 for the null terminator
    strcpy(buffer, columns);
    char* token;

    // get the first token
    token = strtok(buffer, ",");

    // walk through other tokens
    while (token != NULL) {
        // add comma if it's not the first token
        if (first == 0) {
            fputs(",", file);
        }
        switch (token[0]) {
        case '1': {
            // convert int to string
            char id[16];
            sprintf(id, "%d", user.userID);
            fputs(id, file);
            break;
        }
        case '2':
            fputs(user.firstName, file);
            break;
        case '3':
            fputs(user.lastName, file);
            break;
        case '4':
            fputs(user.country, file);
            break;
        case '5':
            fputs(user.phoneNumber, file);
            break;
        case '6':
            fputs(user.emailAddress, file);
            break;
        case '7':
            fputs(user.sin, file);
            break;
        case '8':
            fputs(user.password, file);
            break;
        default:
            printf("Invalid column number: %c\n", token[0]);
            break;
        }
        token = strtok(NULL, ",");  // get the next token
        first = 0;
    }
    fputs("\n", file); // break line
}

void writeHeader(const char* columns, FILE* file) {
    int first = 1;
    char buffer[strlen(columns) + 1]; // +1 for the null terminator
    strcpy(buffer, columns);
    char* token;

    // get the first token
    token = strtok(buffer, ",");

    // walk through other tokens
    while (token != NULL) {
        // add comma if it's not the first token
        if (first == 0) {
            fputs(",", file);
        }
        switch (token[0]) {
        case '1': fputs("User ID", file);
            break;
        case '2': fputs("First Name", file);
            break;
        case '3': fputs("Last Name", file);
            break;
        case '4': fputs("Country", file);
            break;
        case '5': fputs("Phone", file);
            break;
        case '6': fputs("Email", file);
            break;
        case '7': fputs("SIN", file);
            break;
        case '8': fputs("Password", file);
            break;
        default:
            printf("Invalid column number: %c\n", token[0]);
            break;
        }
        token = strtok(NULL, ",");  // Get the next token
        first = 0;
    }
    fputs("\n", file); // break line
}

void writeTable(int n, struct user* users, char* columns, char* fileName) {
    // adding .csv to file name
    int len = strlen(fileName) + 7; // "./" + file name + ".csv" + terminating char
    char filePath[len];
    filePath[0] = '\0'; // adding terminating char for strcat 
    strcat(filePath, "./");
    strcat(filePath, fileName);
    strcat(filePath, ".csv");

    // opening the file in write mode
    FILE* file = fopen(filePath, "wt");
    if (file == NULL) {
        printf("Could not create the file: %s\n", filePath);
        printf("Program terminating.\n");
        exit(0);
    }

    // write header
    writeHeader(columns, file);

    // write entries
    for (int i = 0; i < n; i++) {
        writeRow(users[i], columns, file);
    }

    fclose(file);
}
