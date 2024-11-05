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
    cout << "================== Path of the Force ==================" << endl;
    cout << "1. Create new character" << endl;
    cout << "2. Show character" << endl;
    cout << "3. Modify character" << endl;
    cout << "4. Delete character" << endl;
    cout << "5. View sorted items" << endl;
    cout << "6. View sorted skills" << endl;
    cout << "7. Exit" << endl;
    cout << "=======================================================" << endl;
    cout << "Select an option: ";
}

int main() {
    char profileName[50];
    bool running = true;

    while (running) {
        displayMainMenu();
        int choice;
        choice = readInt("", 1, 7);

        switch (choice) {
            case 1:
                cout << "Enter the profile filename: ";
                readString("", profileName, sizeof(profileName));
                createCharacter(profileName);
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
                        break;
                    case 2:
                        displayCustom(profileName);
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
            
            case 4: {
                cout << "Enter the name of the character to delete: ";
                cin >> profileName;
                cout << "Enter the key: "; // Prompt for password
                char deletePassword[20];
                cin >> deletePassword;
                deleteCharacter(profileName, deletePassword); // Pass the entered password
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
                        break;
                    case 2:
                        loadAndSortItems("item_", itemSize, "rarity");
                        break;
                    case 3:
                        loadAndSortItems("item_", itemSize, "name");
                        break;
                    case 4:
                        loadAndSortItems("item_", itemSize, "type");
                        break;
                    default:
                        loadAndSortItems("item_", itemSize, "name"); // Default to sorting by name
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
                        break;
                    case 2:
                        loadAndSortSkills("skill_", size, "cooldown");
                        break;
                    case 3:
                        loadAndSortSkills("skill_", size, "name");
                        break;
                    default:
                        loadAndSortSkills("skill_", size, "name"); 
                        break;
                }
                break;
            }
            case 7:
                cout << "Exiting the game... See you soon!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
