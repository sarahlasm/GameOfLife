/**
@TODO
  Make checkNeighbors() more efficient (at least in Doughnut)
  Fix Doughnut corner cases
  Fill starting gameboard with random percentage of occupied cells
  Allow person to input their own file
  Kill Sarah
  Write output to file if necessary
  Check after every generation if simulation is static

*/

#include "Doughnut.h"



  int main(int argc, char** argv)
  {

    string mapOrFile;
    double popDensity;
    int rows = 0;
    int cols = 0;
    string mode;

    cout << "Do you want a random map file (r) or a file path (f)?" << endl;
    cin >> mapOrFile;
    if (mapOrFile == "r" || mapOrFile == "random")
    {
      cout << "Number of rows?" << endl;
      cin >> rows;
      cout << "Number of columns?" << endl;
      cin >> cols;
      cout << "Enter a decimal between 0 and 1 for population density." << endl;
      cin >> popDensity;
    }
    cout << "What kind of mode do you want? Classic (c), doughnut (d), or mirror (m)?" << endl;
    cin >> mode;


    Doughnut* d = new Doughnut(rows, cols);
    (*d).setUpBoard(popDensity);
    

    (*d).setArray(0, 3);
    (*d).setArray(1, 5);
    cout << (*d).checkNeighbors(0, 2);
    delete d;

    return 0;
  }
