#include <iostream>
#include "Character.h"
#include <stdio.h>
#include <string>
#include "Display.h"
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
    char profileName[50];
    readString("Enter the profile file name: ", profileName, sizeof(profileName));
    createCharacter(profileName);
    displayCharacter(profileName);
    displayCustom(profileName);
    //char nameC[20] = {"darth vader"};
    //cout << nameC;
    //printCharac(nameC);
    system("pause");
    return 0;
}
