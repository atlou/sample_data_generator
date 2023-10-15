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

void freeUser(struct user* user) {
    if (user->firstName != NULL) {
        free(user->firstName);
        user->firstName = NULL;
    }
    if (user->lastName != NULL) {
        free(user->lastName);
        user->lastName = NULL;
    }
    if (user->country != NULL) {
        free(user->country);
        user->country = NULL;
    }
    if (user->phoneNumber != NULL) {
        free(user->phoneNumber);
        user->phoneNumber = NULL;
    }
    if (user->emailAddress != NULL) {
        free(user->emailAddress);
        user->emailAddress = NULL;
    }
    if (user->sin != NULL) {
        free(user->sin);
        user->sin = NULL;
    }
    if (user->password != NULL) {
        free(user->password);
        user->password = NULL;
    }
}

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
    return strdup(strings[i]); // duplicating so the structs don't point to the real values
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

    free(indexCode);
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

    // allocate memory for email address
    char* email = (char*)malloc(len * sizeof(char));
    if (email == NULL) {
        printf("Could not allocate memory for email address.\n");
        printf("Program terminating.\n");
        exit(0);
    }

    // concatenate all parts
    strcpy(email, f);
    strcat(email, lname);
    strcat(email, "@");
    strcat(email, suffix);

    free(suffix);

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
    struct user* users = (struct user*)malloc(n * sizeof(struct user));
    if (users == NULL) {
        printf("Could not allocate memory for users.\n");
        printf("Program terminating.\n");
        exit(0);
    }

    int idBool = strchr(columns, '1') == NULL ? 0 : 1;
    int fnameBool = strchr(columns, '2') == NULL ? 0 : 1;
    int lnameBool = strchr(columns, '3') == NULL ? 0 : 1;
    int countryBool = strchr(columns, '4') == NULL ? 0 : 1;
    int phoneBool = strchr(columns, '5') == NULL ? 0 : 1;
    int emailBool = strchr(columns, '6') == NULL ? 0 : 1;
    int sinBool = strchr(columns, '7') == NULL ? 0 : 1;
    int passwordBool = strchr(columns, '8') == NULL ? 0 : 1;

    for (int i = 0; i < n; i++) {
        if (idBool == 1) {
            users[i].userID = i + 1;
        }
        if (fnameBool == 1) {
            users[i].firstName = generateFirstName();
        }
        if (lnameBool == 1) {
            users[i].lastName = generateLastName();
        }
        if (countryBool == 1) {
            users[i].country = generateCountry();
        }
        if (phoneBool == 1) {
            users[i].phoneNumber = generatePhoneNumber();
        }
        if (emailBool == 1) {
            users[i].emailAddress = generateEmailAddress(users[i].firstName, users[i].lastName);
        }
        if (sinBool == 1) {
            users[i].sin = generateSIN();
        }
        if (passwordBool == 1) {
            users[i].password = generatePassword();
        }
    }

    return users;
}
