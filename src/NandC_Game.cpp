
#include "NandC_Game.h"
#include "NandC_Player.h"

#include <iostream>

//-------------------------------------------------------
NandC_Game::NandC_Game()
{

    // Resets Game Players.
    for( int iPlayer = 0; iPlayer < 2; ++iPlayer )
    {
        mpPlayers[iPlayer] = NULL;
    }
    
}

//-------------------------------------------------------
int NandC_Game::Run()
{
    
    int WhoseTurn = 0;
    
    std::cout   << "\nNoughts & Crosses:";
    Print_Board();

    while (true)
    {
    
        // Gets Players Move.
        int MovePosition = mpPlayers[WhoseTurn] -> ChooseMove();

        std::cout << "\n Player " << (WhoseTurn+1) << " Moves: " << MovePosition << "\n";

        // Applies Move.
        Move(WhoseTurn,MovePosition);

        // Displays Game Board.
        Print_Board();

        // Breaks if the game is finished.
        if(CheckFinished())
        {
            std::cout << "\nPlayer " << (WhoseTurn+1) << " wins\n";
            break;
        }
        
        // Swaps Turn.
        WhoseTurn = (WhoseTurn + 1) % 2;
    }
    
    return WhoseTurn;
}

//-------------------------------------------------------
void NandC_Game::Move(int WhoseTurn, int MovePosition)
{
    // Converts int Move to x and y coordinates.
    int x = (MovePosition-1) % 3;
    int y = (MovePosition-1) / 3;

    // Places nought or cross.
    _Board[x][y] = WhoseTurn + 1;
}

//-------------------------------------------------------
void NandC_Game::Print_Board()
{
    int x;
    int y;

    std::cout   << "\n\n+---+---+---+\n";

    for(y = 0; y<3; y++)
    {
       std::cout << "|";
       for(x = 0; x<3; x++)
        {
            std::cout   << " "
                        << Print_Symbol(_Board[x][y],(x+1)+(y+1)*3)
                        << " |";
        } 
        std::cout << "\n+---+---+---+\n";
    }

}

//-------------------------------------------------------
char NandC_Game::Print_Symbol(int Symbol,int Coordinate)
{
    char value;

    switch (Symbol)
    {
    case Blank:
        value = Coordinate + 45;
        break;
    
    case Cross:
        value = 'X';
        break;

    case Nought:
        value = 'O';
        break;

    default:
        break;
    }

    // Returns X, O or number(0-9), depending on the board value.
    return value;
}


//-------------------------------------------------------
void NandC_Game::AddPlayer( NandC_Player* apPlayer )
{
  mpPlayers[apPlayer->GetID()] = apPlayer;
}

bool NandC_Game::CheckValid(int Move)
{
    // Converts from int Move to x and y coordinates.
    int X = (Move-1) % 3;
    int Y = (Move-1) / 3;

    // Returns true if location is empty.
    return !_Board[X][Y];
}

bool NandC_Game::CheckFinished()
{
    
    int X;
    int Y;

    bool Result = false;

    // Check Vertical.
    for (X = 0; X<3; X++)
    {
        if( (( _Board[X][0] == _Board[X][1] ) && ( _Board[X][0] == _Board[X][2] ))  && ( _Board[X][0] ) )
        {   
            Result = true;
        }
    }

    // Check Horisontal.
    for (Y = 0; Y<3; Y++)
    {
        if( (( _Board[0][Y] == _Board[1][Y] ) && ( _Board[0][Y] == _Board[2][Y] )) && ( _Board[0][Y] ) )
        {
            Result = true;
        }
    }

    // Check Diagonal.
    if ( ((( _Board[1][1] == _Board[0][0] ) && ( _Board[1][1] == _Board[2][2] )) || (( _Board[1][1] == _Board[2][0] ) && ( _Board[1][1] == _Board[0][2] ))) && (( _Board[1][1] )) )
    
    {
        Result = true;
    }

    // Returns true if game has finished.
    return Result;

}
