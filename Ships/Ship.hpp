#pragma once
#include <iostream>
#include <string.h>

class Ship
{
protected:
    char* name;
    int size;
    int hitsTaken;
public:
    Ship();
    Ship(const char* shipName, int shipSize);
    virtual ~Ship();
    void takeHit();
    bool isSunk() const;
    inline int GetSize(){return this->size;};
};