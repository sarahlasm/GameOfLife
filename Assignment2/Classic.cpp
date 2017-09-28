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
    cout << "elif2\n";
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
    cout << "elif3\n";
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
    cout << "elif4\n";
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
    cout << "else5\n";
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
  cout << "Checkpoint\n";
  return numNeighbors;
}
