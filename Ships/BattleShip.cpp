#include "Battleship.hpp"

Battleship::Battleship()
{
    this->size = 4;
    this->hitsTaken = 0;
    this->name = new char(strlen("BattleShip")+1);
    if(this->name == nullptr)
    {
        std::cout << "could not create a name to the ship" << std::endl;
        return;
    }
    strcpy(this->name, "BattleShip");
}

Battleship::~Battleship()
{
    delete[] this->name;
}

void Battleship::takeHit()
{
    if(this->hitsTaken >= this->size)
    {
        std::cout << "couldn't take more hits" << std::endl;
        return;
    }
    this->hitsTaken++;
}

bool Battleship::isSunk() const
{
    if(this->hitsTaken >= this->size)
    {
        return true;
    }
    return false;
}