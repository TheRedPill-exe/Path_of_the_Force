#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

struct Skill {
    char name[50];
    char description[100];
    int level;
    int cooldown;
    int manaCost;
};

struct Item {
    char name[50];
    char type[20];
    int effect;
    char rarity[20];
    char description[100];
};

struct Character {
    char name[50];
    char species[50];
    char faction[50];
    int health;
    int strength;
    int agility;
    int intelligence;
    int attackPower;
    int defense;
    Skill skills[3];  
    Item items[3];
    char password[20];
};

void createCharacter(char profileName[]);
void readString(const char* prompt, char* buffer, size_t size);

#endif // CHARACTER_H

