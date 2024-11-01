#include <iostream>
#include <stdio.h>
#include <limits>
using namespace std;

struct Skill {
    char name[50];
    char description[100];
    char type[15];
    int cooldown;
    int level;
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
    char name[25];
    char species[15];
    char faction[15];

    int health;
    int strength;
    int agility;
    int intelligence;

    int attackPower;
    int defense;

    Skill skills[3]; // Arreglo de exactamente 3 habilidades
    Item items[3];   // Arreglo de exactamente 3 objetos
};
int readInt(const char* prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
            cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer después de una entrada válida
            return value;
        }
    }
}

// Función para leer cadenas con validación
void readString(const char* prompt, char* buffer, size_t size) {
    while (true) {
        cout << prompt;
        cin.ignore(); // Limpiar el buffer antes de usar getline
        cin.getline(buffer, size);

        if (buffer[0] == '\0') { // Verificar si la cadena está vacía
            cout << "Input cannot be empty. Please enter a valid input." << endl;
        } else {
            break; // Salir del ciclo si la entrada es válida
        }
    }
}

void createCharacter(char profileName[]) {
    Character characterP;
	
	FILE* user = fopen(profileName, "wb+");
	
    cout << "Enter your character name: ";
    cin >> characterP.name;
    cout << "Enter your character species: ";
    cin >> characterP.species;
    cout << "Enter your character faction: ";
    cin >> characterP.faction;
    cout << "Enter your character health: ";
    cin >> characterP.health;
    cout << "Enter your character strength: ";
    cin >> characterP.strength;
    cout << "Enter your character agility: ";
    cin >> characterP.agility;
    cout << "Enter your character intelligence: ";
    cin >> characterP.intelligence;
    cout << "Enter your character attack power: ";
    cin >> characterP.attackPower;
    cout << "Enter your character defense: ";
    cin >> characterP.defense;

    for (int i = 0; i < 3; i++) {
        Skill skill;

        cout << "Enter your character skill number " << (i + 1) << " name: ";
        cin.ignore(); // Limpiar el buffer antes de usar getline
        cin.getline(skill.name, 50);
        cout << "Enter your character skill number " << (i + 1) << " description: ";
        cin.getline(skill.description, 100);
        cout << "Enter your character skill number " << (i + 1) << " level: ";
        cin >> skill.level;
        cout << "Enter your character skill number " << (i + 1) << " cooldown: ";
        cin >> skill.cooldown;
        cout << "Enter your character skill number " << (i + 1) << " mana cost: ";
        cin >> skill.manaCost;

        characterP.skills[i] = skill; // Asignar habilidad al arreglo
    }

    for (int i = 0; i < 3; i++) {
        Item item;

        cout << "Enter your character item number " << (i + 1) << " name: ";
        cin.ignore(); // Limpiar el buffer antes de usar getline
        cin.getline(item.name, 50);
        cout << "Enter your character item number " << (i + 1) << " type: ";
        cin >> item.type;
        cout << "Enter your character item number " << (i + 1) << " effect: ";
        cin >> item.effect;
        cout << "Enter your character item number " << (i + 1) << " rarity: ";
        cin >> item.rarity;
        cout << "Enter your character item number " << (i + 1) << " description: ";
        cin.ignore(); // Limpiar el buffer antes de usar getline
        cin.getline(item.description, 100);

        characterP.items[i] = item; // Asignar objeto al arreglo
    }

    fwrite(&characterP, sizeof(characterP), 1, user);
    fclose(user);
}

int main() {
    createCharacter("profile1.dat");
    return 0;
}

