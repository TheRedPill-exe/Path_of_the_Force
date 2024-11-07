#include "Battlesystem.h"
#include <iostream>
#include <chrono>  // Para el manejo del tiempo
#include <thread>  // Para usar std::this_thread::sleep_for

using namespace std;

void Battle::startBattle() {
    cout << "Battle has started!" << endl;
    while (character1->health > 0 && character2->health > 0) {
        displayBattleStatus();
        if (turn % 2 == 0) {
            cout << character1->name << " attacks!" << endl;
            attack(*character1, *character2);
        } else {
            cout << character2->name << " attacks!" << endl;
            attack(*character2, *character1);
        }
        turn++;
        
        // Reemplazamos usleep() con std::this_thread::sleep_for
        this_thread::sleep_for(chrono::seconds(1));  // Espera 1 segundo entre turnos
    }

    if (character1->health <= 0) {
        cout << character2->name << " wins the battle!" << endl;
    } else {
        cout << character1->name << " wins the battle!" << endl;
    }
}

void Battle::attack(Character& attacker, Character& defender) {
    int damage = 0;
    calculateDamage(attacker, defender, damage);
    defender.health -= damage;
    cout << attacker.name << " deals " << damage << " damage to " << defender.name << "!" << endl;
}

void Battle::calculateDamage(Character& attacker, Character& defender, int& damage) {
    damage = attacker.attackPower - defender.defense;
    if (damage < 0) damage = 0;  // No puede ser daño negativo
}

void Battle::displayBattleStatus() {
    cout << "---------------------------" << endl;
    cout << character1->name << " HP: " << character1->health << " | "
         << character2->name << " HP: " << character2->health << endl;
    cout << "---------------------------" << endl;
}

void startBattle(Character* character1, Character* character2) {
    Battle battle = {character1, character2, 0};
    battle.startBattle();
}
