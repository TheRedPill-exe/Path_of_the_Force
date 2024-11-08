#include <iostream>
#include <stdio.h>
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include "Display.h"
#include "Character.h"
#include "Utilities.h"
#include "ProfileManager.h"
#include "Inventory.h"

using namespace std;

void readCharacterAttributes(Character& characterP) {
    readString("Enter your character name: ", characterP.name, sizeof(characterP.name));
    readString("Enter your character species: ", characterP.species, sizeof(characterP.species));
    readString("Enter your character faction: ", characterP.faction, sizeof(characterP.faction));

    characterP.health = readInt("Enter your character health (1 - 100): ", 1, 100);
    characterP.strength = readInt("Enter your character strength (1 - 100): ", 1, 100);
    characterP.agility = readInt("Enter your character agility (1 - 100): ", 1, 100);
    characterP.intelligence = readInt("Enter your character intelligence (1 - 100): ", 1, 100);
    characterP.attackPower = readInt("Enter your character attack power (1 - 100): ", 1, 100);
    characterP.defense = readInt("Enter your character defense (1 - 100): ", 1, 100);
}

void configureCharacterSkills(Character& characterP, int option) {
    if (option == 1) {
        loadAndSortSkills("skill_", 50, "name");

        for (int i = 0; i < 3; i++) {
            Skill skill;
            int skillNumber = readInt("Enter the number of the skill you want to add \n(0X for the first 10 skills): ", 1, 50);
            char skillPath[100];
            snprintf(skillPath, sizeof(skillPath), "../assets/data/skills/skill_%02d.bin", skillNumber);

            FILE* skillFile = fopen(skillPath, "rb");
            fread(&skill, sizeof(Skill), 1, skillFile);
            characterP.skills[i] = skill;
            fclose(skillFile);
        }

    } else {
        for (int i = 0; i < 3; i++) {
            Skill skill;
            readString("Enter your character skill name: ", skill.name, sizeof(skill.name));
            readString("Enter your character skill description: ", skill.description, sizeof(skill.description));
            skill.level = readInt("Enter your character skill level: ", 1, 100);
            skill.cooldown = readInt("Enter your character skill cooldown: ", 1, 100);
            skill.manaCost = readInt("Enter your character skill mana cost: ", 1, 100);
            characterP.skills[i] = skill;
        }
    }
}

void configureCharacterItems(Character& characterP, int option) {
    if (option == 1) {
        loadAndSortItems("item_", 50, "name");

        for (int i = 0; i < 3; i++) {
            Item item;
            int itemNumber = readInt("Enter the number of the item you want to add \n(0X for the first 10 items): ", 1, 50);
            char itemPath[100];
            snprintf(itemPath, sizeof(itemPath), "../assets/data/items/item_%02d.bin", itemNumber);

            FILE* itemFile = fopen(itemPath, "rb");
            fread(&item, sizeof(Item), 1, itemFile);
            characterP.items[i] = item;
            fclose(itemFile);
        }
    } else {
        for (int i = 0; i < 3; i++) {
            Item item;
            readString("Enter your character item name: ", item.name, sizeof(item.name));
            readString("Enter your character item type: ", item.type, sizeof(item.type));
            item.effect = readInt("Enter your character item effect: ", 0, 30);
            readString("Enter your character item rarity: ", item.rarity, sizeof(item.rarity));
            readString("Enter your character item description: ", item.description, sizeof(item.description));
            characterP.items[i] = item;
        }
    }
}

void encryptCharacterData(Character& characterP, char password[], char keyword[]) {
    
    encrypt(password, keyword);
    strcpy(characterP.password, password);

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
}

void createCharacter(char profileName[]) {
    Character characterP;
    char filePath[30];
    snprintf(filePath, sizeof(filePath), "../users/%s", profileName);
    
    FILE* user = fopen(filePath, "wb+");

    readCharacterAttributes(characterP);
    
    int option;
    option = readInt("Type 1 to select skills or 0 to select them manually: ", 0, 1);
    configureCharacterSkills(characterP, option);
    
    // Configurar objetos del personaje
    option = readInt("Type 1 to select items or 0 to select them manually:", 0, 1);
    configureCharacterItems(characterP, option);

    // Encriptar datos
    char password[10], keyword[10];
    readString("Enter your password: ", password, sizeof(password));
    readString("Enter a keyword: ", keyword, sizeof(keyword));
    encryptCharacterData(characterP, password, keyword);

    // Guardar y cerrar archivo
    cout << "Character created successfully!" << endl;
    fwrite(&characterP, sizeof(characterP), 1, user);
    fclose(user);
}

