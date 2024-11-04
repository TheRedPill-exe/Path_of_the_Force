#include <iostream>
#include <cstring>

using namespace std;

void encrypt(char text[], const char key[]) {
    int keyLength = strlen(key);
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ key[i % keyLength];
    }
}

void decrypt(char* text, const char* key) {
    encrypt(text, key);
}

bool signIn(char passw[], const char* profileName, const char* key) {
    FILE* user = fopen(profileName, "rb");

    if (user == NULL) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }

    char storedPassword[20]; // Ajusta el tamaño según lo que hayas definido
    fread(storedPassword, sizeof(char), sizeof(storedPassword), user);
    fclose(user);

    // Pedir al usuario que ingrese la contraseña
    cout << "Enter your password: ";
    cin >> passw;

    // Encriptar la contraseña ingresada
    encrypt(passw, key);

    // Comparar las contraseñas
    if (strcmp(passw, storedPassword) == 0) {
        cout << "Sign in successful!" << endl;
        return true;
    } else {
        cout << "Incorrect password." << endl;
        return false;
    }
}
