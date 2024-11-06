#ifndef DISPLAY_H
#define DISPLAY_H
#include "Character.h"
void displayCharacter(char* profileName);
void printCharac(char nameC[]);
void displayCustom(char* profileName);
void displayItems(const Item* items, int size);
void displaySkills(const Skill* skills, int size);
void displayCharacters(const Character* characters, int size);
#endif // DISPLAY_H
