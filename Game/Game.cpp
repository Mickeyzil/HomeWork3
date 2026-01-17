/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2)
{
    
}

Game::~Game() = default;

void Game::setup()
{
    this->player1->placeAllShips();
    this->player2->placeAllShips();
}

bool Game::isGameOver() const
{
    if((this->player1->allShipsSunk() == true) || (this->player2->allShipsSunk() == true))
    {
        return true;
    }
    return false;
}

void Game::start()
{
    while(true)
    {
        this->player1->makeMove(this->player2);
        if(this->player2->allShipsSunk() == true)
        {
            std::cout << "The game is over, the winner is: " << this->player1->getName() << "!" << std::endl;
            return;
        }
        this->player2->makeMove(this->player1);
        if(this->player1->allShipsSunk() == true)
        {
            std::cout << "The game is over, the winner is: " << this->player2->getName() << "!" << std::endl;
            return;
        }
    }
}