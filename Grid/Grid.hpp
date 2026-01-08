#pragma once
#include <iostream>
const int cellSize = 10;

class Grid
{
private:
    char cells[cellSize][cellSize];
public:
    Grid();
    ~Grid();
    bool isTitleOccupied(int row, int col) const;
    bool inBounds(int row, int col, int shipSize, bool horizontal) const;
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
    void MarkHit(int row, int col);
    void MarkMiss(int row, int col);
    char getCell(int row, int col) const;
    void printGrid() const;  //optional
};

