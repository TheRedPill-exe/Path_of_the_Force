#include <iostream>
#include <limits>
#include <filesystem>
#include <fstream>
#include <cstdio>  // Para FILE y fopen
#include <cstring> // Para manejar cadenas
#include <cctype>  // Para funciones de caracteres
#include "Character.h"
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
/*
void orderItems(char field[]){
    char filePath[100];
    replaceSpace(nameC);
    snprintf(filePath, sizeof(filePath), "../assets/data/items/%s.txt", nameC);
}
*/