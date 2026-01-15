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