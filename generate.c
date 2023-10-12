// the code used to generate data
// for the various rows/columns

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "generate.h"

// takes a list of columns and a number of rows
// and generates a table
// returns an array of strings where 
// each string represents a row
char** generateTable(char* columns, int rowCount) {
    for (int i = 0; i < rowCount; i++) {

    }
}
// generate column
// switch(column):
    // case '2'
        // for each rowcount
            // generateFirstName()
    // ...

// concat columns
// table = column1
// for each column
    // for each row
        // concact (table's row) (,) (column's row)

// takes a list of columns and generates 
// a single row for that selection
// returns that row as a string
char* generateRow(char* columns, int rowIndex) {
    // concat fields
}

char* generateField(char column, int rowIndex) {
    switch (column) {
    case '1':
        return generateUserID(rowIndex);
        break;
    case '2':
        return generateFirstName();
        break;
    case '3':
        return generateLastName();
        break;
    case '4':
        return generateCountry();
        break;
    case '5':
        return generatePhoneNumber();
        break;
    case '6':
        return generateEmailAddress();
        break;
    case '7':
        return generateSIN();
        break;
    case '8':
        return generatePassword();
        break;
    default:
        printf("Invalid column number: %c.\n", column);
        printf("Program terminating.\n");
        exit(0);
    }
}


char* generateUserID(int i) {
    int len = snprintf(NULL, 0, "%d", i);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    if (str == NULL) {
        printf("Could not allocate memory for User ID.\n");
        printf("Program terminating.\n");
        exit(0);
    }

    snprintf(str, len + 1, "%d", i);
    return str;
}

char* generateFirstName() {

}

char* generateLastName() {

}

char* generateCountry() {

}

char* generatePhoneNumber() {

}

char* generateEmailAddress() {

}

char* generateSIN() {

}

char* generatePassword() {

}

char* pickRandomString(char** strings) {

}