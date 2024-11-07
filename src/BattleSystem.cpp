#include <iostream>
#include <cstring>
#include <fstream>  // Necesario para ifstream
#include "Character.h"
#include "Inventory.h"
#include "Utilities.h"
#include <cstdlib>
using namespace std;

// Definir una estructura de personaje para las peleas
struct FightCharacter {
    char name[30];
    int health;
    int attack;
    int defense;
};

// Función para inicializar un personaje de pelea desde un archivo
bool loadFightCharacter(FightCharacter& character, const char* name) {
    char nameBuffer[30];
    strcpy(nameBuffer, name);  // Copiar el nombre en el buffer

    // Reemplazar los espacios por guiones bajos
    replaceSpace(nameBuffer);

    // Crear la ruta al archivo del personaje
    char filePath[100];
    snprintf(filePath, sizeof(filePath), "../assets/ascii_art/characters/%s.txt", nameBuffer);
    
    ifstream file(filePath);
    if (!file) {
        cout << "Error: Could not load character " << name << endl;
        return false;
    }

    strcpy(character.name, nameBuffer);
    character.health = 100;
    character.attack = 20;
    character.defense = 10;
    
    return true;
}

// Función para realizar el ataque del personaje
int attack(FightCharacter& attacker, FightCharacter& defender) {
    int damage = attacker.attack - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    return damage;
}

// Función para mostrar el estado de ambos personajes
void showBattleStatus(const FightCharacter& p1, const FightCharacter& p2) {
    cout << "\n--- Battle Status ---" << endl;
    cout << p1.name << " - Health: " << p1.health << endl;
    cout << p2.name << " - Health: " << p2.health << endl;
}

// Función de batalla controlada por el usuario
void battle(FightCharacter& player, FightCharacter& enemy) {
    int turn = 1;
    while (player.health > 0 && enemy.health > 0) {
        cout << "\n--- Turn " << turn << " ---" << endl;
        cout << player.name << "'s health: " << player.health << ", " << enemy.name << "'s health: " << enemy.health << "\n";
        
        // Opciones del usuario en su turno
        cout << "\nYour turn! Choose an action:\n";
        cout << "1. Attack\n";
        cout << "2. Defend\n";
        int choice;
        choice = readInt("Enter your choice: ",1,2);

        if (choice == 1) {
            int damage = attack(player, enemy);
            cout << player.name << " attacks " << enemy.name << " and deals " << damage << " damage!" << endl;
        } else if (choice == 2) {
            cout << player.name << " defends, reducing incoming damage on the next attack!" << endl;
            player.defense += 5; // Aumento temporal de defensa
        } else {
            cout << "Invalid choice. Skipping turn." << endl;
        }

        // Mostrar estado tras el ataque del jugador
        showBattleStatus(player, enemy);

        if (enemy.health <= 0) {
            cout << enemy.name << " is defeated!" << endl;
            break;
        }

        // Turno del enemigo
        cout << "\nEnemy's turn!\n";
        int damage = attack(enemy, player);
        cout << enemy.name << " attacks " << player.name << " and deals " << damage << " damage!" << endl;
        
        // Restablecer defensa si se usó en el turno anterior
        if (choice == 2) {
            player.defense -= 5;
        }
        
        showBattleStatus(player, enemy);

        if (player.health <= 0) {
            cout << player.name << " is defeated!" << endl;
            break;
        }

        turn++;
    }
}

// Función para iniciar la batalla entre dos personajes
void startBattle(const char* character1Name, const char* character2Name) {
    FightCharacter player, enemy;
    
    // Cargar los personajes desde los archivos
    if (!loadFightCharacter(player, character1Name) || !loadFightCharacter(enemy, character2Name)) {
        cout << "Error: Unable to load one of the characters!" << endl;
        return;
    }

    cout << "\nBattle Starting!" << endl;
    showBattleStatus(player, enemy);

    // Comenzar la pelea controlada por el usuario
    battle(player, enemy);
}
