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

    int rows = getRows();
    int cols = getCols();

    neighborCount = isOccupied(thisGen[((row-1+rows) % rows)][((col-1+cols) % cols)])
    +               isOccupied(thisGen[row % rows][((col-1+cols) % cols)])
    +               isOccupied(thisGen[(row+1) % rows][(col-1+cols) % cols])
    +               isOccupied(thisGen[((row-1+rows) % rows)][col])
    +               isOccupied(thisGen[(row+1) % rows][col])
    +               isOccupied(thisGen[((row-1+rows) % rows)][(col+1) % cols])
    +               isOccupied(thisGen[(row)][(col+1) % cols])
    +               isOccupied(thisGen[(row+1) % rows][(col+1) % cols]);

    return neighborCount;
  }
