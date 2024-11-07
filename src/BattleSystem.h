#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

// Estructura básica para los personajes de pelea
struct FightCharacter {
    char name[30];
    int health;
    int attack;
    int defense;
};

// Función para cargar un personaje de pelea desde un archivo
bool loadFightCharacter(FightCharacter& character, const char* name);

// Función para realizar el ataque del personaje
int attack(FightCharacter& attacker, FightCharacter& defender);

// Función para mostrar el estado de la batalla
void showBattleStatus(const FightCharacter& p1, const FightCharacter& p2);

// Función principal para manejar la pelea
void battle(FightCharacter& p1, FightCharacter& p2);

// Función para iniciar la batalla entre dos personajes
void startBattle(const char* character1Name, const char* character2Name);

#endif // BATTLESYSTEM_H
