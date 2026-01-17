/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
#include "Ship.hpp"
#include <string.h>

Ship::Ship(const char* shipName, int shipSize)
{
    if((shipSize <= 0) || (shipName == nullptr))
    {
        std::cout << "Invalid ship parameters" << std::endl;
        return;
    }
    this->size = shipSize;
    this->hitsTaken = 0;
    this->name = new char[strlen(shipName)+1];
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
       // std::cout << "cannot hit the ship, the ship is sunk" << std::endl;
        return;
    }
    std::cout << this->name << " got hit!" << std::endl;
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