// CGame.cpp
// 
// Example solution for Lab 2 Polymorphic Dice Race
//
// Copyright (c) Donald Dansereau, 2021

#include "CGame.h"
#include "CPlayer.h"

#include <cstddef>

//-------------------------------------------------------
CGame::CGame()
{
  for( int iPlayer = 0; iPlayer < 2; ++iPlayer )
  {
    mpPlayers[iPlayer] = NULL;
  }
  ResetMarkers();
}

//-------------------------------------------------------
void CGame::ResetMarkers()
{
  for( int iPlayer = 0; iPlayer < 2; ++iPlayer )
  {
    mMarkerPos[iPlayer] = 0;
  }
}

//-------------------------------------------------------
void CGame::AddPlayer( CPlayer* apPlayer )
{
  mpPlayers[apPlayer->GetID()] = apPlayer;
}

//-------------------------------------------------------
int CGame::GetMarkerPos( int PlayerID )
{
  return mMarkerPos[PlayerID];
}

//-------------------------------------------------------
void CGame::Run()
{
  int WhoseTurn = 0;
  int IterCount = 0;
  
  while( true )
  {
    //std::cout << "It is Player " << WhoseTurn << "'s turn: ";
    // better to not have commented out code; we'll learn later how to build a logging class to avoid this
    MoveType WhichMove = mpPlayers[WhoseTurn]->ChooseMove();
    switch( WhichMove )
    {
      case Roll:
      {
        int RollAmount = mDice.RollTwoDice();
        MoveMarker(WhoseTurn, RollAmount);
        //std::cout << "Rolled " << RollAmount << std::endl;
      }
      break;
      case Delay:
      {
        int OtherPlayer = (WhoseTurn+1)%2;
        MoveMarker( OtherPlayer, -DelayAmount );
        //std::cout << "Delayed" << std::endl;
      }
      break;
    };
    if( IsDone() )
    {
      //std::cout << "Player " << WhoseTurn << " Wins!" << std::endl;
      for( int iMarker = 0; iMarker < 2; ++iMarker )
      {
        //std::cout << "Marker " << iMarker << " is at " << mMarkerPos[iMarker] << std::endl;
      }
      break;
    }
    WhoseTurn = (WhoseTurn + 1) % 2;
    ++IterCount;
    //std::cout << "Iter: " << IterCount << std::endl;
  }
}

//-------------------------------------------------------
bool CGame::IsDone()
{
  bool Result = false;
  for( int iMarker = 0; iMarker < 2; ++iMarker )
  {
    //std::cout << "Marker " << iMarker << " is at " << mMarkerPos[iMarker] << std::endl;
    if( mMarkerPos[iMarker] == BoardLength )
    {
      Result = true;
    }
  }
      
  return Result;
}

//-------------------------------------------------------
void CGame::MoveMarker( int WhichMarker, int MoveAmount )
{
  if( (mMarkerPos[WhichMarker] + MoveAmount <= BoardLength) && (mMarkerPos[WhichMarker] + MoveAmount >= 0) )
  {
    mMarkerPos[WhichMarker] += MoveAmount;
  }
}

//-------------------------------------------------------
int CGame::WhoWins()
{
  int Result = -1;
  for( int iMarker=0; iMarker<2; ++iMarker )
    if( mMarkerPos[iMarker] == BoardLength )
      Result = iMarker;
  return Result;
}
