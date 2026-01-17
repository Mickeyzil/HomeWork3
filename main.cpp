/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"

int main()
{
    std::srand(std::time(nullptr));
    HumanPlayer* player1 = new HumanPlayer("Human");
    AiPlayer* player2 = new AiPlayer();

    Game game(player1, player2);
    game.setup();    
    game.start();
       
    delete player1;
    delete player2;
     return 0;
}