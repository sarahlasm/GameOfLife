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
    for (int r = 0; r < rows; ++r)
    {
      for (int c = 0; c < cols; ++c)
      {
        thisGen[r][c] = '-';
      }
    }
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

  char** GameMode::getThisGen()
  {
    return thisGen;
  }

  char** GameMode::getNextGen()
  {
    return nextGen;
  }

  int GameMode::getRows()
  {
    return rows;
  }

  int GameMode::getCols()
  {
    return cols;
  }

    void GameMode::setArray(int row, int col) //Debugging purposes, may be deleted
    {
      thisGen[row][col] = 'X';
    }

  void GameMode::setUpBoard(double popDensity)
  {
    int populatedSquares = rows * cols * popDensity;
    int r1, r2;
    while (populatedSquares > 0)
    {
      r1 = rand() % rows;
      r2 = rand() % cols;
      if (!isOccupied(thisGen[r1][r2]))
      {
        thisGen[r1][r2] = 'X';
        populatedSquares--;
      }
    }
    for (int r = 0; r < rows; ++r)
    {
      for (int c = 0; c < cols; ++c)
      {
        cout << thisGen[r][c] << " ";
      }
      cout << endl;
    }
  }
