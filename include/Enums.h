// Enums.h
//
// This file contains several Enums used throught the project.
//
// Author: Student 490476145 USYD


#ifndef ENUMS_H
#define ENUMS_H

enum PlayStrategy   // enum defining the types of possible Strategies.
{
    Random,         // Random until the last 12 tiles where player charges.
    Charge,         // Charge: Always Roll; RollingEnd.
    Smart  
};

enum MoveType       // enum defining the types of possible move.
{
    Roll,           // Roll: roll the dice and advance.
    Delay           // Delay: delay the opponent by DelayAmount.
};

enum PlayerType     // enum defining the types of possible players.
{ 
    Human, 
    Computer 
};

enum GameType       // enum defining the possible games to play.
{ 
    DiceRace, 
    NoughtsCrosses 
};

#endif

