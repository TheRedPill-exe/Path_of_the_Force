#include <iostream>
#include <limits>
#include <filesystem>
#include <fstream>
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include <cctype>  // Para funciones de caracteres
#include "Character.h"
#include "Inventory.h"
#include <cstdlib> 
using namespace std;

int readInt(const char* prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
            cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer despu�s de una entrada v�lida
            return value;
        }
    }
}
void readString(const char* prompt, char* buffer, size_t size) {
    while (true) {
        cout << prompt;
        cin.getline(buffer, size);

        // Check if the input is empty or contains only whitespace
        bool isEmptyOrWhitespace = true;
        for (size_t i = 0; i < strlen(buffer); i++) {
            if (!isspace(buffer[i])) {
                isEmptyOrWhitespace = false; // Found a non-whitespace character
                break;
            }
        }

        if (isEmptyOrWhitespace) { // If the string is empty or just whitespace
            cout << "Input cannot be empty or whitespace. Please enter a valid input." << endl;
        } else if (cin.fail()) { // Check for input failure
            cin.clear(); // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Input error. Please try again." << endl;
        } else {
            break; // Exit the loop if the input is valid
        }
    }
}


void replaceSpace(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            str[i] = '_'; 
        }
    }
}

bool isName(char nameC[]) {
    char filePath[100];
    replaceSpace(nameC);
    snprintf(filePath, sizeof(filePath), "../assets/ascii_art/characters/%s.txt", nameC);
    ifstream file(filePath);
    if (!file) {
        cout << "Error: Could not open file " << filePath << endl;
        return false;
    }
    return true; 
} 

void clearConsole() {
    #ifdef _WIN32
        system("CLS");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux y macOS
    #endif
}
