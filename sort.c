// any code related to sorting the generated table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "generate.h"

int compareFirstNames(const void* a, const void* b) {
    const struct user* userA = (const struct user*)a;
    const struct user* userB = (const struct user*)b;
    return strcmp(userA->firstName, userB->firstName);
}

int compareLastNames(const void* a, const void* b) {
    const struct user* userA = (const struct user*)a;
    const struct user* userB = (const struct user*)b;
    return strcmp(userA->lastName, userB->lastName);
}

int compareCountry(const void* a, const void* b) {
    const struct user* userA = (const struct user*)a;
    const struct user* userB = (const struct user*)b;
    return strcmp(userA->country, userB->country);
}

int comparePhoneNumber(const void* a, const void* b) {
    const struct user* userA = (const struct user*)a;
    const struct user* userB = (const struct user*)b;
    return strcmp(userA->phoneNumber, userB->phoneNumber);
}

int compareEmailAddress(const void* a, const void* b) {
    const struct user* userA = (const struct user*)a;
    const struct user* userB = (const struct user*)b;
    return strcmp(userA->emailAddress, userB->emailAddress);
}

int compareSIN(const void* a, const void* b) {
    const struct user* userA = (const struct user*)a;
    const struct user* userB = (const struct user*)b;
    return strcmp(userA->sin, userB->sin);
}

int comparePassword(const void* a, const void* b) {
    const struct user* userA = (const struct user*)a;
    const struct user* userB = (const struct user*)b;
    return strcmp(userA->password, userB->password);
}

void sortUsers(struct user* users, int count, char col) {
    switch (col) {
    case '1': return; // user IDs are already sorted
        break;
    case '2':
        qsort(users, count, sizeof(struct user), compareFirstNames);
        break;
    case '3':
        qsort(users, count, sizeof(struct user), compareLastNames);
        break;
    case '4':
        qsort(users, count, sizeof(struct user), compareCountry);
        break;
    case '5':
        qsort(users, count, sizeof(struct user), comparePhoneNumber);
        break;
    case '6':
        qsort(users, count, sizeof(struct user), compareEmailAddress);
        break;
    case '7':
        qsort(users, count, sizeof(struct user), compareSIN);
        break;
    case '8':
        qsort(users, count, sizeof(struct user), comparePassword);
        break;
    }
}