#include "NandC_Player.h"

#include <cstdlib>      // rand
#include <iostream>
#include <string>

//-------------------------------------------------------
NandC_Player::NandC_Player( NandC_Game* apTheGame, int aID )
  : mpTheGame( apTheGame ), mID( aID )
{
}

//-------------------------------------------------------
int NandC_Player::GetID()
{
  return mID;
}

//-------------------------------------------------------
bool NandC_Player::CheckMove(int Move)
{
  bool Result = false;

  if(mpTheGame -> CheckValid(Move))
  {
    Result = true;
  }
  else
  {
    //std::cout << "Invalid Move.\n";
  }

  return Result;
}


//-------------------------------------------------------
NandC_Human_Player::NandC_Human_Player( NandC_Game* apTheGame, int aID )
  : NandC_Player( apTheGame, aID )
{
}


//-------------------------------------------------------
int NandC_Human_Player::ChooseMove(  )
{
  
  int Move;

  while (true)
  {
    std::cout << "\nPlayer " << (mID+1) << "'s turn.\n"
              << "\nWhat move would you like to make? (1-9): ";
    std::cin >> Move;
    std::cout << "\n";

    if(CheckMove(Move))
    {
      break;
    }

  }
  return Move;
}


//-------------------------------------------------------
NandC_Computer_Player::NandC_Computer_Player( NandC_Game* apTheGame, int aID )
  : NandC_Player( apTheGame, aID )
{
}

//-------------------------------------------------------
int NandC_Computer_Player::ChooseMove(  )
{
  int Move = 1;

  while (true)
  {
    
    Move = (rand() % 9) + 1;

    if(CheckMove(Move))
    {
      break;
    }

  }

  return Move;
}