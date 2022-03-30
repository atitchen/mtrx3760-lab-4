#include "Enums.h"
#include "NandC_Game_Manager.h"
#include "NandC_Player.h"

//-------------------------------------------------------
void NandC_Game_Manager::MakeGame(PlayerType p1, PlayerType p2)
{
    // Defines Types of possible players.
    NandC_Computer_Player computer1(&Game,0);
    NandC_Computer_Player computer2(&Game,1);
    NandC_Human_Player human1(&Game,0);
    NandC_Human_Player human2(&Game,1);

    // Add Player 1 to Game.
    switch (p1)
    {
    case Human:
        Game.AddPlayer(&human1);
        break;
    
    case Computer:
        Game.AddPlayer(&computer1);
        break;
    }
    
    // Add Player 1 to Game.
    switch (p2)
    {
    case Human:
        Game.AddPlayer(&human2);
        break;
    
    case Computer:
        Game.AddPlayer(&computer2);
        break;
    }

    // Starts Game.
    Game.Run();

}
        

