#include <iostream>

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
};


