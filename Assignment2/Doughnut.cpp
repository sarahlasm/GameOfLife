#include "Doughnut.h"

  /**
  Inherits constructor from GameMode
  */
  Doughnut::Doughnut(const int ROWS, const int COLS):GameMode(ROWS, COLS)
  {
  }

  Doughnut::~Doughnut()
  {

  }

  /**
  checkNeighbors uses modulus logic to return number of neighbors a cell has in doughnut mode
  Parameters row and col are the row and column of the current cell
  */
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
