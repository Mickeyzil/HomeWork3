#include "Ship.hpp"

class Carrier : public Ship
{
private:
    
public:
    Carrier();
    ~Carrier();
    void takeHit();
    bool isSunk() const;
};