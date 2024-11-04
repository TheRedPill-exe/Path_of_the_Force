#ifndef INVENTORY_H
#define INVENTORY_H

#include "Character.h"
#include "Display.h"

void readItemFromFile(Item& item, const char* fileName);
void bubbleSortByEffect(Item* items, int size);
void bubbleSortByRarity(Item* items, int size);
void bubbleSortByName(Item* items, int size);
void loadAndSortItems(const char* filePrefix, int numberOfItems, const char* sortBy);
void loadAndSortSkills(const char* filePrefix, int numberOfSkills, const char* sortBy);
#endif // INVENTORY_H