#include <iostream>
#include "Character.h"
#include "Utilities.h"
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include "ProfileManager.h"
#include <iomanip>
using namespace std;

void displayCharacter(const char* profileName) {
    Character characterP;
    char filePath[100];
	snprintf(filePath, sizeof(filePath), "../assets/data/characters/%s", profileName);

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

void displayItems(const Item* items, int size) {
    cout << "Items sorted:\n";
    cout << "--------------------------------------------------------------\n";
    cout << "| Name                     | Type          | Effect | Rarity  |\n";
    cout << "--------------------------------------------------------------\n";
    
    for (int i = 0; i < size; i++) {
        cout << "| " << left << setw(25) << items[i].name 
             << "| " << left << setw(13) << items[i].type   
             << "| " << right << setw(6) << items[i].effect 
             << "| " << left << setw(9) << items[i].rarity << " |\n";
    }
    
    cout << "-------------------------------------------------------------\n";
    cout << "Descriptions:\n";
    for (int i = 0; i < size; i++) {
        cout << "Item " << (i + 1) << ": " << items[i].description << endl;
    }
}

void displaySkills(const Skill* skills, int size) {
    cout << "Skills:\n";
    cout << "----------------------------------------------------------\n";
    cout << "| Name                     | Level | Cooldown | Mana Cost |\n";
    cout << "----------------------------------------------------------\n";
    
    for (int i = 0; i < size; i++) {
        cout << "| " << left << setw(25) << skills[i].name 
             << "| " << right << setw(6) << skills[i].level 
             << "| " << right << setw(9) << skills[i].cooldown 
             << "| " << right << setw(10) << skills[i].manaCost << " |\n";
    }
    
    cout << "----------------------------------------------------------\n";
    cout << "Descriptions:\n";
    for (int i = 0; i < size; i++) {
        cout << "Skill " << (i + 1) << ": " << skills[i].description << endl;
    }
}

