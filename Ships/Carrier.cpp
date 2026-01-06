#include "Carrier.hpp"

Carrier::Carrier()
{
    this->size = 5;
    this->name = new char(strlen("Carrier")+1);
    if(this->name == nullptr)
    {
        std::cout << "could not create a name to the ship" << std::endl;
        return;
    }
    strcpy(this->name, "Carrier");
}

Carrier::~Carrier()
{
    delete[] this->name;
}

void Carrier::takeHit()
{
    if(this->hitsTaken >= this->size)
    {
        std::cout << "couldn't take more hits" << std::endl;
        return;
    }
    this->hitsTaken++;
}

bool Carrier::isSunk() const
{
    if(this->hitsTaken >= this->size)
    {
        return true;
    }
    return false;
}