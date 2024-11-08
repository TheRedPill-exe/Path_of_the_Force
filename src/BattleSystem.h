#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H
#include "Character.h"

bool loadFightCharacter(Character& character, const char* name);

// Función para realizar el ataque del personaje
int attack(Character& attacker, Character& defender);

// Función para mostrar el estado de la batalla
void showBattleStatus(const Character& p1, const Character& p2);

// Función principal para manejar la pelea
void battle(Character& player, Character& enemy, FILE* battleLog);

// Función para iniciar la batalla entre dos personajes y registrar el historial
void startBattle(const char* character1Name, const char* character2Name, int battleNum);

#endif // BATTLESYSTEM_H
