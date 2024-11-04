#include <iostream>
#include "Character.h"
#include <iostream>
#include <stdio.h>
#include <limits>
#include <iostream>
#include <vector>
#include <string>
#include "Display.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
    char profileName[50];
    readString("Enter the profile file name: ", profileName, sizeof(profileName));
    createCharacter(profileName);
    displayCharacter(profileName);
    return 0;
}
