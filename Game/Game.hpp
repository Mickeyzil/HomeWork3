/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
#pragma once
class Player;

class Game
{
private:
    Player* player1;
    Player* player2;
public:
    Game(Player* p1, Player* p2);
    ~Game();
    void setup();
    void start();
    bool isGameOver() const;
};


