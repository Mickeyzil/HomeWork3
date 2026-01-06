#include "Ship.hpp"

class Cruiser : public Ship
{
private:
    
public:
    Cruiser();
    ~Cruiser();
    void takeHit();
    bool isSunk() const;
};