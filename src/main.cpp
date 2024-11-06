#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <locale>
#include <codecvt>
#include "Utilities.h"
#include "Character.h"
#include "Display.h"
#include "Inventory.h"
#include "ProfileManager.h"

using namespace std;

void displayMainMenu() {
    setlocale(LC_ALL, "");
    cout << "================== Path of the Force ==================" << endl;
    cout << "1. Create new character" << endl;
    cout << "2. Show character" << endl;
    cout << "3. Modify character" << endl;
    cout << "4. Delete character" << endl;
    cout << "5. View sorted items" << endl;
    cout << "6. View sorted skills" << endl;
    cout << "7. View ordered characters (default ones)" << endl;
    cout << "8. Exit" << endl;
    cout << "=======================================================" << endl;
    cout << "Select an option: ";
}

int main() {
    char profileName[50];
    bool running = true;
    int sizech = 10;
    char nameC[50] = "logo";
    printCharac(nameC);
    while (running) {
        displayMainMenu();
        int choice;
        choice = readInt("", 1, 7);

        switch (choice) {
            case 1:
                cout << "Enter the profile filename: ";
                readString("", profileName, sizeof(profileName));
                createCharacter(profileName);
                clearConsole();
                break;
            case 2:
                int displayChoice;
                cout << "Enter the option to show: \n1 For default characters.\n2 For custom characters:\n";
                displayChoice = readInt("", 1, 2);
                cout << "Enter the name of the character to display: ";
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
                cin >> profileName;
                cout << "Enter the password: "; // Prompt for password
                char password[20];
                cin >> password;
                modifyCharacter(profileName, password); // Pass the entered password
                break;
            case 3:
                
            case 4: {
                cout << "Enter the name of the character to delete: ";
                cin >> profileName;
                cout << "Enter the key: "; // Prompt for password
                char deletePassword[20];
                cin >> deletePassword;
                deleteCharacter(profileName, deletePassword); // Pass the entered password
                system("pause");
                clearConsole();
                break;
            }
            case 5: {
                int itemSize = 20;
                int itemOption = 0;
                cout << "How would you like to sort the items?\n1. Effect\n2. Rarity\n3. Name\n4. Type\nSelect an option: ";
                cin >> itemOption;
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
                cin >> option;
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
