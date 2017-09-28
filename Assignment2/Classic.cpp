#include "Classic.h"

using namespace std;

int ROWS;
int COLS;

Classic::Classic (const int ROWS, const int COLS):GameMode(ROWS, COLS)
{
  (*this).ROWS = ROWS;
  (*this).COLS = COLS;
}

Classic::~Classic()
{

}

int Classic::checkNeighbors(int row, int col)
{

  char** thisGen = getThisGen();
  int numNeighbors = 0;
  cout << "Checkpoint 1\n";

  if (row == 0)
  {
    cout << "if1\n";
    if (col == 0)
    {
      for (int r = 0; r < 2; ++r)
      {
        for (int c = 0; c < 2; ++c)
        {
          if (r == row && c == col)
          {
            cout << "If\n";
            break;
          }
          else if (GameMode::isOccupied(thisGen[r][c]))
            ++numNeighbors;
        }
      }
      cout << "Reached end of if. Yay!\n";
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
    cout << "elif2\n";
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
    cout << "elif3\n";
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
    cout << "elif4\n";
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
    cout << "else5\n";
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
  cout << "Checkpoint\n";
  return numNeighbors;
}
