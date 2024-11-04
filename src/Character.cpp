#include <iostream>
#include <stdio.h>
#include <limits>
#include <iostream>
#include <vector>
#include <string>
#include "Display.h"
#include "Character.h"
#include "Utilities.h"

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
    
    FILE* user = fopen(profileName, "wb+");
    
    readString("Enter your character name: ", characterP.name, sizeof(characterP.name));
    readString("Enter your character species: ", characterP.species, sizeof(characterP.species));
    readString("Enter your character faction: ", characterP.faction, sizeof(characterP.faction));
    
    characterP.health = readInt("Enter your character health (1 - 100): ", 1, 100);
    characterP.strength = readInt("Enter your character strength (1 - 100): ", 1, 100);
    characterP.agility = readInt("Enter your character agility (1 - 100): ", 1, 100);
    characterP.intelligence = readInt("Enter your character intelligence (1 - 100): ", 1, 100);
    characterP.attackPower = readInt("Enter your character attack power (1 - 100): ", 1, 100);
    characterP.defense = readInt("Enter your character defense (1 - 100): ", 1, 100);
    
    
    cout << "it's time to create your character habilities!" << endl;
    cout << "(Whatever the description, it will deal damage with its level 1 time.)" << endl;
    

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
	
	for (int i = 0; i < 3; i++) {
	    Item item;
	
	    cout << "Enter your character item number " << (i + 1) << " name: ";
	    readString("", item.name, sizeof(item.name));
	    
	    cout << "Enter your character item number " << (i + 1) << " type: ";
	    readString("", item.type, sizeof(item.type));
	    
	    cout << "Enter your character item number " << (i + 1) << " effect: ";
	    item.effect = ("", 0,10);
	    
	    cout << "Enter your character item number " << (i + 1) << " rarity: ";
	    readString("", item.rarity , sizeof(item.rarity));
	    
	    cout << "Enter your character item number " << (i + 1) << " description: ";
	    readString("", item.description, sizeof(item.description));
	
	    characterP.items[i] = item; // Asignar objeto al arreglo
	}

	cout << "Character created successfully!" << endl;
    fwrite(&characterP, sizeof(characterP), 1, user);
    fclose(user);
    
}


