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


