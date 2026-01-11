#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(const char* name)
{
    this->playerName = new char(strlen(name)+1);
    if(this->playerName == nullptr)
    {
        std::cout << "the human player has name" << std::endl;
        return;
    }
    strcpy(this->playerName, name);
}

HumanPlayer::~HumanPlayer()
{
    delete[] this->playerName;
}

void HumanPlayer::placeAllShips()
{
    int row, col;
    int horizontal;
    int index = 0;
    char symbol = 0;
    while(1)
    {
        if(index > 4)
        {
            std::cout << "All ships placed successfully" << std::endl;
            break;
        }
        std::cout << "Please press the row from 0 to 9 and the col from 0 to 9 you like to place the ship" << std::endl;
        std::cin >> row >> col;
        if(this->grid.isTitleValid(row,col) == false)
        {
            std::cout << "The row or the col is not valid please try again" << std::endl;
            continue;
        }
        if(this->grid.isTitleOccupied(row,col) == true)
        {
            std::cout << "The title you chose is already taken" << std::endl;
            continue;
        }

        std::cout << "Please write 1 if you want the ship horizontal or 2 if you want the ship vertical" << std::endl;
        std::cin >> horizontal;
        
        if((horizontal != 1) && (horizontal != 2))
        {
            std::cout << "you did not choose direction to the ship,horizontal or vertical please try again" << std::endl;
            continue;
        }
        
        if(horizontal == 1)
        {
            if(this->grid.inBounds(row,col,this->ships[index]->GetSize(),true) == false)
            {
                std::cout << "Can not plase the ship in grid, the bounds crossed" << std::endl;
                continue;
            }
            
            this->grid.placeShip(row,col,this->ships[index]->GetSize(),true, symbol);
            index++;
            symbol++;
            continue;
        }
        else
        {
            if(this->grid.inBounds(row,col,this->ships[index]->GetSize(),false) == false)
            {
                std::cout << "Can not plase the ship in grid, the bounds crossed" << std::endl;
                continue;
            }
            
            this->grid.placeShip(row,col,this->ships[index]->GetSize(),false,symbol);
            index++;
            symbol++;
            continue;
        }
    }  
}

void HumanPlayer::makeMove(Player* opponent)
{
    int row, col;
    std::cout << "Please choose row and col to attack" << std::endl;
    std::cin >> row >> col;
    if(this->grid.isTitleValid(row,col) == false)
    {
        std::cout << "The title you chose is not valid, you lost your turn" << std::endl;
        return;
    }
    char target = opponent->getGrid().getCell(row,col);
    if(target == '~')
    {
        std::cout << "The title you chose is empty, marks as miss" << std::endl;
        opponent->getGrid().MarkMiss(row, col);
        return;
    }
    else if(target == 'X' || target == 'M')
    {
        std::cout << "you already chose this target before" << std::endl;
        return;
    }
    else
    {
        if(target == '0')
        {
            if(opponent->getShip(0)->isSunk() == true)
            {
                std::cout << "You attack a sunk ship, attack doesn't count" << std::endl;
                return;
            }
            opponent->getShip(0)->takeHit();
        }
        else if(target == '1')
        {
            if(opponent->getShip(1)->isSunk() == true)
            {
                std::cout << "You attack a sunk ship, attack doesn't count" << std::endl;
                return;
            }
            opponent->getShip(1)->takeHit();
        }
        else if(target == '2')
        {
            if(opponent->getShip(2)->isSunk() == true)
            {
                std::cout << "You attack a sunk ship, attack doesn't count" << std::endl;
                return;
            }
            opponent->getShip(2)->takeHit();
        }
        else if(target == '3')
        {
            if(opponent->getShip(3)->isSunk() == true)
            {
                std::cout << "You attack a sunk ship, attack doesn't count" << std::endl;
                return;
            }
            opponent->getShip(3)->takeHit();
        }
        else
        {
            if(opponent->getShip(4)->isSunk() == true)
            {
                std::cout << "You attack a sunk ship, attack doesn't count" << std::endl;
                return;
            }
            opponent->getShip(4)->takeHit();
        }
    }
}