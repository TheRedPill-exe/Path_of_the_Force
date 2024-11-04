#ifndef DISPLAY_H
#define DISPLAY_H
#include "Character.h"
void displayCharacter(const char* profileName);
void printCharac(char nameC[]);
void displayCustom(const char* profileName);
void displayItems(const Item* items, int size);
void displaySkills(const Skill* skills, int size);

#endif // DISPLAY_H
