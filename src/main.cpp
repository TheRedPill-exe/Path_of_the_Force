#include <iostream>
#include "Character.h"
#include <stdio.h>
#include <string>
#include "Display.h"
#include <cstdlib>
#include "Inventory.h"
#include "ProfileManager.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
    char profileName[50];
    readString("Enter the profile file name: ", profileName, sizeof(profileName));
    //createCharacter(profileName);
    //displayCharacter("darth_vader.bin");
    modifyCharacter(profileName, "queso");
    displayCustom(profileName);
    //char nameC[20] = {"darth vader"};
    //cout << nameC;
    //printCharac(nameC);
    
    
    
    system("pause");
    return 0;
}
