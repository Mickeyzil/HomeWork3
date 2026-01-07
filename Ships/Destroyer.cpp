#include "Destroyer.hpp"

Destroyer::Destroyer()
{
    this->size = 2;
    this->hitsTaken = 0;    
    this->name = new char(strlen("Destroyer")+1);
    if(this->name == nullptr)
    {
        std::cout << "could not create a name to the ship" << std::endl;
        return;
    }
    strcpy(this->name, "Destroyer");
}

Destroyer::~Destroyer()
{
    delete[] this->name;
}

void Destroyer::takeHit()
{
    if(this->hitsTaken >= this->size)
    {
        std::cout << "couldn't take more hits" << std::endl;
        return;
    }
    this->hitsTaken++;
}

bool Destroyer::isSunk() const
{
    if(this->hitsTaken >= this->size)
    {
        return true;
    }
    return false;
}