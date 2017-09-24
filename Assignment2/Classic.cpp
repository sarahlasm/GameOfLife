#include "Classic.h"

using namespace std;

Classic::Classic (const int ROWS, const int COLS):GameMode(ROWS, COLS)
{

}

Classic::~Classic()
{

}

int Classic::checkNeighbors(int row, int col)
{
  char** thisGen = getThisGen();
  int numNeighbors = 0;

  if (row > 0 && row < GameMode::getRows() && col > 0 && col < GameMode::getCols())
  {
     for (int i = row - 1; i < row + 2; ++i)
     {
        for (int j = col - 1; j < col + 2; ++j)
        {
           if (i == row && j == col)
              continue;
           else if (GameMode::isOccupied(thisGen[i][j]))
              ++numNeighbors;
        }
     }
  } //end center check

  else if (row == 0)
  {
    for (int i = row; i < row + 2; ++i)
    {
       for (int j = col - 1; j < col + 2; ++j)
       {
          if (i == row && j == col)
             continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
             ++numNeighbors;
       }
    }
  }//end row == 0 check

  else if (row == GameMode::getRows())
  {
    for (int i = row - 1; i < row + 1; ++i)
    {
       for (int j = col - 1; j < col + 2; ++j)
       {
          if (i == row && j == col)
             continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
             ++numNeighbors;
       }
    }
  }//end row == getRows() check

  else if (col == 0)
  {
    for (int i = row - 1; i < row + 2; ++i)
    {
       for (int j = col; j < col + 2; ++j)
       {
          if (i == row && j == col)
             continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
             ++numNeighbors;
       }
    }
  } //end col == 0 check

  else if (col == GameMode::getCols())
  {
    for (int i = row - 1; i < row + 2; ++i)
    {
       for (int j = col - 1; j < col + 1; ++j)
       {
          if (i == row && j == col)
             continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
             ++numNeighbors;
       }
    }
  } //end col == getcols() check

  return numNeighbors;
}
