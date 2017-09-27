#include "GameMode.h"

char** thisGen;
char** nextGen;
int genCount;
int rows;
int cols;
bool stable;

/**
Constructor
@Parameters - ROWS (rows in the gameboard) and COLS (cols in the gameboard)
Initializes two arrays, thisGen and nextGen
*/
GameMode::GameMode(const int ROWS, const int COLS)
{
  rows = ROWS;
  cols = COLS;
  stable = false;

  thisGen = new char*[ROWS];
  for (int i = 0; i < ROWS; ++i)
  {
    thisGen[i] = new char[COLS];
  }
  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      thisGen[r][c] = '-';
    }
  }

  nextGen = new char*[ROWS];
  for (int i = 0; i < ROWS; ++i)
  {
    nextGen[i] = new char[COLS];
  }
  genCount = 0;
}

/**
Destructor
Deletes thisGen and nextGen
*/
GameMode::~GameMode()
{
  delete thisGen;
  delete nextGen;
}

/**
Parameters - row and col number of cell
Returns number of neighbors a given cell has
To be overridden in child classes
*/
int GameMode::checkNeighbors(int row, int col)
{
  return 0;
}

/**
Creates new generation, changes pointer, checks if simulation is stable
*/
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

  stable = GameMode::compareGrid(thisGen, nextGen);

  if (stable)
  {
    cout << "Stable" << endl;
  }

  else
  {
    thisGen = nextGen;
    nextGen = new char*[rows];
    for (int i = 0; i < rows; ++i)
    nextGen[i] = new char[cols];
  }
}

/**
Parameter - character c
Returns true if c is 'X', therefore occupied
*/
bool GameMode::isOccupied(char c)
{
  return c == 'X';
}

/**
Returns thisGen
*/
char** GameMode::getThisGen()
{
  return thisGen;
}

/**
Returns nextGen
*/
char** GameMode::getNextGen()
{
  return nextGen;
}

/**
Returns number of rows
*/
int GameMode::getRows()
{
  return rows;
}

/**
Returns number of columns
*/
int GameMode::getCols()
{
  return cols;
}

/**
Parameters - row and col number of cell they wanted changed
Sets that cell to be occupied
*/
void GameMode::setArray(int row, int col)
{
  thisGen[row][col] = 'X';
}

/**
Parameter popDensity - a decimal between 0 and 1
Randomly fills board with X's based on population density
*/

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

/**
Parameters - thisGen and nextGen
Returns true if same
*/
bool GameMode::compareGrid(char** thisGen, char** nextGen)
{
  for (int row = 0; row < rows; ++row)
  {
    for (int col = 0; col < cols; ++col)
    {
      if (thisGen[row][col] != nextGen[row][col])
      {
        return false;
      }
    }
  }
  return true;
}

/**
Returns true if stable
*/
bool GameMode::getStable()
{
  return stable;
}

/**
Prints out the gameboard
*/
void GameMode::printBoard()
{
  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      cout << thisGen[r][c];
    }
    cout << endl;
  }
}

/**
Returns current genCount
*/
int GameMode::getGenCount()
{
  return genCount;
}
