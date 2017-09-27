#include "Classic.h"

using namespace std;

const int ROWS = GameMode::getRows();
const int COLS = GameMode::getCols();

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

  if (row == 0)
  {
    if (col == 0)
    {
      for (int i = 0; i < 2; ++row)
      {
        for (int j = 0; j < 2; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else if (col == COLS - 1)
    {
      for (int i = 0; i < 2; ++row)
      {
        for (int j = getCols() - 2; j < COLS; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int i = 0; i < 2; ++row)
      {
        for (int j = col - 1; j < col + 2; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }
  }

  else if (row == ROWS - 1)
  {
    if (col == 0)
    {
      for (int i = ROWS - 2; i < ROWS; ++row)
      {
        for (int j = 0; j < 2; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else if (col == COLS - 1)
    {
      for (int i = ROWS - 2; i < ROWS; ++row)
      {
        for (int j = COLS - 2; j < COLS; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int i = ROWS - 2; i < ROWS; ++row)
      {
        for (int j = col - 1; j < col + 2; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }
  }

  else if (col == 0)
  {
    if (row == 0)
    {
      for (int i = 0; i < 2; ++row)
      {
        for (int j = 0; j < 2; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else if (row == ROWS - 1)
    {
      for (int i = ROWS - 2; i < ROWS; ++row)
      {
        for (int j = 0; j < 2; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int i = row - 1; i < row + 2; ++row)
      {
        for (int j = 0; j < 2; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }
  }

  else if (col == COLS - 1)
  {
    if (row == 0)
    {
      for (int i = 0; i < 2; ++row)
      {
        for (int j = COLS - 2; j < COLS; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else if (row == ROWS - 1)
    {
      for (int i = ROWS - 2; i < ROWS; ++row)
      {
        for (int j = COLS - 2; j < COLS; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }

    else
    {
      for (int i = row - 1; i < row + 2; ++row)
      {
        for (int j = COLS - 2; j < COLS; ++col)
        {
          if (i == row && j == col)
            continue;
          else if (GameMode::isOccupied(thisGen[i][j]))
            ++numNeighbors;
        }
      }
    }
  }

  else
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
  }
  return numNeighbors;
}
