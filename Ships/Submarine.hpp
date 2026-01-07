#pragma once
#include "Ship.hpp"

class Submarine : public Ship
{
private:

public:
    Submarine();
    ~Submarine();
    void takeHit() override;
    bool isSunk() const;
};