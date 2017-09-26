/**
@TODO
  Make checkNeighbors() more efficient (at least in Doughnut)
  Fix Doughnut corner cases
  Allow person to input their own file
  Input exception handling
  Kill Sarah
  Write output to file if necessary //kk
  Check after every generation if simulation is static //ye

*/

#include "Doughnut.h"
#include "Classic.h"
#include "Mirror.h"
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> origin/master
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
    int genCount;
    string autoOrNo;
    string pPause;
    string optOutput;
    string outputFile;
    bool yOutput;

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


  	cout << "Do you want the simulation to run automatically (a) or for you to toggle (t) each generation using the enter key?" << endl;
  	cin >> autoOrNo;

  	if (autoOrNo == "t" || autoOrNo == "toggle")
  	{
  		//do this later
  	}
  	else
  	{
  		//ugh do a switch UGH
  		cout << "Do you want a pause between each generation? (y/n)" << endl;
  		cin >> pPause;

  		if (pPause == "y" || pPause == "yes")
  		{
  			//do this later
  		}

  		else if (pPause == "n" || pPause == "no")
  		{
  			//do this later just skip it
  		}

  		else
  			cout << "pls y or n" << endl;
  	}

  	cout << "Do you want to output the results to another file? (y/n)" << endl;
  	cin >> optOutput;

  	if (optOutput == "y" || optOutput == "yes")
  	{
  		cout << "What file name?" << endl;
  		cin >> outputFile;
  		yOutput = true;
  	}

    if (mapOrFile == "r" || mapOrFile == "random")
      (*newGame).setUpBoard(popDensity);

  	while ((*newGame).getStable() == false)//initial pass at this
  	{
  		cout << genCount;
  		for (int row = 0; row < rows; ++row)
  		{
  			for (int col = 0; col < cols; ++col)
  			{
  				cout << (*newGame).getThisGen()[row][col];
  			}
  			cout << endl;
  		}
  		(*newGame).changeGrid();
  		++genCount;
  	}

    delete newGame;

    return 0;
  }
