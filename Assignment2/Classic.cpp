#include "Classic.h"

using namespace std;

int ROWS;
int COLS;

/**
Inherits constructor from GameMode
*/
Classic::Classic (const int ROWS, const int COLS):GameMode(ROWS, COLS)
{
  (*this).ROWS = ROWS;
  (*this).COLS = COLS;
}

Classic::~Classic()
{

}

/**
checkNeighbors runs through the grid to count the neighbors of the particular cell
Parameters row and col are the row and column of the current cell
*/
int Classic::checkNeighbors(int row, int col)
{

  char** thisGen = getThisGen();
  int numNeighbors = 0;

  if (row == 0)
  {
    if (col == 0)
    {
      for (int r = 0; r < 2; ++r)
      {
        for (int c = 0; c < 2; ++c)
        {
          if (r == row && c == col)
          {
            break;
          }
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else if (col == COLS - 1)
    {
      for (int r = 0; r < 2; ++r)
      {
        for (int c = getCols() - 2; c < COLS; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int r = 0; r < 2; ++r)
      {
        for (int c = col - 1; c < col + 2; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }
  }

  else if (row == ROWS - 1)
  {
    if (col == 0)
    {
      for (int r = ROWS - 2; r < ROWS; ++r)
      {
        for (int c = 0; c < 2; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else if (col == COLS - 1)
    {
      for (int r = ROWS - 2; r < ROWS; ++r)
      {
        for (int c = COLS - 2; c < COLS; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int r = ROWS - 2; r < ROWS; ++r)
      {
        for (int c = col - 1; c < col + 2; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }
  }

  else if (col == 0)
  {
    if (row == 0)
    {
      for (int r = 0; r < 2; ++r)
      {
        for (int c = 0; c < 2; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else if (row == ROWS - 1)
    {
      for (int r = ROWS - 2; r < ROWS; ++r)
      {
        for (int c = 0; c < 2; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int r = row - 1; r < row + 2; ++r)
      {
        for (int c = 0; c < 2; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }
  }

  else if (col == COLS - 1)
  {
    if (row == 0)
    {
      for (int r = 0; r < 2; ++r)
      {
        for (int c = COLS - 2; c < COLS; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else if (row == ROWS - 1)
    {
      for (int r = ROWS - 2; r < ROWS; ++r)
      {
        for (int c = COLS - 2; c < COLS; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int r = row - 1; r < row + 2; ++r)
      {
        for (int c = COLS - 2; c < COLS; ++c)
        {
          if (r == row && c == col)
            continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
    }
  }

  else
  {
    for (int r = row - 1; r < row + 2; ++r)
    {
       for (int c = col - 1; c < col + 2; ++c)
       {
          if (r == row && c == col)
             continue;
          else if (GameMode::isOccupied(thisGen[r][c]))
             ++numNeighbors;
       }
    }
  }
  return numNeighbors;
}
