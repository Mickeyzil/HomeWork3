#include "HumanPlayer.hpp"
#include <iostream>

HumanPlayer::HumanPlayer(const char* name) : Player(name)
{
   
}

HumanPlayer::~HumanPlayer() = default;

void HumanPlayer::placeAllShips()
{
    int row, col;
    int dir;
    int index = 0;
    char symbol = '0';

    while (index < MaxShips)
    {
        std::cout << "Please enter row (0-9) and col (0-9) to place the ship:\n";
        std::cin >> row >> col;

        if (grid.isTitleValid(row, col) == false)
        {
            std::cout << "Invalid row/col. Try again.\n";
            continue;
        }

        std::cout << "Enter 1 for horizontal or 2 for vertical:\n";
        std::cin >> dir;

        if (dir != 1 && dir != 2)
        {
            std::cout << "Invalid direction. Try again.\n";
            continue;
        }

        bool isHorizontal = (dir == 1);
        int size = ships[index]->GetSize();

        if (grid.inBounds(row, col, size, isHorizontal) == false)
        {
            std::cout << "Out of bounds. Try again.\n";
            continue;
        }
        if (grid.canPlaceShip(row, col, size, isHorizontal) == false)   
        {
            std::cout << "Collision with another ship. Try again.\n";
            continue;
        }

        if(grid.placeShip(row, col, size, isHorizontal, symbol) == true)
        {
            index++;
            symbol++;
        }
    }

    std::cout << "All ships placed successfully\n";
}

void HumanPlayer::makeMove(Player* opponent)
{
    int row, col;
    std::cout << "Please choose row and col to attack\n";
    std::cin >> row >> col;

    if (!opponent->getGrid().isTitleValid(row, col))
    {
        std::cout << "The tile you chose is not valid, you lost your turn\n";
        this->displayMyGrid();
        opponent->displayMyGrid();
        return;
    }

    char target = opponent->getGrid().getCell(row, col);

    if (target == 'X' || target == 'M')
    {
        std::cout << "You already chose this target before, you lost your turn\n";
        this->displayMyGrid();
        opponent->displayMyGrid();
        return;
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