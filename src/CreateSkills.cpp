#include <iostream>
#include <cstdio>
#include <cstring>
#include "Character.h"

using namespace std;


void saveSkillToFile(const Skill& skill, const char* fileName) {
    FILE* file = fopen(fileName, "wb");
    if (file) {
        fwrite(&skill, sizeof(Skill), 1, file);
        fclose(file);
        cout << "Skill saved to " << fileName << endl;
    } else {
        cout << "Error opening file: " << fileName << endl;
    }
}

int main() {
    Skill skills[48] = {
        {"Force Push", "Pushes enemies away", 1, 10, 5},
        {"Healing Light", "Restores health over time", 1, 20, 10},
        {"Mind Trick", "Confuses enemies", 2, 15, 8},
        {"Force Shield", "Protects against attacks", 3, 25, 15},
        {"Saber Mastery", "Increases lightsaber damage", 4, 30, 20},
        {"Stealth", "Becomes invisible for a short time", 2, 10, 5},
        {"Speed Burst", "Increases movement speed", 3, 20, 8},
        {"Telepathy", "Communicates with allies", 1, 5, 2},
        {"Lightning Strike", "Deals lightning damage", 4, 35, 25},
        {"Force Leap", "Jumps to a target location", 3, 15, 10},
        {"Force Grip", "Holds an enemy in place", 2, 30, 20},
        {"Blinding Light", "Temporarily blinds enemies", 3, 20, 15},
        {"Force Sense", "Increases awareness of surroundings", 1, 5, 1},
        {"Energy Drain", "Drains energy from enemies", 4, 25, 18},
        {"Healing Wave", "Restores a large amount of health", 5, 40, 30},
        {"Force Wave", "Creates a shockwave that knocks back enemies", 3, 30, 20},
        {"Force Cloak", "Makes the user invisible", 2, 10, 5},
        {"Combat Reflexes", "Increases defense for a short time", 3, 15, 12},
        {"Sonic Blast", "Sends out a sonic wave that stuns enemies", 4, 20, 18},
        {"Barrier", "Creates a barrier that absorbs damage", 4, 35, 25},
        {"Speed of the Force", "Doubles movement speed for a short time", 5, 20, 15},
        {"Invisibility", "Grants temporary invisibility", 3, 15, 10},
        {"Force Teleport", "Teleports the user to a nearby location", 4, 30, 20},
        {"Energy Shield", "Absorbs damage for a limited time", 5, 40, 30},
        {"Enhanced Vision", "Improves vision in low-light conditions", 2, 5, 3},
        {"Disarm", "Disarms an enemy", 3, 25, 12},
        {"Force Empathy", "Reads the emotions of others", 2, 10, 8},
        {"Power Surge", "Increases attack power temporarily", 3, 30, 15},
        {"Elemental Manipulation", "Controls elements for offense", 4, 35, 20},
        {"Battle Meditation", "Enhances allies' performance", 4, 10, 8},
        {"Teleport Strike", "Teleports behind an enemy for a strike", 3, 20, 12},
        {"Saber Throw", "Throws the lightsaber at an enemy", 3, 25, 15},
        {"Force Reflection", "Reflects projectiles", 4, 30, 18},
        {"Barrier Break", "Destroys barriers", 5, 40, 25},
        {"Shadow Step", "Quickly moves behind an enemy", 3, 15, 10},
        {"Panic Attack", "Causes fear in enemies", 2, 20, 8},
        {"Chain Lightning", "Strikes multiple enemies with lightning", 4, 35, 25},
        {"Astral Projection", "Explores the surroundings spiritually", 5, 10, 5},
        {"Tremor", "Causes the ground to shake, knocking enemies down", 3, 20, 12},
        {"Force Drain", "Drains life from enemies to heal allies", 4, 25, 18},
        {"Mind Shield", "Protects against mental attacks", 3, 15, 10},
        {"Hologram", "Creates a holographic decoy", 2, 5, 3},
        {"Quick Recovery", "Increases recovery speed after combat", 1, 10, 5},
        {"Adrenaline Rush", "Temporarily boosts speed and power", 4, 20, 15},
        {"Blizzard", "Summons a snowstorm to damage enemies", 4, 35, 25},
        {"Phoenix Rebirth", "Revives allies with full health", 5, 40, 30},
        {"Mind Control", "Controls an enemy's actions", 5, 30, 20},
        {"Thunderclap", "Creates a thunderous sound that stuns enemies", 3, 25, 12}
    };

    // Guardamos cada habilidad en un archivo binario con su nombre.
    for (int i = 0; i < 48; i++) {
        char fileName[100];
        // Generar el nombre del archivo usando el nombre de la habilidad
        sprintf(fileName, "../assets/data/skills/skill_%02d.bin", i+1);
        saveSkillToFile(skills[i], fileName);
    }

    return 0;
}
