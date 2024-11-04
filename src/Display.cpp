#include <iostream>
#include "Character.h"

using namespace std;

void displayCharacter(const char* profileName) {
    Character characterP;
    FILE* user = fopen(profileName, "rb");

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


