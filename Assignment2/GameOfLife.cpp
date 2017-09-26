/**
@TODO
  Make checkNeighbors() more efficient (at least in Doughnut)
  Fix Doughnut corner cases
  Allow person to input their own file
  Input exception handling
  Kill Sarah
  Write output to file if necessary
  Check after every generation if simulation is static

*/

#include "Doughnut.h"
#include "Classic.h"
#include "Mirror.h"
#include <iostream>
#include <fstream>


  int main(int argc, char** argv)
  {
    GameMode* newGame;

    string mapOrFile;
    double popDensity;
    int rows = 0;
    int cols = 0;
    string fileName;
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
    else if (mapOrFile == "f" || mapOrFile == "file")
    {
      cout << "File path?" << endl;
      cin >> fileName;
      string input;
      ifstream inFile(fileName);
      if (getline(inFile, input)) rows = stoi(input);
      if (getline(inFile, input)) cols = stoi(input);
      cout << rows << " " << cols << endl;
      //Initialize array
    }
    cout << "What kind of mode do you want? Classic (c), doughnut (d), or mirror (m)?" << endl;
    cin >> mode;


    if (mode == "d" || mode == "doughnut")
      newGame = new Doughnut(rows, cols);
    else if (mode == "m" || mode == "mirror")
      newGame = new Mirror(rows, cols);
    else
      newGame = new Classic(rows, cols);

    if (mapOrFile == "r" || mapOrFile == "random")
      (*newGame).setUpBoard(popDensity);



    delete newGame;

    return 0;
  }
