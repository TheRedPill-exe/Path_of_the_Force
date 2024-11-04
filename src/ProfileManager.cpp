#include <iostream>
#include <cstring>
#include "Character.h"
using namespace std;

#include <cstring>

void encrypt(char text[], const char key[]) {
    int keyLength = strlen(key);
    for (int i = 0; text[i] != '\0'; i++) {
        // Calcula el desplazamiento usando el valor ASCII del carácter en la clave
        int shift = key[i % keyLength];
        text[i] = (text[i] + shift) % 128; // Mantén los caracteres en el rango ASCII (0-127)
    }
}

void decrypt(char text[], const char key[]) {
    int keyLength = strlen(key);
    for (int i = 0; text[i] != '\0'; i++) {
        int shift = key[i % keyLength];
        text[i] = (text[i] - shift + 128) % 128; // Inversa del cifrado para mantener el rango ASCII
    }
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

void modifyCharacter(char profileName[]) {
    Character characterP;
    char filePath[30];
    snprintf(filePath, sizeof(filePath), "../users/%s", profileName);
    
    FILE* user = fopen(filePath, "rb+");
    if (!user) {
        cout << "Character profile not found!" << endl;
        return;
    }
    
    fread(&characterP, sizeof(Character), 1, user);
    
    int option;
    do {
        cout << "\n--- Modify Character Menu ---" << endl;
        cout << "1. Change Basic Attributes" << endl;
        cout << "2. Modify Skills" << endl;
        cout << "3. Modify Items" << endl;
        cout << "4. Save and Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                modifyCharacterAttributes(characterP);
                break;
            case 2:
                modifyCharacterSkills(characterP);
                break;
            case 3:
                modifyCharacterItems(characterP);
                break;
            case 4:
                fseek(user, 0, SEEK_SET);
                fwrite(&characterP, sizeof(Character), 1, user);
                cout << "Changes saved successfully!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);

    fclose(user);
}

void modifyCharacterAttributes(Character& characterP) {
    cout << "\n-- Modify Basic Attributes --" << endl;
    readCharacterAttributes(characterP);
}

void modifyCharacterSkills(Character& characterP) {
    int option;
    cout << "\nType 1 to select skills from list or 0 to enter manually: ";
    cin >> option;
    configureCharacterSkills(characterP, option);
}

void modifyCharacterItems(Character& characterP) {
    int option;
    cout << "\nType 1 to select items from list or 0 to enter manually: ";
    cin >> option;
    configureCharacterItems(characterP, option);
}