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
void modifyCharacter(char profileName[], const char key[]) {
    Character characterP;
    char filePath[30];
    snprintf(filePath, sizeof(filePath), "../users/%s", profileName);
    
    FILE* user = fopen(filePath, "rb+");
    if (!user) {
        cout << "Character profile not found!" << endl;
        return;
    }

    // Leer el personaje encriptado
    fread(&characterP, sizeof(Character), 1, user);

    // Desencriptar para poder trabajar en texto plano
    decrypt(characterP.name, key);
    decrypt(characterP.species, key);
    decrypt(characterP.faction, key);
    for (int i = 0; i < 3; i++) {
        decrypt(characterP.skills[i].name, key);
        decrypt(characterP.skills[i].description, key);
        decrypt(characterP.items[i].name, key);
        decrypt(characterP.items[i].type, key);
        decrypt(characterP.items[i].rarity, key);
        decrypt(characterP.items[i].description, key);
    }

    // Solicitar y verificar la contraseña
    char inputPassword[20];
    cout << "Enter your password: ";
    cin >> inputPassword;
    encrypt(inputPassword, key);
    if (strcmp(inputPassword, characterP.password) != 0) {
        cout << "Incorrect password. Access denied." << endl;
        fclose(user);
        return;
    }

    // Menú de modificación
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
                // Reencriptar datos antes de guardar
                encrypt(characterP.name, key);
                encrypt(characterP.species, key);
                encrypt(characterP.faction, key);
                for (int i = 0; i < 3; i++) {
                    encrypt(characterP.skills[i].name, key);
                    encrypt(characterP.skills[i].description, key);
                    encrypt(characterP.items[i].name, key);
                    encrypt(characterP.items[i].type, key);
                    encrypt(characterP.items[i].rarity, key);
                    encrypt(characterP.items[i].description, key);
                }
                // Guardar en archivo
                fseek(user, 0, SEEK_SET);
                fwrite(&characterP, sizeof(Character), 1, user);
                cout << "Changes saved and encrypted successfully!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);

    fclose(user);
}

bool deleteCharacter(const char* fileName, const char* key) {
    char filePath[50];
    snprintf(filePath, sizeof(filePath), "../users/%s", fileName);
    FILE* file = fopen(filePath, "rb");
    Character characterP;
    
    // Verificar si el archivo existe
    if (!file) {
        cout << "Error: File not found." << endl;
        return false;
    }

    // Leer la contraseña almacenada en el archivo
    fread(&characterP, sizeof(characterP), 1 , file);
    fclose(file);

    // Solicitar la contraseña al usuario
    char inputPassword[20];
    cout << "Enter your password: ";
    cin >> inputPassword;

    // Encriptar la contraseña ingresada
    encrypt(inputPassword, key);

    // Verificar que coincida con la contraseña almacenada
    if (strcmp(inputPassword, characterP.password) != 0) {
        cout << "Incorrect password. Access denied." << endl;
        return false;
    }

    // Eliminar el archivo si la contraseña es correcta
    if (remove(filePath) == 0) {
        cout << "File deleted successfully." << endl;
        return true;
    } else {
        perror("Error");
        return false;
    }
}