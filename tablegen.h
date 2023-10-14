#ifndef TABLEGEN_H_
#define TABLEGEN_H_

// expected number of entries in data files
#define FIRST_NAMES_COUNT 1000
#define LAST_NAMES_COUNT 1000
#define COUNTRIES_COUNT 195
#define EMAIL_SUFFIXES_COUNT 100

// files paths
#define FIRST_NAMES_FILE "./first_names.txt"
#define LAST_NAMES_FILE "./last_names.txt"
#define COUNTRIES_FILE "./countries.txt"
#define EMAIL_SUFFIXES_FILE "./email_suffixes.txt"

char* columnsPrompt();
int rowsPrompt();
char* filePrompt();

#endif