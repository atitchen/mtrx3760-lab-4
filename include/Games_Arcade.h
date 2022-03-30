// Games_Arcade.h
//
// Class used to setup games via a menu system.
//
// Author: Student 490476145 USYD

#ifndef _GAMES_ARCADE_H
#define _GAMES_ARCADE_H

#include "Enums.h"


class CGames_Arcade
{

    public:

    void menu();            // Opens the user menu.
    void WaitForEnter();    // Halts program until player presses enter.
    
    void DiceRaceMenu();            // Opens the Dice Race menu.
    void NoughtsCrossesMenu();      // Opens the Noughts and Crosses menu.

};


#endif