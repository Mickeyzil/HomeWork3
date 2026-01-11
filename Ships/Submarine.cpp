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