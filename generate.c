// the code used to generate data
// for the various rows/columns

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "tablegen.h"
#include "generate.h"

#define SIN_LENGTH 9
#define PASSWORD_LENGTH_MIN 6
#define PASSWORD_LENGTH_MAX 16
#define PHONE_INDEX_LENGTH 3
#define PHONE_LINE_LENGTH 4

// global variables
extern char** firstNames;
extern char** lastNames;
extern char** countries;
extern char** emailSuffixes;

// generates a random character string
// takes in a length, a starting character, and an ending character
// those characters are used to establish a range in the ASCII table
// returns a random string made from characters in that range
char* randomASCII(int len, char start, char end) {

    char* str = (char*)malloc(sizeof(char) * (len + 1));
    if (str == NULL) {
        printf("Could not allocate memory for a random ASCII string.\n");
        printf("Program terminating.\n");
        exit(0);
    }

    int r = end - start + 1; // range size
    for (int i = 0; i < len; i++) {
        char c = (rand() % r) + start;
        // avoid commas
        while (c == ',') {
            c = (rand() % r) + start;
        }
        str[i] = c; // random ascii character from range [start to end]
    }
    str[len] = '\0'; // terminating char

    return str;
}

char* pickRandomString(char** strings, int len) {
    int i = rand() % len; // random number from 0 to len-1
    return strings[i];
}

char* generateFirstName() {
    return pickRandomString(firstNames, FIRST_NAMES_COUNT);
}

char* generateLastName() {
    return pickRandomString(lastNames, LAST_NAMES_COUNT);
}

char* generateCountry() {
    return pickRandomString(countries, COUNTRIES_COUNT);
}

char* generatePhoneNumber() {
    char* indexCodes[] = { "398", "270", "925", "867", "209", "429", "908", "997", "444", "219" };
    int indexCodesCount = 10;

    // pick a random index code
    char* indexCode = pickRandomString(indexCodes, indexCodesCount);

    // generate the last 4 digits
    char* phoneLine = randomASCII(PHONE_LINE_LENGTH, '0', '9');

    // concat index and line
    char* phoneNumber = (char*)malloc((PHONE_INDEX_LENGTH + PHONE_LINE_LENGTH + 2) * sizeof(char));
    if (phoneNumber == NULL) {
        printf("Could not allocate memory for phone number.\n");
        printf("Program terminating.\n");
        exit(0);
    }
    strncpy(phoneNumber, indexCode, PHONE_INDEX_LENGTH); // copy index code into phone number
    phoneNumber[PHONE_INDEX_LENGTH] = '-'; // add hyphen
    strncpy(phoneNumber + PHONE_INDEX_LENGTH + 1, phoneLine, PHONE_LINE_LENGTH); // copy phoneline into phone number
    phoneNumber[PHONE_INDEX_LENGTH + PHONE_LINE_LENGTH + 1] = '\0'; // add terminating character

    free(phoneLine);

    return phoneNumber;
}

char* generateEmailAddress(char* fname, char* lname) {
    // shorten first name to one char only
    char f[2];
    strncpy(f, fname, 1);
    f[1] = '\0';

    // pick random suffix
    char* suffix = pickRandomString(emailSuffixes, EMAIL_SUFFIXES_COUNT);

    // length = first letter + last name + @ + suffix + terminating char
    int len = 1 + strlen(lname) + 1 + strlen(suffix) + 1;

    // concatenate all parts
    char* email = (char*)malloc(len * sizeof(char));
    strcpy(email, f);
    strcat(email, lname);
    strcat(email, "@");
    strcat(email, suffix);

    return email;
}

char* generateSIN() {
    return randomASCII(SIN_LENGTH, '0', '9');
}

char* generatePassword() {
    int r = PASSWORD_LENGTH_MAX - PASSWORD_LENGTH_MIN;
    int len = (rand() % r) + PASSWORD_LENGTH_MIN;
    return randomASCII(len, '!', '~');
}

// generates an array of n number of users
// only assigns variables for the right columns
// returns a pointer of users
struct user* generateUsers(char* columns, int n) {

    // allocate memory for n numbers of structs
    struct user* users = malloc(n * sizeof(struct user));

    for (int i = 0; i < n; i++) {
        if (strchr(columns, '1') != NULL) {
            users[i].userID = i + 1;
        }
        if (strchr(columns, '2') != NULL) {
            users[i].firstName = generateFirstName();
        }
        if (strchr(columns, '3') != NULL) {
            users[i].lastName = generateLastName();
        }
        if (strchr(columns, '4') != NULL) {
            users[i].country = generateCountry();
        }
        if (strchr(columns, '5') != NULL) {
            users[i].phoneNumber = generatePhoneNumber();
        }
        if (strchr(columns, '6') != NULL) {
            users[i].emailAddress = generateEmailAddress(users[i].firstName, users[i].lastName);
        }
        if (strchr(columns, '7') != NULL) {
            users[i].sin = generateSIN();
        }
        if (strchr(columns, '8') != NULL) {
            users[i].password = generatePassword();
        }
    }

    return users;
}
