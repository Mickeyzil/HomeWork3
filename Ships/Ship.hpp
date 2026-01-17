/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
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
    Ship(const char* shipName, int shipSize);
    virtual ~Ship();
    virtual void takeHit();
    bool isSunk() const;
    inline int GetSize() const {return this->size;};
};