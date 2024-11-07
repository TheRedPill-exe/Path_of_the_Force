#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include <string>

class Character {
public:
    std::string name;
    int health;
    int attackPower;
    int defense;

    Character(std::string name, int health, int attackPower, int defense)
        : name(name), health(health), attackPower(attackPower), defense(defense) {}
};

class Battle {
private:
    Character* character1;
    Character* character2;
    int turn;

public:
    Battle(Character* character1, Character* character2, int turn = 0)
        : character1(character1), character2(character2), turn(turn) {}

    void startBattle();
    void attack(Character& attacker, Character& defender);
    void calculateDamage(Character& attacker, Character& defender, int& damage);
    void displayBattleStatus();
};

void startBattle(Character* character1, Character* character2);

#endif // BATTLESYSTEM_H
