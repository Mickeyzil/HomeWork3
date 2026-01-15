#pragma once
#include "Ship.hpp"
#include "Carrier.hpp"
#include "Cruiser.hpp"
#include "Battleship.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"
#include "Grid.hpp"

const int MaxShips = 5;

class Player
{
protected:
    char* playerName;
    Ship* ships[MaxShips];
    Grid grid;
public:
    Player();
    Player(const char* name);
    virtual ~Player();
    virtual void placeAllShips() = 0;
    virtual void makeMove(Player* opponent) = 0;
    bool allShipsSunk() const;
    inline Grid& getGrid(){return this->grid;};
    inline const Grid& getGrid() const{return this->grid;};
    inline Ship* getShip(int index) { return ships[index]; }
    inline const Ship* getShip(int index) const { return ships[index]; }
    void displayMyGrid() const; 
    void printOpponentGrid() const;
    inline const char* getName() const {return this->playerName;};
};


