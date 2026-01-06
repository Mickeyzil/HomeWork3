#include "Cruiser.hpp"

Cruiser::Cruiser()
{
    this->size = 3;
    this->hitsTaken = 0;    
    this->name = new char(strlen("Cruiser")+1);
    if(this->name == nullptr)
    {
        std::cout << "could not create a name to the ship" << std::endl;
        return;
    }
    strcpy(this->name, "Cruiser");
}

Cruiser::~Cruiser()
{
    delete[] this->name;
}

void Cruiser::takeHit()
{
    if(this->hitsTaken >= this->size)
    {
        std::cout << "couldn't take more hits" << std::endl;
        return;
    }
    this->hitsTaken++;
}

bool Cruiser::isSunk() const
{
    if(this->hitsTaken >= this->size)
    {
        return true;
    }
    return false;
}