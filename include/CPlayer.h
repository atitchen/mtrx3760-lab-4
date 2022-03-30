// CPlayer.h
// 
// Example solution for Lab 2 Polymorphic Dice Race
//
// This example puts all CPlayers (base class and derived) in one file
// For any more complicated example, you would want to split these out
// into separate files.
//
// Note the init process keeps a pointer to the game, to get info about
// markers. Then during operation no pointers need be passed about, e.g.
// to ChooseMove().
//
// Copyright (c) Donald Dansereau, 2021

#ifndef __CPLAYER_H
#define __CPLAYER_H

//--Includes---------------------------------------------
#include "CGame.h"

//-------------------------------------------------------
// Abstract base class for a player
class CPlayer
{
  public:

    CPlayer( CGame* apTheGame, int aID );     // CTOR: create a player who knows the game and has an ID
    virtual CGame::MoveType ChooseMove() = 0; // function to choose a move
    int GetID();                              // return this player's ID

  protected:
  
    CGame* mpTheGame;                         // keep a pointer to the game (knows-a)
    int mID;                                  // this player's ID, 0 or 1, corresponds to their marker ID
};

//-------------------------------------------------------
// Derived class, random player, selects move randomly
class CPlayerRand: public CPlayer
{
  public:
    CPlayerRand( CGame* apTheGame, int aID ); // CTOR: create a player who knows the game and has an ID
    CGame::MoveType ChooseMove();             // Define this player's way of choosing moves
};

//-------------------------------------------------------
// Derived class, charge player, always advances
class CPlayerCharge: public CPlayer
{
  public:
    CPlayerCharge( CGame* apTheGame, int aID ); // CTOR: create a player who knows the game and has an ID
    CGame::MoveType ChooseMove();               // Define this player's way of choosing moves
};

//-------------------------------------------------------
// Derived class, smart player, uses board state to decide
class CPlayerSmart: public CPlayer
{
  public:
    CPlayerSmart( CGame* apTheGame, int aID );  // CTOR: create a player who knows the game and has an ID
    CGame::MoveType ChooseMove();               // Define this player's way of choosing moves
};

class CPlayerHuman: public CPlayer
{
  public:
    CPlayerHuman( CGame* apTheGame, int aID ); // CTOR: create a player who knows the game and has an ID
    CGame::MoveType ChooseMove();               // Define this player's way of choosing moves
};

#endif
