#include <iostream>
#include <limits>
#include <filesystem>
#include <fstream>
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include <cctype>  // Para funciones de caracteres
#include "Character.h"
#include "Inventory.h"

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

// Funci�n para leer cadenas con validaci�n
void readString(const char* prompt, char* buffer, size_t size) {
    while (true) {
        cout << prompt;
        cin.getline(buffer, size);

        if (buffer[0] == '\0') { // Verificar si la cadena est� vac�a
            cout << "Input cannot be empty. Please enter a valid input." << endl;
        } else {
            break; // Salir del ciclo si la entrada es v�lida
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
bool selectOrCreate(char prompt[], char filePath[], char fileName[], char fileType[]) {
    char option;
    cout << prompt;
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
    if (option == 's' || option == 'S') {
        cout << "Skills to choose:";
        
        loadAndSortSkills("skill_", 40, "name");  
        cout << "Enter the name of the " << fileName << " you want to select: ";
        readString("", filePath, 100);
        return true;
    } else if (option == 'c' || option == 'C') {
        cout << "Enter the name of the new " << fileName << ": ";
        readString("", filePath, 100);
        strcat(filePath, fileType);
        return false;
    } else {
        cout << "Invalid option. Please enter 's' to select an existing " << fileName << " or 'c' to create a new one." << endl;
        return selectOrCreate(prompt, filePath, fileName, fileType);
    }
}