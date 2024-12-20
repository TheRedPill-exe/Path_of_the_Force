#ifndef UTILITIES_H
#define UTILITIES_H

int readInt(const char* prompt, int min, int max);
void readString(const char* prompt, char* buffer, size_t size);
bool isName(char nameC[]);
void replaceSpace(char str[]);
void clearConsole();
bool exists(const char* filename);
#endif // UTILITIES_H
