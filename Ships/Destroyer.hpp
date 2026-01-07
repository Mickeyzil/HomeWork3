#pragma once
#include "Ship.hpp"

class Destroyer : public Ship
{
private:

public:
    Destroyer();
    ~Destroyer();
    void takeHit() override;
    bool isSunk() const;
};