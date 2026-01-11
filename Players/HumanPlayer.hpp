#include "Player.hpp"

class HumanPlayer : public Player
{
private:
    
public:
    HumanPlayer(const char* name);
    ~HumanPlayer();
    void placeAllShips();
    void makeMove(Player* opponent);
};


