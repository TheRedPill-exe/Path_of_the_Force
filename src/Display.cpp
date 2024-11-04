#include <iostream>
#include "Character.h"
#include "Utilities.h"
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include "ProfileManager.h"

using namespace std;

void displayCharacter(const char* profileName) {
    Character characterP;
    char filePath[50];
	snprintf(filePath, sizeof(filePath), "../users/%s", profileName);

    FILE* user = fopen(filePath, "rb");

    if (user == NULL) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    fread(&characterP, sizeof(Character), 1, user);
    fclose(user);

    cout << "Character Information:" << endl;
    cout << "Name: " << characterP.name << endl;
    cout << "Species: " << characterP.species << endl;
    cout << "Faction: " << characterP.faction << endl;
    cout << "Health: " << characterP.health << endl;
    cout << "Strength: " << characterP.strength << endl;
    cout << "Agility: " << characterP.agility << endl;
    cout << "Intelligence: " << characterP.intelligence << endl;
    cout << "Attack Power: " << characterP.attackPower << endl;
    cout << "Defense: " << characterP.defense << endl;

    cout << "\nSkills:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Skill " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.skills[i].name << endl;
        cout << "    Description: " << characterP.skills[i].description << endl;
        cout << "    Level: " << characterP.skills[i].level << endl;
        cout << "    Cooldown: " << characterP.skills[i].cooldown << endl;
        cout << "    Mana Cost: " << characterP.skills[i].manaCost << endl;
    }

    cout << "\nItems:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Item " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.items[i].name << endl;
        cout << "    Type: " << characterP.items[i].type << endl;
        cout << "    Effect: " << characterP.items[i].effect << endl;
        cout << "    Rarity: " << characterP.items[i].rarity << endl;
        cout << "    Description: " << characterP.items[i].description << endl;
    }
}

void displayCustom(const char* profileName) {
    Character characterP;
    char filePath[50];
    snprintf(filePath, sizeof(filePath), "../users/%s", profileName);

    FILE* user = fopen(filePath, "rb");

    if (user == NULL) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    fread(&characterP, sizeof(Character), 1, user);
    fclose(user);

    // Pide la palabra clave para desencriptar
    char keyword[10];
    cout << "Enter the keyword to decrypt the character information: ";
    cin >> keyword;

    // Desencriptar los campos de texto del personaje
    decrypt(characterP.name, keyword);
    decrypt(characterP.species, keyword);
    decrypt(characterP.faction, keyword);
    for (int i = 0; i < 3; i++) {
        decrypt(characterP.skills[i].name, keyword);
        decrypt(characterP.skills[i].description, keyword);
    }
    for (int i = 0; i < 3; i++) {
        decrypt(characterP.items[i].name, keyword);
        decrypt(characterP.items[i].type, keyword);
        decrypt(characterP.items[i].rarity, keyword);
        decrypt(characterP.items[i].description, keyword);
    }

    // Mostrar la información del personaje
    cout << "Character Information:" << endl;
    cout << "Name: " << characterP.name << endl;
    cout << "Species: " << characterP.species << endl;
    cout << "Faction: " << characterP.faction << endl;
    cout << "Health: " << characterP.health << endl;
    cout << "Strength: " << characterP.strength << endl;
    cout << "Agility: " << characterP.agility << endl;
    cout << "Intelligence: " << characterP.intelligence << endl;
    cout << "Attack Power: " << characterP.attackPower << endl;
    cout << "Defense: " << characterP.defense << endl;

    cout << "\nSkills:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Skill " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.skills[i].name << endl;
        cout << "    Description: " << characterP.skills[i].description << endl;
        cout << "    Level: " << characterP.skills[i].level << endl;
        cout << "    Cooldown: " << characterP.skills[i].cooldown << endl;
        cout << "    Mana Cost: " << characterP.skills[i].manaCost << endl;
    }

    cout << "\nItems:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Item " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.items[i].name << endl;
        cout << "    Type: " << characterP.items[i].type << endl;
        cout << "    Effect: " << characterP.items[i].effect << endl;
        cout << "    Rarity: " << characterP.items[i].rarity << endl;
        cout << "    Description: " << characterP.items[i].description << endl;
    }
}

void printCharac(char nameC[]) {
    if (isName(nameC)) {
        replaceSpace(nameC);
        
        // Construye la ruta del archivo usando el nombre del personaje
        char filePath[100];
        snprintf(filePath, sizeof(filePath), "../assets/ascii_art/characters/%s.txt", nameC);
        
        // Abre el archivo usando fopen
        FILE* user = fopen(filePath, "r"); // Abre el archivo en modo lectura
        if (!user) {
            cout << "Error: Unable to open file." << endl;
            return;
        }

        char line[256];
        // Lee y muestra el contenido del archivo
        while (fgets(line, sizeof(line), user)) {
            cout << line; // Imprime cada línea leída
        }
        fclose(user); // Cierra el archivo
    }
}
