#include <iostream>
#include <cstdio>
#include <cstring>
#include "Character.h"

using namespace std;

void saveItemToFile(const Item& item, const char* fileName) {
    FILE* file = fopen(fileName, "wb");
    if (file) {
        fwrite(&item, sizeof(Item), 1, file);
        fclose(file);
        cout << "Item saved to " << fileName << endl;
    } else {
        cout << "Error opening file: " << fileName << endl;
    }
}

int main() {
    Item items[51] = {
        {"Lightsaber", "Weapon", 10, "Rare", "A Jedi's weapon"},
        {"Armor", "Armor", 5, "Common", "Protective gear"},
        {"Medpack", "Healing", 20, "Uncommon", "Restores health"},
        {"Blaster", "Weapon", 8, "Uncommon", "Standard blaster pistol"},
        {"Force Crystal", "Artifact", 15, "Legendary", "Enhances Force powers"},
        {"Stun Grenade", "Grenade", 7, "Common", "Temporarily incapacitates"},
        {"Thermal Detonator", "Grenade", 12, "Rare", "Explosive device"},
        {"Holo Projector", "Gadget", 5, "Common", "Creates holographic images"},
        {"Jetpack", "Gadget", 20, "Rare", "Allows short flights"},
        {"Droid Repair Kit", "Gadget", 6, "Uncommon", "Repairs droids"},
        {"Sonic Blaster", "Weapon", 10, "Rare", "Fires sonic blasts"},
        {"Force Shield", "Armor", 18, "Legendary", "Protects against Force attacks"},
        {"Healing Potion", "Healing", 15, "Common", "Restores health instantly"},
        {"Grappling Hook", "Gadget", 5, "Common", "Allows climbing to high places"},
        {"Comlink", "Gadget", 2, "Common", "Used for communication"},
        {"Droid Control Device", "Gadget", 8, "Uncommon", "Controls droids remotely"},
        {"Bounty Hunter Visor", "Gadget", 6, "Rare", "Enhances targeting capabilities"},
        {"Force Amplifier", "Artifact", 25, "Legendary", "Boosts Force abilities"},
        {"Thermal Scanners", "Gadget", 9, "Rare", "Detects heat signatures"},
        {"Combat Suit", "Armor", 10, "Rare", "Armor for combat situations"},
        {"Holo Map", "Gadget", 5, "Common", "Displays the surroundings in hologram"},
        {"Disguise Kit", "Gadget", 4, "Uncommon", "Helps in disguising"},
        {"Tranquilizer Dart", "Ammunition", 3, "Common", "Darts that put enemies to sleep"},
        {"Flashlight", "Gadget", 2, "Common", "Provides light in dark areas"},
        {"Vibroblade", "Weapon", 7, "Uncommon", "A blade with vibro technology"},
        {"Sith Holocron", "Artifact", 20, "Legendary", "Contains Sith knowledge"},
        {"Force Cloak", "Armor", 15, "Rare", "Makes the wearer invisible to the Force"},
        {"Ion Cannon", "Weapon", 30, "Legendary", "Fires ionized energy"},
        {"Smoke Bomb", "Grenade", 5, "Common", "Creates a smoke screen"},
        {"Energy Shield", "Armor", 25, "Legendary", "Absorbs energy attacks"},
        {"Magnetic Boots", "Gadget", 10, "Rare", "Allows walking on metal surfaces"},
        {"Pulse Grenade", "Grenade", 12, "Rare", "Creates a powerful shockwave"},
        {"HoloNet Communicator", "Gadget", 10, "Uncommon", "For long-distance communication"},
        {"Stun Baton", "Weapon", 9, "Common", "Non-lethal weapon"},
        {"Medkit", "Healing", 20, "Rare", "Advanced medical supplies"},
        {"Plasma Rifle", "Weapon", 15, "Legendary", "High-tech plasma weapon"},
        {"Shield Generator", "Gadget", 25, "Legendary", "Creates a protective shield"},
        {"Cryo Grenade", "Grenade", 12, "Rare", "Freezes targets temporarily"},
        {"Life Detector", "Gadget", 8, "Uncommon", "Detects life forms"},
        {"Battle Droid", "Companion", 10, "Common", "Fights alongside the user"},
        {"Ration Pack", "Food", 5, "Common", "Provides sustenance"},
        {"Compressor", "Gadget", 7, "Rare", "Compresses items for storage"},
        {"Sonic Mine", "Weapon", 15, "Rare", "Triggers a sonic explosion"},
        {"Energy Cell", "Power Source", 10, "Common", "Power for gadgets"},
        {"Cryo Stasis Chamber", "Gadget", 30, "Legendary", "Preserves life in stasis"},
        {"Interstellar Map", "Gadget", 12, "Rare", "Shows star systems and routes"},
        {"Tracking Device", "Gadget", 10, "Uncommon", "Tracks targets"},
        {"Tactical Visor", "Gadget", 10, "Rare", "Enhances vision in combat"},
        {"Prototype Armor", "Armor", 30, "Legendary", "Advanced protective gear"},
        {"Anti-Gravity Boots", "Gadget", 15, "Legendary", "Allows floating"},
        {"Repulsor Ray", "Weapon", 25, "Legendary", "Repels objects and enemies"}
    };

    // Guardamos cada item en un archivo binario.
    for (int i = 0; i < 51; i++) {
        char fileName[70];
        sprintf(fileName, "../assets/data/items/item_%02d.bin", i + 1);
        saveItemToFile(items[i], fileName);
    }

    return 0;
}