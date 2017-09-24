#include "Doughnut.h"

  Doughnut::Doughnut(const int ROWS, const int COLS):GameMode(ROWS, COLS)
  {
  }

  Doughnut::~Doughnut()
  {

  }

  int Doughnut::checkNeighbors(int row, int col)
  {
    char** thisGen = getThisGen();
    int neighborCount = 0;
    if (row > 0 && row < getRows())
    {
        if (isOccupied(thisGen[row-1][col]))
          neighborCount++;
        if (isOccupied(thisGen[row+1][col]))
          neighborCount++;
    }
    if (col > 0 && col < getCols())
    {
      if (isOccupied(thisGen[row][col-1]))
        neighborCount++;
      if (isOccupied(thisGen[row][col+1]))
        neighborCount++;
    }
    return neighborCount;
  }
