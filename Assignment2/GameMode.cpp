#include "GameMode.h"

   char** thisGen;
   char** nextGen;
   int genCount;
   int rows;
   int cols;

  GameMode::GameMode(const int ROWS, const int COLS)
  {
    rows = ROWS;
    cols = COLS;

    thisGen = new char*[ROWS];
    for (int i = 0; i < ROWS; ++i)
    {
      thisGen[i] = new char[COLS];
    }
    nextGen = new char*[ROWS];
    for (int i = 0; i < ROWS; ++i)
    {
      nextGen[i] = new char[COLS];
    }
    genCount = 0;
  }

  GameMode::~GameMode()
  {

  }

  int GameMode::checkNeighbors(int row, int col)
  {
    return 0;
  }

  void GameMode::changeGrid()
  {
    int numNeighbors;
    for (int row = 0; row < rows; ++row)
    {
      for (int col = 0; col < cols; ++col)
      {
        numNeighbors = checkNeighbors(row, col);
        if (numNeighbors == 2)
          nextGen[row][col] = thisGen[row][col];
        else if (numNeighbors == 3)
          nextGen[row][col] = 'X';
        else
          nextGen[row][col] = '-';

      }
    }
    thisGen = nextGen;
    nextGen = new char*[rows];
    for (int i = 0; i < rows; ++i)
    {
      nextGen[i] = new char[cols];
    }
  }

  bool GameMode::isOccupied(char c)
  {
    return c == 'X';
  }

  char** getThisGen()
  {
    return thisGen;
  }

  char** getNextGen()
  {
    return nextGen;
  }

  int getRows()
  {
    return rows;
  }

  int getCols()
  {
    return cols;
  }
