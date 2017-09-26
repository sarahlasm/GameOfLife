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
    if (row > 0 && row < getRows()) //Get horizontal neighbors
    {
        if (isOccupied(thisGen[row-1][col]))
          neighborCount++;
        if (isOccupied(thisGen[row+1][col]))
          neighborCount++;
        if (col > 0)
        {
          if (isOccupied(thisGen[row-1][col-1]))
            neighborCount++;
          if (isOccupied(thisGen[row+1][col-1]))
            neighborCount++;
        }
        if (col < getCols())
        {
          if (isOccupied(thisGen[row-1][col+1]))
            neighborCount++;
          if (isOccupied(thisGen[row+1][col+1]))
            neighborCount++;
        }
    }
    if (col > 0 && col < getCols()) //Get vertical neighbors
    {
      if (isOccupied(thisGen[row][col-1]))
        neighborCount++;
      if (isOccupied(thisGen[row][col+1]))
        neighborCount++;
    }

    if ((col == 0 || col == getCols()-1) && (row == 0 || row == getRows()-1)) //Corner cases
    {
      if (row == 0)
      {
        if (col == 0)
        {
          //Do something. Help! Corners are hard.
        }
      }
    }
    else //This is very inefficient. Needs to be fixed. If we have time and don't die.
    {
      if (col == 0)
      {
        for (int r = row-1; r <= row+1; ++r)
        {
          if (isOccupied(thisGen[r][getCols()-1]))
            neighborCount++;
          if (isOccupied(thisGen[r][1]))
            neighborCount++;
        }
      }
      if (col == getCols()-1)
      {
        for (int r = row-1; r <= row+1; ++r)
        {
          if (isOccupied(thisGen[r][0]))
            neighborCount++;
          if (isOccupied(thisGen[r][col-1]))
            neighborCount++;
        }
      }
      if (row == 0)
      {
        for (int c = col-1; c <= col+1; ++c)
        {
          if (isOccupied(thisGen[getRows()-1][c]))
            neighborCount++;
          if (isOccupied(thisGen[1][c]))
            neighborCount++;
        }
      }
      if (row == getRows()-1)
      {
        for (int c = col-1; c <= col+1; ++c)
        {
          if (isOccupied(thisGen[0][c]))
            neighborCount++;
          if (isOccupied(thisGen[row-1][c]))
            neighborCount++;
        }
      }
    }


    return neighborCount;
  }
