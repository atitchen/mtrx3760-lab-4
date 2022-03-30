// CDice.cpp
// 
// Example solution for Lab 2 Polymorphic Dice Race
//
// Copyright (c) Donald Dansereau, 2021

//--Includes---------------------------------------------
#include "CDice.h"

#include <cstdlib>      // rand

//-------------------------------------------------------
// It's important to add two dice, rand() % 12 doesn't do it
int CDice::RollTwoDice()
{
  int Result1 = (rand() % 6) + 1;
  int Result2 = (rand() % 6) + 1;  
  int Result = Result1 + Result2;
  return Result;
}

