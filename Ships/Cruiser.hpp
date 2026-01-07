#pragma once
#include "Ship.hpp"

class Cruiser : public Ship
{
private:
    
public:
    Cruiser();
    ~Cruiser();
    void takeHit() override;
    bool isSunk() const;
};