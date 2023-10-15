#ifndef GENERATE_H_
#define GENERATE_H_

struct user {
    int userID;
    char* firstName;
    char* lastName;
    char* country;
    char* phoneNumber;
    char* emailAddress;
    char* sin;
    char* password;
};

void freeUser(struct user* user);
struct user* generateUsers(char* columns, int n);

#endif