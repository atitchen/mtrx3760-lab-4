// CGameEvaluator.h
// 
// Example solution for Lab 2 Polymorphic Dice Race
//
// Copyright (c) Donald Dansereau, 2021

#ifndef __CGAMEEVALUATOR_H
#define __CGAMEEVALUATOR_H

//--Includes---------------------------------------------
#include "Enums.h"
#include "CGame.h"

//-------------------------------------------------------
// Class for evaluating games using different strategies
class CGameManager
{
  public:
    // Knows about and evaluates all alternative player strategies
    void EvalMethod(PlayStrategy p2);

  private:
    // Consts
    static const int mcNReps = 10000; // how many times should the game be run when collecting stats

    // Members
    CGame mGame;              // The game to be evaluated

    // Helper functions
    double EvalOneMethod();   // evaluates a single method, after mGame is set up with appropriate players
};

#endif
