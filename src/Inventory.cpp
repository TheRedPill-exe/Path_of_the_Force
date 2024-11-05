#include <iostream>
#include <cstdio>
#include <cstring>
#include "Display.h"
#include "Character.h"

using namespace std;

void readItemFromFile(Item& item, const char* fileName) {
    char filePath[40];
    snprintf(filePath, sizeof(filePath), "../assets/data/items/%s", fileName);

    FILE* file = fopen(filePath, "rb");
    if (file) {
        fread(&item, sizeof(Item), 1, file);
        fclose(file);
    } else {
        cout << "Error opening file: " << fileName << endl;
    }
}

void bubbleSortByEffect(Item* items, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (items[j].effect > items[j + 1].effect) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

void bubbleSortByRarity(Item* items, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(items[j].rarity, items[j + 1].rarity) > 0) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

void bubbleSortByName(Item* items, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(items[j].name, items[j + 1].name) > 0) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

// Ordena Items por tipo
void bubbleSortByType(Item* items, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(items[j].type, items[j + 1].type) > 0) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

// Modifica la función loadAndSortItems para incluir la nueva opción de ordenación
void loadAndSortItems(const char* filePrefix, int numberOfItems, const char* sortBy) {
    Item* items = new Item[numberOfItems];  // Memoria dinámica para los ítems

    for (int i = 0; i < numberOfItems; i++) {
        char fileName[50];
        sprintf(fileName, "%s%02d.bin", filePrefix, i + 1);
        readItemFromFile(items[i], fileName);
    }

    // Ordenar según el criterio especificado
    if (strcmp(sortBy, "effect") == 0) {
        bubbleSortByEffect(items, numberOfItems);
    } else if (strcmp(sortBy, "rarity") == 0) {
        bubbleSortByRarity(items, numberOfItems);
    } else if (strcmp(sortBy, "name") == 0) {
        bubbleSortByName(items, numberOfItems);
    } else if (strcmp(sortBy, "type") == 0) {
        bubbleSortByType(items, numberOfItems);
    }

    displayItems(items, numberOfItems);

    delete[] items;  // Liberar la memoria después de mostrar los ítems
}

void readSkillFromFile(Skill& skill, const char* fileName) {
    char filePath[40];
    snprintf(filePath, sizeof(filePath), "../assets/data/skills/%s", fileName);

    FILE* file = fopen(filePath, "rb");
    if (file) {
        fread(&skill, sizeof(Skill), 1, file);
        fclose(file);
    } else {
        cout << "Error opening file: " << fileName << endl;
    }
}

// Ordena Skills por nivel
void bubbleSortByLevel(Skill* skills, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (skills[j].level > skills[j + 1].level) {
                swap(skills[j], skills[j + 1]);
            }
        }
    }
}

// Ordena Skills por nombre
void bubbleSortByName(Skill* skills, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(skills[j].name, skills[j + 1].name) > 0) {
                swap(skills[j], skills[j + 1]);
            }
        }
    }
}
void bubbleSortByCooldown(Skill* skills, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (skills[j].cooldown > skills[j + 1].cooldown) {
                swap(skills[j], skills[j + 1]);
            }
        }
    }
}

// Ordena Skills por manaCost
void bubbleSortByManaCost(Skill* skills, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (skills[j].manaCost > skills[j + 1].manaCost) {
                swap(skills[j], skills[j + 1]);
            }
        }
    }
}
// Carga y ordena Skills
void loadAndSortSkills(const char* filePrefix, int numberOfSkills, const char* sortBy) {
    Skill* skills = new Skill[numberOfSkills];  // Memoria dinámica para los skills

    for (int i = 0; i < numberOfSkills; i++) {
        char fileName[50];
        sprintf(fileName, "%s%02d.bin", filePrefix, i + 1);
        readSkillFromFile(skills[i], fileName);
    }

    // Ordenar según el criterio especificado
    if (strcmp(sortBy, "level") == 0) {
    bubbleSortByLevel(skills, numberOfSkills);
    } else if (strcmp(sortBy, "cooldown") == 0) {
        bubbleSortByCooldown(skills, numberOfSkills);
    } else if (strcmp(sortBy, "manaCost") == 0) {
        bubbleSortByManaCost(skills, numberOfSkills);
    } else if (strcmp(sortBy, "name") == 0) {
        bubbleSortByName(skills, numberOfSkills);
    }


    displaySkills(skills, numberOfSkills); // Asegúrate de que displayItems funcione con Skill

    delete[] skills;  // Liberar la memoria después de mostrar los skills
}
