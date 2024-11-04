#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

void encrypt(char text[], const char key[]);
void decrypt(char* text, const char* key);
bool signIn(char passw[], const char* profileName, const char* key);

#endif // PROFILEMANAGER_H
