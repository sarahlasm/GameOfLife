/**
@TODO
  Make checkNeighbors() more efficient (at least in Doughnut)
  Fill starting gameboard with random percentage of occupied cells
  Allow person to input their own file
  Kill Sarah
  Write output to file if necessary
  Check after every generation if simulation is static

*/

#include "Doughnut.h"

  int main(int argc, char** argv)
  {
    const int ROWS = 5;
    const int COLS = 6;

    Doughnut* d = new Doughnut(ROWS, COLS);

    (*d).setArray(0, 3);
    (*d).setArray(1, 5);
    cout << (*d).checkNeighbors(0, 2);
    delete d;

    return 0;
  }
