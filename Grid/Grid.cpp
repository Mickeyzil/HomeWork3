#include "Grid.hpp"

Grid::Grid()
{
    for(int i=0; i<cellSize; i++)
    {
        for(int j=0; j<cellSize; j++)
        {
            this->cells[cellSize][cellSize] = '~';
        }
    }
}

Grid::~Grid()
{

}

char Grid::getCell(int row, int col) const
{
    if(row >= cellSize || col >= cellSize)
    {
        std::cout << "Can not return the symbol in the board" << std::endl;
        return 'W';
    }
    return this->cells[row][col];
}

bool Grid::isTitleOccupied(int row, int col) const
{
    char title = this->cells[row][col];
    if(title == 'S' || title == 'X')
    {
        return true;
    }
    return false;
}

bool Grid::inBounds(int row, int col,  int shipSize, bool horizontal) const
{
    if(row >= cellSize || col >= cellSize)
    {
        std::cout << "The row or col are not valid" << std::endl;
        return false;
    }
    if(shipSize <= 0)
    {
        std::cout << "The size of the ship is invalid" << std::endl;
        return false;
    }
    if(horizontal == true)
    {
        for(int i=col; i<col+shipSize;i++)
        {
            if(i >= cellSize)
            {
                std::cout << "The ship is not in the grid's bound" << std::endl;
                return false;
            }
        }
    }
    else
    {
        for(int i=row; i<row+shipSize;i++)
        {
            if(i >= cellSize)
            {
                std::cout << "The ship is not in the grid's bound" << std::endl;
                return false;
            }
        }
    }
    return true;
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    bool isOccupied = isTitleOccupied(row,col);
    if(isOccupied == true)
    {
        std::cout << "Can not place ship in those row and col" << std::endl;
        return;
    }

    if(this->inBounds(row, col, shipSize,horizontal) == false)
    {
        std::cout << "Can not place ship, not in bound" << std::endl;
        return;
    }

    if(horizontal == true)
    {
        for(int i=col; i<col+shipSize; i++)
        {
            this->cells[row][i] = 'S';
        }
        return;
    }
    else
    {
        for(int i=row; i<row+shipSize; i++)
        {
            this->cells[i][col] = 'S';
        }
        return;
    }
}

void Grid::MarkHit(int row, int col)
{
    if(row >= cellSize || col >= cellSize)
    {
        std::cout << "Can not mark hit on board" << std::endl;
        return;
    }
    this->cells[row][col] = 'X';
}

void Grid::MarkMiss(int row, int col)
{
    if(row >= cellSize || col >= cellSize)
    {
        std::cout << "Can not mark miss on board" << std::endl;
        return;
    }
    this->cells[row][col] = 'M';
}