#ifndef GENERATE_H_
#define GENERATE_H_
// TODO: Remove all but generateTable?
char** generateTable(char* columns, int rowCount);
char* generateRow(char* columns, int rowIndex);
char* generateField(char column, int rowIndex);
char* generateUserID(int i);
char* generateFirstName();
char* generateLastName();
char* generateCountry();
char* generatePhoneNumber();
char* generateEmailAddress();
char* generateSIN();
char* generatePassword();
char* pickRandomString(char** strings);

#endif