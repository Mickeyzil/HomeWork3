#pragma once
#include "Ship.hpp"

class Carrier : public Ship
{
private:
    
public:
    Carrier();
    ~Carrier();
    void takeHit() override;
    bool isSunk() const;
};