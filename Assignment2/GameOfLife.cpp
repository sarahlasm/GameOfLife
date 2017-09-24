/**
@TODO
  Fix errors (see commit 9-23-17 - Error fixes for current errors)
  Implement Mirror and Classic modes (does Amanda have that?)
  Fill starting gameboard with random percentage of occupied cells
  Allow person to input their own file
  Kill Sarah
  Write output to file if necessary
  Check after every generation if simulation is static

*/

#include "Doughnut.h"

class GameOfLife
{
  int main()
  {
    const int ROWS = 5;
    const int COLS = 6;

    Doughnut* d = new Doughnut(ROWS, COLS);
    delete d;
  }

};
