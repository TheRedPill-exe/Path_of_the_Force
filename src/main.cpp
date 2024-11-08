/*
Realizar con manejo de archivos un micro proyecto que contenga  
definición de estructuras de registro, el cual debe ser usado para 
Crear, guardar, borrar, actualizar, consultar y Ordenar,  
a través de manejo de menús  y las funciones asociadas, 
como se han visto a lo largo de los diferentes ejemplos presentados,  
los archivos pueden ser de texto o binarios; y con cualquier librería para este tipo de programas. 

Adicionar en un archivo de texto: explicación del manejo y el 
tema desarrollado, además de permitir o NO, que otros vean su código y lo mejoren. */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <locale>
#include <codecvt>
#include <thread>
#include "Utilities.h"
#include "Character.h"
#include "Display.h"
#include "Inventory.h"
#include "ProfileManager.h"
#include "Battlesystem.h"

using namespace std;

void displayMainMenu() {
    setlocale(LC_ALL, "");
    cout << "========================== Path of the Force ==========================" << endl;
    cout << "   1. Create new character" << endl;
    cout << "   2. Show character" << endl;
    cout << "   3. Modify character" << endl;
    cout << "   4. Delete character" << endl;
    cout << "   5. View sorted items" << endl;
    cout << "   6. View sorted skills" << endl;
    cout << "   7. View ordered characters (default ones) " << endl;
    cout << "   8. Start battle" << endl;
    cout << "   9. Exit" << endl;
    cout << "=======================================================================" << endl;
    cout << "Select an option: ";
}

int main() {
    int battleNum = 1;
    char profileName[50];
    bool running = true;
    int sizech = 10;
    char nameC[50] = "logo";
    //std::thread audioThread(playAudio, "../assets/starwars.wav");
    displayFileWithOffset("nave");
    while (running) {
        printCharac(nameC);
        displayMainMenu();
        int choice;
        choice = readInt("", 1, 9);

        switch (choice) {
            case 1:
                cout << "Enter the profile filename: ";
                readString("", profileName, sizeof(profileName));
                createCharacter(profileName);
                system("pause");
                clearConsole();
                break;
            case 2:
                int displayChoice;
                cout << "Enter the option to show: \n1 For default characters.\n2 For custom characters:\n";
                displayChoice = readInt("", 1, 2);
                cout << "Enter the name of the character (or profile) to display: ";
                readString("", profileName, sizeof(profileName));
                switch (displayChoice) {
                    case 1:
                        displayCharacter(profileName);
                        system("pause");
                        clearConsole();
                        break;
                    case 2:
                        displayCustom(profileName);
                        system("pause");
                        clearConsole();
                        break;
                    default:
                        cout << "Invalid option. Please try again." << endl;
                }

                break;
                cout << "Enter the name of the character to modify: ";
                readString("", profileName, sizeof(profileName));
                cout << "Enter the password: "; // Prompt for password
                char password[20];
                readString("", password, sizeof(password));
                modifyCharacter(profileName, password); // Pass the entered password
                break;
            case 3:
                cout << "Enter the name of the character to modify: ";
                readString("", profileName, sizeof(profileName));
                cout << "Enter the keyword: "; // Prompt for password
                char keyc[20];
                readString("", keyc, sizeof(keyc));
                modifyCharacter(profileName, password); // Pass the entered password
                system("pause");
                clearConsole();
                break;
            case 4: {
                cout << "Enter the name of the character to delete: ";
                readString("", profileName, sizeof(profileName));
                cout << "Enter the key: "; // Prompt for password
                char deletePassword[20];
                readString("", deletePassword, sizeof(deletePassword));
                deleteCharacter(profileName, deletePassword); // Pass the entered password
                system("pause");
                clearConsole();
                break;
            }
            case 5: {
                int itemSize = 20;
                int itemOption = 0;
                cout << "How would you like to sort the items?\n1. Effect\n2. Rarity\n3. Name\n4. Type\nSelect an option: ";
                itemOption = readInt("", 1, 4);
                cout << "Enter the number of items to sort: ";
                itemSize = readInt("", 1, 50);
                switch (itemOption) {
                    case 1:
                        loadAndSortItems("item_", itemSize, "effect");
                        system("pause");
                        clearConsole();
                        break;
                    case 2:
                        loadAndSortItems("item_", itemSize, "rarity");
                        system("pause");
                        clearConsole();
                        break;
                    case 3:
                        loadAndSortItems("item_", itemSize, "name");
                        system("pause");
                        clearConsole();
                        break;
                    case 4:
                        loadAndSortItems("item_", itemSize, "type");
                        system("pause");
                        clearConsole();
                        break;
                    default:
                        loadAndSortItems("item_", itemSize, "name"); // Default to sorting by name
                        system("pause");
                        clearConsole();
                        break;
                }
                break;
            }
            case 6: {
                int size = 20;
                int option = 0;
                cout << "How would you like to sort the skills?\n1. Level\n2. Cooldown\n3. Name\nSelect an option: ";
                option = readInt("", 1, 3);
                cout << "Enter the number of skills to sort: ";
                size = readInt("", 1, 50);

                switch (option) {
                    case 1:
                        loadAndSortSkills("skill_", size, "level");
                        system("pause");
                        clearConsole();
                        break;
                    case 2:
                        loadAndSortSkills("skill_", size, "cooldown");
                        system("pause");
                        clearConsole();
                        break;
                    case 3:
                        loadAndSortSkills("skill_", size, "name");
                        system("pause");
                        clearConsole();
                        break;
                    default:
                        loadAndSortSkills("skill_", size, "name");
                        system("pause");
                        clearConsole(); 
                        break;
                }
                break;
            }
            case 7:
                sizech = readInt("Enter the number of characters to sort: ", 1, 39);
                loadAndSortCharacters(sizech, "name");
                system("pause");
                clearConsole();
                break;
            case 8:
                cout << "Enter the name of the first character (you): ";
                readString("", profileName, sizeof(profileName));
                Character character1;
                replaceSpace(profileName);
                readCharacterFromFile(character1, profileName);
                cout << "Enter the name of the second character (AI): ";
                readString("", profileName, sizeof(profileName));
                Character character2;
                replaceSpace(profileName);
                readCharacterFromFile(character2, profileName);
                cout << "Starting battle between characters!" << endl;
                startBattle(character1.name, character2.name, battleNum);  // Iniciar la batalla
                battleNum++;
                system("pause");
                clearConsole();
                break;
            case 9:
                cout << "Exiting the game... See you soon!" << endl;
                running = false;
                clearConsole();
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
