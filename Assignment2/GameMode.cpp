#include "GameMode.h"

  private char thisGen[][];
  private char nextGen[][];
  private int genCount;

  GameMode::GameMode(const int ROWS, const int COLS)
  {

    thisGen = new char*[ROWS];
    for (int i = 0; i < ROWS; ++i)
    {
      thisGen[i] = new char[COLS];
    }
    nextGen = new char[thisGen.size()][thisGen[0].size()]
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
    for (int row = 0; row < thisGen.size(); ++row)
    {
      for (int col = 0; col < thisGen[0].size(); ++col)
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
    thisGen =& nextGen;
    nextGen =& char**;
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
    return thisGen.size();
  }

  int getCols()
  {
    return thisGen[0].size();
  }
