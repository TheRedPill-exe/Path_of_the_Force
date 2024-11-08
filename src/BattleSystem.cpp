#include <iostream>
#include <cstring>
#include <fstream>  // Necesario para ifstream
#include "Character.h"
#include "Inventory.h"
#include "Utilities.h"
#include <cstdlib>
using namespace std;

// Función para inicializar un personaje de pelea desde un archivo
bool loadFightCharacter(Character& character, const char* name) {
    char nameBuffer[30];
    strcpy(nameBuffer, name);  // Copiar el nombre en el buffer

    // Reemplazar los espacios por guiones bajos
    replaceSpace(nameBuffer);

    // Crear la ruta al archivo del personaje
    char filePath[100];
    snprintf(filePath, sizeof(filePath), "../assets/data/characters/%s.bin", nameBuffer);
    
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        cout << "Error: Could not load character " << name << endl;
        return false;
    }
    fread(&character, sizeof(Character), 1, file);
    
    return true;
}

// Función para realizar el ataque del personaje
int attack(Character& attacker, Character& defender) {
    int damage = attacker.attackPower - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    return damage;
}

// Función para mostrar el estado de ambos personajes
void showBattleStatus(const Character& p1, const Character& p2) {
    cout << "\n--- Battle Status ---" << endl;
    cout << p1.name << " - Health: " << p1.health << endl;
    cout << p2.name << " - Health: " << p2.health << endl;
}

// Función de batalla controlada por el usuario
void battle(Character& player, Character& enemy, FILE* battleLog) {
    int turn = 1;
    while (player.health > 0 && enemy.health > 0) {
        fprintf(battleLog, "\n--- Turn %d ---\n", turn);
        fprintf(battleLog, "%s's health: %d, %s's health: %d\n", player.name, player.health, enemy.name, enemy.health);

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
            fprintf(battleLog, "%s attacks %s and deals %d damage!\n", player.name, enemy.name, damage);
        } else if (choice == 2) {
            cout << player.name << " defends, reducing incoming damage on the next attack!" << endl;
            player.defense += 5; // Aumento temporal de defensa
            fprintf(battleLog, "%s defends, boosting defense temporarily!\n", player.name);
        } else {
            cout << "Invalid choice. Skipping turn." << endl;
            fprintf(battleLog, "Invalid choice. Turn skipped.\n");
        }

        // Mostrar estado tras el ataque del jugador
        showBattleStatus(player, enemy);

        if (enemy.health <= 0) {
            cout << enemy.name << " is defeated!" << endl;
            fprintf(battleLog, "%s is defeated!\n", enemy.name);
            break;
        }

        // Turno del enemigo
        cout << "\nEnemy's turn!\n";
        int damage = attack(enemy, player);
        cout << enemy.name << " attacks " << player.name << " and deals " << damage << " damage!" << endl;
        fprintf(battleLog, "%s attacks %s and deals %d damage!\n", enemy.name, player.name, damage);
        
        // Restablecer defensa si se usó en el turno anterior
        if (choice == 2) {
            player.defense -= 5;
        }
        
        showBattleStatus(player, enemy);

        if (player.health <= 0) {
            cout << player.name << " is defeated!" << endl;
            fprintf(battleLog, "%s is defeated!\n", player.name);
            break;
        }

        turn++;
    }
}

// Función para iniciar la batalla entre dos personajes y registrar el historial
void startBattle(const char* character1Name, const char* character2Name, int battleNum) {
    Character player, enemy;
    
    // Cargar los personajes desde los archivos
    if (!loadFightCharacter(player, character1Name) || !loadFightCharacter(enemy, character2Name)) {
        cout << "Error: Unable to load one of the characters!" << endl;
        return;
    }

    // Crear el archivo de registro de batalla
    char logFilePath[100];
    snprintf(logFilePath, sizeof(logFilePath), "../battlesRegister/battle_%d.txt", battleNum);
    FILE* battleLog = fopen(logFilePath, "w");
    if (!battleLog) {
        cout << "Error: Could not create battle log file." << endl;
        return;
    }

    cout << "\nBattle Starting!" << endl;
    fprintf(battleLog, "Battle between %s and %s\n", player.name, enemy.name);
    showBattleStatus(player, enemy);

    // Comenzar la pelea controlada por el usuario
    battle(player, enemy, battleLog);

    // Cerrar el archivo de registro
    fclose(battleLog);
}
