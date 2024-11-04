#include <iostream>
#include <stdio.h>
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include "Display.h"
#include "Character.h"
#include "Utilities.h"
#include "ProfileManager.h"

using namespace std;

enum ItemType {
    WEAPON,
    ARMOR,
    POTION,
    ACCESSORY
};

enum Rarity {
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY
};

// Funci�n para crear un personaje y pedir todos los datos necesarios
void createCharacter(char profileName[]) {
    Character characterP;
    char filePath[30];
    snprintf(filePath, sizeof(filePath), "../users/%s", profileName);
    FILE* user = fopen(filePath, "wb+");
    
    // Leer y encriptar los datos del personaje
    readString("Enter your character name: ", characterP.name, sizeof(characterP.name));
    readString("Enter your character species: ", characterP.species, sizeof(characterP.species));
    readString("Enter your character faction: ", characterP.faction, sizeof(characterP.faction));
    
    characterP.health = readInt("Enter your character health (1 - 100): ", 1, 100);
    characterP.strength = readInt("Enter your character strength (1 - 100): ", 1, 100);
    characterP.agility = readInt("Enter your character agility (1 - 100): ", 1, 100);
    characterP.intelligence = readInt("Enter your character intelligence (1 - 100): ", 1, 100);
    characterP.attackPower = readInt("Enter your character attack power (1 - 100): ", 1, 100);
    characterP.defense = readInt("Enter your character defense (1 - 100): ", 1, 100);

    cout << "It's time to create your character abilities!" << endl;
    cout << "(Whatever the description, it will deal damage with its level 1 time.)" << endl;

    // Leer y encriptar habilidades
    for (int i = 0; i < 3; i++) {
        Skill skill;
    
        cout << "Enter your character skill number " << (i + 1) << " name: ";
        readString("", skill.name, sizeof(skill.name));
        cout << "Enter your character skill number " << (i + 1) << " description: ";
        readString("", skill.description, sizeof(skill.description));
        cout << "Enter your character skill number " << (i + 1) << " level: ";
        skill.level = readInt("", 1, 100);
        cout << "Enter your character skill number " << (i + 1) << " cooldown: ";
        skill.cooldown = readInt("", 1, 100);
        cout << "Enter your character skill number " << (i + 1) << " mana cost: ";
        skill.manaCost = readInt("", 1, 100);
    
        characterP.skills[i] = skill; // Asignar habilidad al arreglo
    }

    // Leer y encriptar items
    for (int i = 0; i < 3; i++) {
        Item item;

        cout << "Enter your character item number " << (i + 1) << " name: ";
        readString("", item.name, sizeof(item.name));
        cout << "Enter your character item number " << (i + 1) << " type: ";
        readString("", item.type, sizeof(item.type));
        cout << "Enter your character item number " << (i + 1) << " effect: ";
        item.effect = readInt("", 0, 10); // Asegúrate de que esto sea un entero
        cout << "Enter your character item number " << (i + 1) << " rarity: ";
        readString("", item.rarity, sizeof(item.rarity));
        cout << "Enter your character item number " << (i + 1) << " description: ";
        readString("", item.description, sizeof(item.description));

        characterP.items[i] = item; // Asignar objeto al arreglo
    }

    char passw[10];
    char keyword[10];
    cout << "Enter your password: ";
    cin >> passw;
    cout << "Enter a keyword: ";
    cin >> keyword;
    encrypt(passw, keyword);
    strcpy(characterP.password, passw); // Copia la contraseña encriptada

    // Encriptar los campos de texto del personaje
    encrypt(characterP.name, keyword);
    encrypt(characterP.species, keyword);
    encrypt(characterP.faction, keyword);
    for (int i = 0; i < 3; i++) {
        encrypt(characterP.skills[i].name, keyword);
        encrypt(characterP.skills[i].description, keyword);
    }
    for (int i = 0; i < 3; i++) {
        encrypt(characterP.items[i].name, keyword);
        encrypt(characterP.items[i].type, keyword);
        encrypt(characterP.items[i].rarity, keyword);
        encrypt(characterP.items[i].description, keyword);
    }

    cout << "Character created successfully!" << endl;
    fwrite(&characterP, sizeof(characterP), 1, user);
    fclose(user);
}
