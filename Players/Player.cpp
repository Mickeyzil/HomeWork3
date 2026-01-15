#include "Player.hpp"
#include <cstring>   
#include <iostream>  

Player::Player(const char* name) : grid()
{
    this->ships[0] = new Carrier();
    this->ships[1] = new Battleship();
    this->ships[2] = new Cruiser();
    this->ships[3] = new Submarine();
    this->ships[4] = new Destroyer();
    this->playerName = new char[strlen(name)+1];
    if(this->playerName == nullptr)
    {
        std::cout << "The player has no name" << std::endl;
        return;
    }
    strcpy(this->playerName, name);
}

Player::Player() : Player("Player")
{

}

Player::~Player()
{
    delete[] this->playerName;
    for(int i=0; i<MaxShips; i++)
    {
        delete this->ships[i];
    }
}

bool Player::allShipsSunk() const
{
    for(int i=0; i<MaxShips; i++)
    {
        if(this->ships[i]->isSunk() == false)
        {
            return false;
        }
    }
    return true;
}

void Player::displayMyGrid() const
{
    this->grid.printGrid();
}

void Player::printOpponentGrid() const
{
    std::cout << "  ";
    for (int col = 0; col < cellSize; ++col)
    {
        std::cout << col << " ";
    }
    std::cout << "\n";

    for (int row = 0; row < cellSize; ++row)
    {
        std::cout << row << " ";
        for (int col = 0; col < cellSize; ++col)
        {
            char cell = this->grid.getCell(row,col);
            if(cell == 'X' || cell == 'M')
            {
                std::cout << cell << " ";
                continue;
            }
            std:: cout << "~" << " ";
        }
        std::cout << "\n";
    }
}