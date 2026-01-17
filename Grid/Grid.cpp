/*Mickey Zilberman 212918635
  Gil Cohen 322399338*/
#include "Grid.hpp"

Grid::Grid()
{
    for(int i=0; i<cellSize; i++)
    {
        for(int j=0; j<cellSize; j++)
        {
            this->cells[i][j] = '~';
        }
    }
}

Grid::~Grid()
{

}

bool Grid::isTitleValid(int row, int col) const
{
    return (row >= 0 && row < cellSize) && (col >= 0 && col < cellSize);
}

char Grid::getCell(int row, int col) const
{
    if (row < 0 || col < 0 || row >= cellSize || col >= cellSize)
    {
        std::cout << "Invalid cell access\n";
        return '~';
    }
    return cells[row][col];
}

bool Grid::isTitleOccupied(int row, int col) const
{
    if (isTitleValid(row, col) == false)
        return true; 

    return cells[row][col] != '~';
}


bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    if (row < 0 || col < 0)
        return false;

    if (row >= cellSize || col >= cellSize)
        return false;

    if (shipSize <= 0)
        return false;

    if (horizontal)
        return col + shipSize <= cellSize;
    else
        return row + shipSize <= cellSize;
}

bool Grid::canPlaceShip(int row, int col, int shipSize, bool horizontal) const
{
    if (!inBounds(row, col, shipSize, horizontal))
        return false;

    if (horizontal)
    {
        for (int c = col; c < col + shipSize; ++c)
        {
            if (this->cells[row][c] != '~')
                return false;
        }
    }
    else
    {
        for (int r = row; r < row + shipSize; ++r)
        {
            if (this->cells[r][col] != '~')
                return false;
        }
    }

    return true;
}


bool Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    if (!canPlaceShip(row, col, shipSize, horizontal))
        return false;

    if (horizontal)
    {
        for (int c = col; c < col + shipSize; ++c)
            cells[row][c] = symbol;
    }
    else
    {
        for (int r = row; r < row + shipSize; ++r)
            cells[r][col] = symbol;
    }

    return true;
}


void Grid::markHit(int row, int col)
{
    if(row < 0 || row >= cellSize || col < 0 || col >= cellSize)
    {
        std::cout << "Can not mark hit on board" << std::endl;
        return;
    }
    this->cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col)
{
    if(row < 0 || row >= cellSize || col < 0 || col >= cellSize)
    {
        std::cout << "Can not mark miss on board" << std::endl;
        return;
    }
    this->cells[row][col] = 'M';
}

void Grid::printGrid() const
{
    std::cout << "  ";
    for (int col = 0; col < cellSize; ++col)
    {
        std::cout << col << " ";
    }
    std::cout << "\n";

    for (int row = 0; row < cellSize; ++row)
    {
        std::cout << row << " ";
        for (int col = 0; col < cellSize; ++col)
        {
            std::cout << cells[row][col] << " ";
        }
        std::cout << "\n";
    }
}