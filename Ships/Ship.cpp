#include "Ship.hpp"
#include <string.h>

Ship::Ship()
{
    this->hitsTaken = 0;
    this->size = 0;
    this->name = nullptr;
}

Ship::Ship(const char* shipName, int shipSize)
{
    if(shipSize <= 0)
    {
        std::cout << "The Size is not valid" << std::endl;
        exit(1);
    }
    this->size = shipSize;
    this->hitsTaken = 0;
    this->name = new char(strlen(shipName)+1);
    if(this->name == nullptr)
    {
        std::cout << "could not create a name to the ship" << std::endl;
        return;
    }
    strcpy(this->name, shipName);
}

Ship::~Ship()
{
    delete[] this->name;
}

void Ship::takeHit()
{
    if(this->hitsTaken >= this->size)
    {
        std::cout << "cannot hit the ship" << std::endl;
        return;
    }
    this->hitsTaken++;
}

bool Ship::isSunk() const
{
    if(this->hitsTaken >= this->size)
    {
        return true;
    }
    return false;
}