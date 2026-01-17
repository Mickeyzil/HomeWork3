/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
#pragma once
#include "Player.hpp"

class AiPlayer : public Player
{
private:
    
public:
    AiPlayer();
    ~AiPlayer();
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
};