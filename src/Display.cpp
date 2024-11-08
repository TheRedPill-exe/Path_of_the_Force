#include <iostream>
#include "Character.h"
#include "Utilities.h"
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include "ProfileManager.h"
#include <iomanip>
#include <fstream>
#include <thread>       // Para sleep_for
#include <chrono>       

using namespace std;

void printCharac(char nameC[]) {
    if (isName(nameC)) {
        replaceSpace(nameC);
        
        // Construye la ruta del archivo usando el nombre del personaje
        char filePath[100];
        snprintf(filePath, sizeof(filePath), "../assets/ascii_art/characters/%s.txt", nameC);
        
        // Abre el archivo usando fopen
        FILE* user = fopen(filePath, "r"); // Abre el archivo en modo lectura
        if (!user) {
            //cout << "Error: Unable to open file." << endl;
            return;
        }

        char line[256];
        // Lee y muestra el contenido del archivo
        while (fgets(line, sizeof(line), user)) {
            cout << line; // Imprime cada línea leída
        }
        fclose(user); // Cierra el archivo
    }
}

void displayCharacter(char* profileName) {
    Character characterP;
    char filePath[100];

    replaceSpace(profileName);
	snprintf(filePath, sizeof(filePath), "../assets/data/characters/%s.bin", profileName);
    printCharac(profileName);
    
    FILE* user = fopen(filePath, "rb");

    if (user == NULL) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    fread(&characterP, sizeof(Character), 1, user);
    fclose(user);

    cout << "Character Information:" << endl;
    cout << "Name: " << characterP.name << endl;
    cout << "Species: " << characterP.species << endl;
    cout << "Faction: " << characterP.faction << endl;
    cout << "Health: " << characterP.health << endl;
    cout << "Strength: " << characterP.strength << endl;
    cout << "Agility: " << characterP.agility << endl;
    cout << "Intelligence: " << characterP.intelligence << endl;
    cout << "Attack Power: " << characterP.attackPower << endl;
    cout << "Defense: " << characterP.defense << endl;

    cout << "\nSkills:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Skill " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.skills[i].name << endl;
        cout << "    Description: " << characterP.skills[i].description << endl;
        cout << "    Level: " << characterP.skills[i].level << endl;
        cout << "    Cooldown: " << characterP.skills[i].cooldown << endl;
        cout << "    Mana Cost: " << characterP.skills[i].manaCost << endl;
    }

    cout << "\nItems:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Item " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.items[i].name << endl;
        cout << "    Type: " << characterP.items[i].type << endl;
        cout << "    Effect: " << characterP.items[i].effect << endl;
        cout << "    Rarity: " << characterP.items[i].rarity << endl;
        cout << "    Description: " << characterP.items[i].description << endl;
    }
}

void displayCustom(char* profileName) {
    Character characterP;
    char filePath[50];
    snprintf(filePath, sizeof(filePath), "../users/%s", profileName);

    FILE* user = fopen(filePath, "rb");

    if (user == NULL) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    fread(&characterP, sizeof(Character), 1, user);
    fclose(user);

    // Pide la palabra clave para desencriptar
    char keyword[10];
    cout << "Enter the keyword to decrypt the character information: ";
    readString("", keyword, 10);

    // Desencriptar los campos de texto del personaje
    decrypt(characterP.name, keyword);
    decrypt(characterP.species, keyword);
    decrypt(characterP.faction, keyword);
    for (int i = 0; i < 3; i++) {
        decrypt(characterP.skills[i].name, keyword);
        decrypt(characterP.skills[i].description, keyword);
    }
    for (int i = 0; i < 3; i++) {
        decrypt(characterP.items[i].name, keyword);
        decrypt(characterP.items[i].type, keyword);
        decrypt(characterP.items[i].rarity, keyword);
        decrypt(characterP.items[i].description, keyword);
    }

    // Mostrar la información del personaje
    cout << "Character Information:" << endl;
    cout << "Name: " << characterP.name << endl;
    cout << "Species: " << characterP.species << endl;
    cout << "Faction: " << characterP.faction << endl;
    cout << "Health: " << characterP.health << endl;
    cout << "Strength: " << characterP.strength << endl;
    cout << "Agility: " << characterP.agility << endl;
    cout << "Intelligence: " << characterP.intelligence << endl;
    cout << "Attack Power: " << characterP.attackPower << endl;
    cout << "Defense: " << characterP.defense << endl;

    cout << "\nSkills:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Skill " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.skills[i].name << endl;
        cout << "    Description: " << characterP.skills[i].description << endl;
        cout << "    Level: " << characterP.skills[i].level << endl;
        cout << "    Cooldown: " << characterP.skills[i].cooldown << endl;
        cout << "    Mana Cost: " << characterP.skills[i].manaCost << endl;
    }

    cout << "\nItems:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Item " << (i + 1) << ":" << endl;
        cout << "    Name: " << characterP.items[i].name << endl;
        cout << "    Type: " << characterP.items[i].type << endl;
        cout << "    Effect: " << characterP.items[i].effect << endl;
        cout << "    Rarity: " << characterP.items[i].rarity << endl;
        cout << "    Description: " << characterP.items[i].description << endl;
    }
}


