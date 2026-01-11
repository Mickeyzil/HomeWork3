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