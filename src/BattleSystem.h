#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H
#include "Character.h"

bool loadFightCharacter(Character& character, const char* name);

int attack(Character& attacker, Character& defender);

void showBattleStatus(const Character& p1, const Character& p2);

void battle(Character& player, Character& enemy, FILE* battleLog);

void startBattle(const char* character1Name, const char* character2Name, int battleNum);

#endif // BATTLESYSTEM_H
