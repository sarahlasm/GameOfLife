#include "Doughnut.h"


  Doughnut::Doughnut(char thisGen[6][5]):GameMode(thisGen)
  {
  }

  Doughnut::~Doughnut()
  {

  }

  int Doughnut::checkNeighbors(int row, int col)
  {
    int neighborCount = 0;
    if (row > 0 && row < thisGen.size())
    {
        if (isOccupied(thisGen[row-1][col]))
          neighborCount++;
        if (isOccupied(thisGen[row+1][col]))
          neighborCount++;
    }
    if (col > 0 && col < thisGen[0].size())
    {
      if (isOccupied(thisGen[row][col-1]))
        neighborCount++;
      if (isOccupied(thisGen[row][col+1]))
        neighborCount++;
    }
    return neighborCount;
  }
