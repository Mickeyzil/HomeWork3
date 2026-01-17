/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
#pragma once
#include "Player.hpp"

class HumanPlayer : public Player
{
private:
    
public:
    HumanPlayer(const char* name);
    ~HumanPlayer();
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
};


