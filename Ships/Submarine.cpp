#include "Submarine.hpp"

Submarine::Submarine()
{
    this->size = 3;
    this->hitsTaken = 0;    
    this->name = new char(strlen("Submarine")+1);
    if(this->name == nullptr)
    {
        std::cout << "could not create a name to the ship" << std::endl;
        return;
    }
    strcpy(this->name, "Submarine");
}

Submarine::~Submarine()
{
    delete[] this->name;
}

void Submarine::takeHit()
{
    if(this->hitsTaken >= this->size)
    {
        std::cout << "couldn't take more hits" << std::endl;
        return;
    }
    this->hitsTaken++;
}

bool Submarine::isSunk() const
{
    if(this->hitsTaken >= this->size)
    {
        return true;
    }
    return false;
}