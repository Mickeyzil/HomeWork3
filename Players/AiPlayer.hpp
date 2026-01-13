#include "Player.hpp"

class AiPlayer : public Player
{
private:
    
public:
    AiPlayer();
    ~AiPlayer();
    void placeAllShips();
    void makeMove(Player* opponent);
};