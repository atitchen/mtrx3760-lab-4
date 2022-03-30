// NandC_Player.h
//
// Class used to make player decisions from either user input or computer logic.
//
// Author: Student 490476145 USYD


#ifndef _NANDC_PLAYER_H
#define _NANDC_PLAYER_H

#include "NandC_Game.h"



//-------------------------------------------------------
// Player Base Class
//
class NandC_Player
{
    public:

        NandC_Player( NandC_Game* apTheGame, int aID );     // CTOR: create a player who knows the game and has an ID
        virtual int ChooseMove() = 0;                       // function to choose a move
        int GetID();                                        // return this player's ID

    protected:

        NandC_Game* mpTheGame;              // keep a pointer to the game (knows-a)
        int mID;                            // this player's ID, 0 or 1, corresponds to their marker ID
        bool CheckMove(int Move);           // Used to check move is valid.

};

//-------------------------------------------------------
// Dirived Player Class, Human Player
//
class NandC_Human_Player: public NandC_Player
{
  public:
    NandC_Human_Player( NandC_Game* apTheGame, int aID );   // CTOR: create a player who knows the game and has an ID
    int ChooseMove();                                       // Define this player's way of choosing moves
};


//-------------------------------------------------------
// Dirived Player Class, Computer Player
//
class NandC_Computer_Player: public NandC_Player
{
  public:
    NandC_Computer_Player( NandC_Game* apTheGame, int aID );    // CTOR: create a player who knows the game and has an ID
    int ChooseMove();                                           // Define this player's way of choosing moves
};

#endif