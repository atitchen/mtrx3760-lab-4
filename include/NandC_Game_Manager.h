// NandC_Game_Manager.h
//
// Class used to setup noughts and crosses games.
//
// Author: Student 490476145 USYD


#ifndef _NANDC_GAME_MANAGER_H
#define _NANDC_GAME_MANAGER_H

#include "Enums.h"
#include "NandC_Game.h"

class NandC_Game_Manager
{
    public:
        void MakeGame(PlayerType p1, PlayerType p2);  // Creates and starts a game.
    
    private:
        NandC_Game Game;    // Stores the current game.

};


#endif