#include "Player.hpp"

Player::Player(const char* name)
{
    this->ships[0] = new Carrier();
    this->ships[1] = new Battleship();
    this->ships[2] = new Cruiser();
    this->ships[3] = new Submarine();
    this->ships[4] = new Destroyer();
    this->grid = Grid();
    this->playerName = new char(strlen(name)+1);
    if(this->playerName == nullptr)
    {
        return;
    }
    strcpy(this->playerName, name);
}

Player::~Player()
{
    delete[] this->playerName;
    for(int i=0; i<5; i++)
    {
        delete this->ships[i];
    }
}

bool Player::allShipsSunk() const
{
    for(int i=0; i<5; i++)
    {
        if(this->ships[i]->isSunk() == false)
        {
            return false;
        }
    }
    return true;
}