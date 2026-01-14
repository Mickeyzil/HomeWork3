#include "AiPlayer.hpp"
#include <iostream>
#include <cstdlib>  

AiPlayer::AiPlayer() : Player("AiPlayer")
{
   
}

AiPlayer::~AiPlayer() = default;

void AiPlayer::placeAllShips()
{
    int row, col;
    int index = 0;
    char symbol = '0';
    bool isHorizontal;
    while (index < MaxShips)
    {
        row = rand() % 10;
        col = rand() % 10;
        isHorizontal = rand() % 2;
        int size = this->getShip(index)->GetSize();
        if (this->getGrid().placeShip(row, col, size, isHorizontal, symbol))
        {
            index++;
            symbol++;
        }

    }
}

void AiPlayer::makeMove(Player* opponent)
{
    int row = rand() % 10;
    int col = rand() % 10;
    char target = opponent->getGrid().getCell(row,col);
    while(target == 'X' || target == 'M')
    {
        row = rand() % 10;
        col = rand() % 10;
        target = opponent->getGrid().getCell(row,col);
    }

    if (target == '~')
    {
        std::cout << "Miss!\n";
        opponent->getGrid().markMiss(row, col);
        this->displayMyGrid();
        opponent->displayMyGrid();
        return;
    }

    int idx = target - '0';
    if (idx < 0 || idx >= MaxShips)
    {        
        std::cout << "Unexpected cell value\n";
        return;
    }

    opponent->getShip(idx)->takeHit();
    opponent->getGrid().markHit(row, col);

    this->displayMyGrid();
    opponent->displayMyGrid();
}