void displayItems(const Item* items, int size) {
    cout << "Items sorted:\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "| Name                       | Type           | Effect | Rarity       |\n";
    cout << "----------------------------------------------------------------------\n";
    
    for (int i = 0; i < size; i++) {
        cout << "| " << left << setw(27) << items[i].name 
             << "| " << left << setw(15) << items[i].type   
             << "| " << right << setw(7) << items[i].effect 
             << "| " << left << setw(11) << items[i].rarity << " |\n";
    }
    
    cout << "---------------------------------------------------------------------\n";
    cout << "Descriptions:\n";
    for (int i = 0; i < size; i++) {
        cout << "Item " << (i + 1) << ": " << items[i].description << endl;
    }
}

void displaySkills(const Skill* skills, int size) {
    cout << "Skills:\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "| Name                       | Level   | Cooldown   | Mana Cost    |\n";
    cout << "-------------------------------------------------------------------\n";
    
    for (int i = 0; i < size; i++) {
        cout << "| " << left << setw(27) << skills[i].name 
             << "| " << right << setw(8) << skills[i].level 
             << "| " << right << setw(11) << skills[i].cooldown 
             << "| " << right << setw(12) << skills[i].manaCost << " |\n";
    }
    
    cout << "-------------------------------------------------------------------\n";
    cout << "Descriptions:\n";
    for (int i = 0; i < size; i++) {
        cout << "Skill " << (i + 1) << ": " << skills[i].description << endl;
    }
}


void displayCharacters(const Character* characters, int size) {
    cout << "Characters:\n";
    cout << "----------------------------------------------------------------\n";
    cout << "| Name                     | Species       | Faction            |\n";
    cout << "----------------------------------------------------------------\n";
    
    for (int i = 0; i < size; i++) {
        // Si el personaje tiene salud 0, se salta a la siguiente iteración
        if (characters[i].health == 0) {
            continue;
        }

        cout << "| " << left << setw(27) << characters[i].name 
             << "| " << left << setw(15) << characters[i].species 
             << "| " << left << setw(15) << characters[i].faction << " |\n";
    }
    
    cout << "--------------------------------------------------------------\n";
    cout << "Detailed Information:\n";
    for (int i = 0; i < size; i++) {
        // Si el personaje tiene salud 0, se salta a la siguiente iteración
        if (characters[i].health == 0) {
            continue;
        }

        cout << "Character " << (i + 1) << ":\n";
        cout << " - Name: " << characters[i].name << endl;
        cout << " - Health: " << characters[i].health << endl;
        cout << " - Strength: " << characters[i].strength << endl;
        cout << " - Agility: " << characters[i].agility << endl;
        cout << " - Intelligence: " << characters[i].intelligence << endl;
        cout << " - Attack Power: " << characters[i].attackPower << endl;
        cout << " - Defense: " << characters[i].defense << endl;
        
        cout << " - Skills:\n";
        for (int j = 0; j < 3; j++) {
            cout << "   * " << characters[i].skills[j].name << " (Level: " << characters[i].skills[j].level << ")\n";
        }
        
        cout << " - Items:\n";
        for (int j = 0; j < 3; j++) {
            cout << "   * " << characters[i].items[j].name << "\n";
        }
        cout << "--------------------------------------------------------------\n";
    }
}

void displayFileWithOffset(const char filename[]) {
    char filePath[60];
    snprintf(filePath, sizeof(filePath), "../assets/ascii_art/characters/%s.txt", filename);

    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filePath << endl;
        return;
    }

    string line;
    size_t max_offset = 0;
    
    // Determinar la longitud máxima de una línea en el archivo
    while (getline(file, line)) {
        if (line.length() > max_offset) {
            max_offset = line.length();
        }
    }

    // Reiniciar el archivo al inicio
    file.clear();
    file.seekg(0, ios::beg);
    // Mostrar el archivo desplazando cada línea hacia la izquierda
    for (size_t offset = 0; offset <= max_offset; ++offset) {
        clearConsole();  // Limpiar la consola antes de mostrar el siguiente desplazamiento
        file.clear();
        file.seekg(0, ios::beg);

        while (getline(file, line)) {
            if (offset < line.length()) {
                cout << line.substr(offset) << endl;
            } else {
                cout << endl;
            }
        }

        // Añadir un pequeño retraso para hacer que el efecto de desplazamiento sea visible
        this_thread::sleep_for(chrono::milliseconds(90-offset*2));
    }

    file.close();
}
void playAudio(const string& filename) {
    #ifdef _WIN32
        // En Windows, usa PowerShell para reproducir el audio en segundo plano sin abrir ventana
        string command = "powershell -Command (New-Object Media.SoundPlayer \"" + filename + "\").PlaySync();";
    #elif __APPLE__
        // En macOS, usa `afplay` en segundo plano
        string command = "afplay " + filename + " &";
    #elif __linux__
        // En Linux, intenta `aplay` para .wav o `mpg123` para .mp3, en segundo plano
        string command = "aplay " + filename + " &" + " || mpg123 " + filename + " &";
    #else
        cerr << "Sistema operativo no compatible para reproducir audio." << std::endl;
        return;
    #endif

    // Ejecutar el comando para reproducir el audio en segundo plano
    if (system(command.c_str()) != 0) {
        cerr << "Error: no se pudo reproducir el archivo de audio: " << filename << std::endl;
    }
}

