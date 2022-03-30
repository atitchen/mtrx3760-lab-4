// NandC_Game.h
//
// Class used to run and control noughts and crosses games.
//
// Author: Student 490476145 USYD

#ifndef _NANDC_GAME_H
#define _NANDC_GAME_H

#include "Enums.h"

class NandC_Player;

class NandC_Game
{   
    public:
        enum Symbol         // enum defining the types of possible symbols.
        {
        Blank,              // No Symbol.
        Cross,              // Cross Symbol.
        Nought              // Nought Symbol.
        };

        NandC_Game();                                   // CTOR: Runs when a new game is created.
        void Print_Board();                             // Prints the game board.
        void AddPlayer( NandC_Player* apPlayer );       // Adds a player to the game; the player knows their ID.
        int Run();                                      // Starts game of noughts and crosses.   
        bool CheckValid(int Move);                      // Checks move is valid.
        void Move(int WhoseTurn, int MovePosition);     // Applies players move.
        bool CheckFinished();                           // Checks if the game is finished.


    private:
        int _Board[3][3] = {0,0,0,0,0,0,0,0,0};         // The game board.
        NandC_Player* mpPlayers[2];                     // Pointers to the two players; starts empty; you must add players via AddPlayer().
        char Print_Symbol(int Symbol,int Coordinate);   // used to print the correct values to the game board.
        

};




#endif