// CGameEvaluator.cpp
// 
// Example solution for Lab 2 Polymorphic Dice Race
//
// Copyright (c) Donald Dansereau, 2021

//--Includes---------------------------------------------
#include "CGameManager.h"

#include "CPlayer.h"
#include "CGame.h"
#include "Enums.h"

#include <iostream>

//-------------------------------------------------------
// This evaluator creates players, adds them to the game,
// and runs the game to evaluate them via the helper function
// EvalOneMethod. There are better ways to do this, we will 
// study the factory design pattern later on...
// For now a key point is that there are no if statements deciding
// how the player should behave... it's all done through polymorphism.
void CGameManager::EvalMethod(PlayStrategy p2)
{

    CPlayerRand player1( &mGame, 0 );
    CPlayerRand player2( &mGame, 1 );
    CPlayerCharge player3( &mGame, 1 );
    CPlayerSmart player4( &mGame, 1 );

    mGame.AddPlayer( &player1 );

    switch (p2)
    {
    case Random:
        
        mGame.AddPlayer( &player2 );
        
        break;

    case Charge:
        
        mGame.AddPlayer( &player3 );
        
        break;

    case Smart:
        
        mGame.AddPlayer( &player4 );

        break;
        
    default:
        break;
    }

    
    

    {   // note the use of curly braces to set up a scope here for myChargePlayer and StrategyWins variables
        double StrategyWins = EvalOneMethod();
        std::cout << "Your strategy won " << StrategyWins << "\% of the time" << std::endl;
    }
    
}

//-------------------------------------------------------
double CGameManager::EvalOneMethod()
{
    double Result = -1;
    int TrackWins = 0;

    for( int iReps = 0; iReps < mcNReps; ++iReps )
    {
        mGame.ResetMarkers();
        mGame.Run();
        int Winner = mGame.WhoWins();
        if( Winner == 1 )
            ++TrackWins;
    }      

    Result = TrackWins * 100.0 / double(mcNReps);
    return Result;
}
