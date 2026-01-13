#include "AiPlayer.hpp"

AiPlayer::AiPlayer()
{
    this->playerName = new char(strlen("AiPlayer")+1);
    if(this->playerName == nullptr)
    {
        std::cout << "The AI Player has no name\n";
        return;
    }
    strcpy(this->playerName, "AiPlayer");
}

AiPlayer::~AiPlayer()
{
    delete[] this->playerName;
}

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
        if(this->grid.canPlaceShip(row,col,size,isHorizontal) == true)
        {
            this->grid.placeShip(row,col,size,isHorizontal,symbol);
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
    while(target == 'X')
    {
        row = rand() % 10;
        col = rand() % 10;
        target = opponent->getGrid().getCell(row,col);
    }

    if (target == '~')
    {
        std::cout << "Miss!\n";
        opponent->getGrid().MarkMiss(row, col);
        return;
    }

    int idx = target - '0';
    if (idx < 0 || idx >= 5)
    {        
        std::cout << "Unexpected cell value\n";
        return;
    }

    opponent->getShip(idx)->takeHit();
    opponent->getGrid().MarkHit(row, col);

    this->grid.printGrid();
    opponent->getGrid().printGrid();
}