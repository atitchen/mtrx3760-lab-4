// Main.cpp
//
// Author: Student 490476145 USYD

#include <stdlib.h>

#include "Games_Arcade.h"

int main()
{
    srand(4322);
    
    // Creates Game Arcade and opens the menu.
    CGames_Arcade gamesArcade = CGames_Arcade();
    gamesArcade.menu();
  
    return 0;
} 
