#ifndef IO_H_
#define IO_H_

void freeStrings(char** strings, int n);
char** readFile(int n, char filePath[]);
void writeTable(int n, struct user* users, char* columns, char* fileName);

#endif