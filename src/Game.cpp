#include "game.h"
#include "Battlesystem.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void startGame() {
    string player1Name, player2Name;

    cout << "Enter the name of the first character: ";
    cin >> player1Name;
    cout << "Enter the name of the second character: ";
    cin >> player2Name;

    Character player1, player2;
    char filePath1[100], filePath2[100];

    snprintf(filePath1, sizeof(filePath1), "../assets/data/characters/%s.bin", player1Name.c_str());
    snprintf(filePath2, sizeof(filePath2), "../assets/data/characters/%s.bin", player2Name.c_str());

    FILE* file1 = fopen(filePath1, "rb");
    if (file1) {
        fread(&player1, sizeof(Character), 1, file1);
        fclose(file1);
    }

    FILE* file2 = fopen(filePath2, "rb");
    if (file2) {
        fread(&player2, sizeof(Character), 1, file2);
        fclose(file2);
    }

    startBattle(&player1, &player2);
}
