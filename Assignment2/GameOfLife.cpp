/**
@TODO
  Make checkNeighbors() more efficient (at least in Doughnut)
  Fix Doughnut corner cases
  Allow person to input their own file
  Input exception handling
  Write output to file if necessary //kk
  Check after every generation if simulation is static //ye

*/

#include "Doughnut.h"
#include "Classic.h"
#include "Mirror.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

  int main(int argc, char** argv)
  {
    GameMode* newGame;

    int checkpoints = 0;
    bool inputCheck = false;
    bool modeCheck = false;
    bool enterCheck = false;
    bool pauseCheck = false;
    bool outputCheck = false;

    string mapOrFile = "";
    int rows = 0;
    int cols = 0;
    double popDensity = 0.0;
    string fileName = "";
    string input;
    string mode;
    string autoOrNo;
    bool enterToggle; //false = auto
    string pauseOrNo;
    bool pauseToggle;
    string outputTo;
    string outputFile;
    bool outputToggle;


    while (checkpoints < 5)
    {
      while (!inputCheck)
      {
        cout << "Do you want a random map file (r) or a file path (f)?" << endl;
        cin >> mapOrFile;
        if (mapOrFile == "r" || mapOrFile == "random")
        {
          cout << "Number of rows?" << endl;
          cin >> rows; //check this
          cout << "Number of columns?" << endl;
          cin >> cols; //check this
          cout << "Enter a decimal between 0 and 1 for population density." << endl;
          cin >> popDensity; //check this
          ++checkpoints;
          inputcheck = true;
          break;
        }
        else if (mapOrFile == "f" || mapOrFile == "file")
        {
          cout << "File path?" << endl;
          cin >> fileName;
          ifstream inFile(fileName);
          if (getline(inFile, input)) rows = stoi(input);
          if (getline(inFile, input)) cols = stoi(input);
          ++checkpoints;
          inputcheck = true;
          break;
        }
        else
        {
          cout << "Please enter a valid input." << endl;
          continue;
        }
      }
      while (!modeCheck)
      {
        cout << "What kind of mode do you want? Classic (c), doughnut (d), or mirror (m)?" << endl;
        cin >> mode;

        if (mode == "d" || mode == "doughnut")
        {
          newGame = new Doughnut(rows, cols);
          ++checkpoints;
          modeCheck = true;
          break;
        }
        else if (mode == "m" || mode == "mirror")
        {
          newGame = new Mirror(rows, cols);
          ++checkpoints;
          modeCheck = true;
          break;
        }
        else if (mode == "c" || mode == "classic")
        {
          newGame = new Classic(rows, cols);
          ++checkpoints;
          modeCheck = true;
          break;
        }
        else
        {
          cout << "Please enter a valid input." << endl;
          continue;
        }
      }
      while (!outputCheck)
      {
        cout << "Would you like to output to a file? (y/n)" << endl;
        cin >> outputTo;
        if (outputTo == "y" || outputTo == "yes")
        {
          cout << "Name of file?" << endl;
          cin >> outputfile;
          ++checkpoints;
          outputToggle = true;
          outputCheck = true;
          break;
        }
        else if (outputTo == "n" || outputTo == "no")
        {
          ++checkpoints;
          outputToggle = false;
          outputCheck = true;
          break;
        }
        else
        {
          cout << "Please provide valid input." << endl;
          continue;
        }
      }
      while (!enterCheck && !outputToggle)
      {
        cout << "Would you like for the output to be automatic (a) or toggled (t)?" << endl;
        cin >> autoOrNo;

        if (autoOrNo == "a" || autoOrNo == "auto" || autoOrNo == "automatic")
        {
          enterToggle = false;
          ++checkpoints;
          enterCheck = true;
          break;
        }
        else if (autoOrNo == "t" || autoOrNo == "toggle")
        {
          enterToggle = true;
          ++checkpoints;
          enterCheck = true;
          break;
        }
        else
        {
          cout << "Please enter valid input." << endl;
          continue;
        }
      }
      while (!pauseCheck && !outputToggle)
      {
        if (!enterToggle)
        {
          cout << "Would you like to have a pause (p) between each generation?" << endl;
          cin >> pauseOrNo;

          if (pauseOrNo == "p" || pauseOrNo == "pause")
          {
            pauseToggle = true;
            ++checkpoints;
            pauseCheck = true;
            break;
          }
          else
          {
            cout << "Please enter valid input." << endl;
            continue;
          }
        }
        else
        {
          ++checkpoints;
          pauseToggle = false;
          pauseCheck = true;
          break;
        }
      }
    }

    if (mapOrFile == "r" || mapOrFile == "random")
      (*newGame).setUpBoard(popDensity);
    else if (mapOrFile == "f" || mapOrFile == "file")
    {
      int r = 0;
      while (inFile >> input)
      {
          for (int c = 0; c < cols; ++c)
          {
            if (input[c] == 'X')
              (*newGame).setArray(r,c);
          }
          r++;
      }
    //  (*newGame).printBoard();
    }

    if (outputToggle)
    {
      ofstream theOutputFile;
      theOutputFile.open(outputFile);
      theOutputFile << genCount;
      while ((*newGame).getStable() == false && genCount < 500)//initial pass at this
    	{
    		theOutputFile << genCount;
    		for (int row = 0; row < rows; ++row)
    		{
    			for (int col = 0; col < cols; ++col)
    			{
    				theOutputFile << (*newGame).getThisGen()[row][col];
    			}
    			theOutputFile << endl;
    		}
    		(*newGame).changeGrid();
    		++genCount;
    	}
      theOutputFile.close();
    }
    else
    {
      if (enterToggle)
      {
        cout << "Press any key to toggle the next generation." << endl;
        while ((*newGame).getStable() == false && genCount < 500)
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
          cin.ignore();
      	}
      }
      else if (pauseToggle) //FIGURE OUT HOW TO IMPLEMENT THIS
      {
        while ((*newGame).getStable() == false && genCount < 500)
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
      }
      else
      {
        while ((*newGame).getStable() == false && genCount < 500)
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
      }
    }
  	/*while ((*newGame).getStable() == false)//initial pass at this
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
  	}*/
    return 0;

  }
