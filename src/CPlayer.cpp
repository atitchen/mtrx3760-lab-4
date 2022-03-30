// CPlayer.cpp
// 
// Example solution for Lab 2 Polymorphic Dice Race
//
// Copyright (c) Donald Dansereau, 2021

//--Includes---------------------------------------------
#include "CPlayer.h"

#include <cstdlib>      // rand
#include <iostream>
#include <string>

//-------------------------------------------------------
CPlayer::CPlayer( CGame* apTheGame, int aID )
  : mpTheGame( apTheGame ), mID( aID )
{
}

//-------------------------------------------------------
int CPlayer::GetID()
{
  return mID;
}

//-------------------------------------------------------
CPlayerRand::CPlayerRand( CGame* apTheGame, int aID )
  : CPlayer( apTheGame, aID )
{
}

//-------------------------------------------------------
CGame::MoveType CPlayerRand::ChooseMove(  )
{
  CGame::MoveType Result;
  if( rand() % 2 == 0 )
  {
    Result = CGame::Roll;
  }
  else
  {
    Result = CGame::Delay;
  }
  return Result;
}

//-------------------------------------------------------
CPlayerCharge::CPlayerCharge( CGame* apTheGame, int aID )
  : CPlayer( apTheGame, aID )
{
}

//-------------------------------------------------------
CGame::MoveType CPlayerCharge::ChooseMove()
{
  CGame::MoveType Result = CGame::Roll;
  return Result;
}

//-------------------------------------------------------
CPlayerSmart::CPlayerSmart( CGame* apTheGame, int aID )
  : CPlayer( apTheGame, aID )
{
}

//-------------------------------------------------------
CGame::MoveType CPlayerSmart::ChooseMove()
{
  CGame::MoveType Result;
  Result = CGame::Roll;
  
  int OpponentID = (mID + 1) % 2;

  int OpponentPos = mpTheGame->GetMarkerPos( OpponentID );
  
  if( abs((CGame::BoardLength - OpponentPos)) < 13 )
     Result = CGame::Delay;
 
  return Result;
}

//-------------------------------------------------------
CPlayerHuman::CPlayerHuman( CGame* apTheGame, int aID )
  : CPlayer( apTheGame, aID )
{
}

//-------------------------------------------------------
CGame::MoveType CPlayerHuman::ChooseMove(  )
{
  CGame::MoveType Result;
  
  int userInput;

  while (true)
  {
    std::cout << "\nWhat move would you like to make? Roll (1) or Delay (2): ";
    std::cin >> userInput;
    std::cout << "\n";

    if (userInput == 1)
    {

      Result = CGame::Roll;
      break;

    }
    else if (userInput == 2)
    {

      Result = CGame::Delay;
      break;

    }


  }
  return Result;
}
