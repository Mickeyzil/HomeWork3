#pragma once
#include "Ship.hpp"

class Battleship : public Ship
{
private:
    
public:
    Battleship();
    ~Battleship();
    void takeHit();
    bool isSunk() const;
};