// CGame.h
// 
// Example solution for Lab 2 Polymorphic Dice Race
//
// Copyright (c) Donald Dansereau, 2021

#ifndef __CGAME_H
#define __CGAME_H


//--Includes---------------------------------------------
#include "CDice.h"

//--Forward Declarations---------------------------------
class CPlayer;

//-------------------------------------------------------
// Dice race game from Lab 1
// If this was well written the first time, it should require
// relatively little change for Lab 2
// See lab 1 for details and rules
class CGame
{
  public:
    // types
    enum MoveType                         // enum defining the types of possible move
    {
      Roll, Delay                         // roll: roll the dice and advance; delay: delay the opponent by DelayAmount
    };

    // consts
    static const int BoardLength = 64;           // constant defining the length of the race board
    static const int DelayAmount = 12;           // if a player chooses to delay their opponent, by how much are they delayed
    
    // functions
    CGame();                                      // Starts without players, resets marker positions
    void ResetMarkers();                          // resets markers to starting position
    void AddPlayer( CPlayer* apPlayer );          // Adds a player to the game; the player knows their ID
    
    int GetMarkerPos( int PlayerID );             // returns position of marker for requested player ID

    bool IsDone();                                // determines if someone's won
    int WhoWins();                                // returns the winner in case of game being complete

    void Run();                                   // Runs a complete game
    
  private:
    // Mambers
    int mMarkerPos[2];      // Position of each marker; could also be in a separate board class
    CDice mDice;            // This game has dice
    CPlayer* mpPlayers[2];  // Pointers to the two players; starts empty; you must add players via AddPlayer()

    // Helper functions
    // Move the identified marker by the prescribed amount
    // invalid requests (off end of board) are ignored
    void MoveMarker( int WhichMarker, int MoveAmount ); 
};

#endif
