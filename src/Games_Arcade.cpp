// Games_Arcade.cpp
//
// Methods used to setup games via a menu system.
//
// Author: Student 490476145 USYD


#include <iostream>
#include <string>

#include "Games_Arcade.h"
#include "CGameManager.h"
#include "NandC_Game_Manager.h"


//-------------------------------------------------------
void CGames_Arcade::menu()
{

    int GameSelect;

    while (true)
    {

        std::cout   << "\nGames:\n"
                    << "(0) Dice Race Game\n"
                    << "(1) Noughts and Crosses\n"
                    << "(2) QUIT\n\n"
                    << "What would you like to play?: ";

        std::cin >> GameSelect;

        if(GameSelect == 2){
            break;
        }

        switch (GameSelect)
        {
        case 0:
            DiceRaceMenu();
            break;

        case 1:
            NoughtsCrossesMenu();
            break;
        
        default:
            std::cout << "\nInvalid input. Try Again: ";
            break;
        }

        WaitForEnter();
    }
    
}




//-------------------------------------------------------
void CGames_Arcade::DiceRaceMenu()
{

    CGameManager DiceGameManager;
    int GameStrategy;

    while (true)
    {

        std::cout   << "\nGame Strategies:\n"
                    << "(0) Random\n"
                    << "(1) Charge\n"
                    << "(2) Smart\n\n";

        std::cout   << "\nWhat strategy would you like to use?: ";

        std::cin >> GameStrategy;

        
        if(GameStrategy<=2)
        {

            // Starts Dice Race with user defined parameters.
            DiceGameManager.EvalMethod((PlayStrategy) GameStrategy); 
            break; 

        }
        
        
        std::cout << "\nInvalid input. Try Again: ";
            

    }
}

//-------------------------------------------------------
void CGames_Arcade::NoughtsCrossesMenu()
{

    int Player1;
    int Player2;

    while (true)
    {
        
        std::cout   << "\nPlayer Types:\n"
                    << "(0) Human Player\n"
                    << "(1) Computer Player\n\n";

        std::cout   << "\nIs Player 1 a human or computer?: ";

        std::cin >> Player1;

        std::cout   << "\nIs Player 2 a human or computer?: ";

        std::cin >> Player2;

        // Starts Noughts and Crosses with user defined parameters.
        NandC_Game_Manager NandC_Manager;
        NandC_Manager.MakeGame((PlayerType) Player1,(PlayerType) Player2);

        break;
    }
    
}

//-------------------------------------------------------
void CGames_Arcade::WaitForEnter()
{
    std::cout   << "\n(Press Enter to Continue)\n";
    std::cin.ignore();
    std::cin.ignore();
}
