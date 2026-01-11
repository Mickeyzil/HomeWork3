#include "Carrier.hpp"

Carrier::Carrier()
{
    this->size = 5;
    this->hitsTaken = 0;
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