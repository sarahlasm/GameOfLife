/**
Sarah Lasman and Amanda Galemmo
2278776          2270004
lasma101@mail.chapman.edu  galem100@mail.chapman.edu
CS 350 Section 3
Assignment #2
*/

#include "Doughnut.h"
#include "Classic.h"
#include "Mirror.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

/**
Main method
Asks user for input, and what game mode/file type/parameters/etc. they want
Creates instance of their game type
Prints gameboard each generation
Deletes object and ends simulation after 500 generations or the board becomes stable
*/
  int main(int argc, char** argv)
  {
    GameMode* newGame;

    bool allParametersEntered = false; //Checks to see if all file parameters (below) have been entered
    bool inputCheck = false;
    bool modeCheck = false;
    bool enterCheck = false;
    bool pauseCheck = false;
    bool outputCheck = false;

    string randomOrFile; //Is the input random, or from a file
    int rows = 0;
    int cols = 0;
    double popDensity = 0.0;
    string fileName;
    string input;
    string mode;
    string autoOrNo;
    bool enterToggle; //false = auto
    string pauseOrNo;
    bool pauseToggle;
    string outputTo;
    string outputFile;
    bool outputToggle;
    ifstream inFile;


    while (!allParametersEntered)
    {
      while (!inputCheck)
      {
        cout << "Do you want a random map file (r) or a file path (f)?" << endl;
        cin >> randomOrFile;
        if (randomOrFile == "r" || randomOrFile == "random")
        {
          cout << "Number of rows?" << endl;
          cin >> rows;
          while (cin.fail() || rows < 1)
          {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> rows;
          }
          cout << "Number of columns?" << endl;
          cin >> cols;
          while (cin.fail() || cols < 1)
          {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> cols;
          }
          cout << "Enter a decimal between 0 and 1 for population density." << endl;
          cin >> popDensity;
          while (cin.fail() || popDensity > 1 || popDensity < 0)
          {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> popDensity;
          }
          inputCheck = true;
          break;
        }
        else if (randomOrFile == "f" || randomOrFile == "file")
        {
          cout << "File path?" << endl;
          cin >> fileName;
          ifstream inFile(fileName);
          try
          {
            if (getline(inFile, input)) rows = stoi(input);
            if (getline(inFile, input)) cols = stoi(input);
            inFile.close();
          }
          catch (exception e)
          {
            cerr << "Your file is formatted incorrectly. Please edit the file and reload the program." << endl;
            inFile.close();
            return -1;
          }
          inputCheck = true;
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
          modeCheck = true;
          break;
        }
        else if (mode == "m" || mode == "mirror")
        {
          newGame = new Mirror(rows, cols);
          modeCheck = true;
          break;
        }
        else if (mode == "c" || mode == "classic")
        {
          newGame = new Classic(rows, cols);
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
          cin >> outputFile;
          allParametersEntered = true;
          outputToggle = true;
          outputCheck = true;
          break;
        }
        else if (outputTo == "n" || outputTo == "no")
        {
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
          enterCheck = true;
          break;
        }
        else if (autoOrNo == "t" || autoOrNo == "toggle")
        {
          enterToggle = true;
          allParametersEntered = true;
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
          cout << "Would you like to have a pause (p) between each generation, or no (n)?" << endl;
          cin >> pauseOrNo;

          if (pauseOrNo == "p" || pauseOrNo == "pause")
          {
            pauseToggle = true;
            allParametersEntered = true;
            pauseCheck = true;
            break;
          }
          else if (pauseOrNo == "n" || pauseOrNo == "no")
          {
            allParametersEntered = true;
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
          allParametersEntered = true;
          pauseToggle = false;
          pauseCheck = true;
          break;
        }
      }
    }

    if (randomOrFile == "r" || randomOrFile == "random")
      (*newGame).setUpBoard(popDensity);
    else if (randomOrFile == "f" || randomOrFile == "file")
    {
      string input2;
      ifstream inFile2(fileName);
      int r = 0;
      inFile2 >> input2;
      inFile2 >> input2;
      while (inFile2 >> input2)
      {
          for (int c = 0; c < cols; ++c)
          {
            if (input2[c] == 'X')
            {
              (*newGame).setArray(r,c);
            }
          }
          r++;
      }
      inFile2.close();
    }

    int genCount = (*newGame).getGenCount();

    if (outputToggle)
    {
      ofstream theOutputFile;
      theOutputFile.open(outputFile);
      while ((*newGame).getStable() == false && genCount < 500)//initial pass at this
    	{
    		theOutputFile << genCount << endl;
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
        cout << "Press enter to toggle the next generation." << endl;
        while ((*newGame).getStable() == false && genCount < 500)
      	{
      		cout << genCount << endl;
      		(*newGame).printBoard();
      		(*newGame).changeGrid();
      		++genCount;
          cin.ignore();
      	}
      }
      else if (pauseToggle)
      {
        while ((*newGame).getStable() == false && genCount < 500)
      	{
      		cout << genCount << endl;
      		(*newGame).printBoard();
      		(*newGame).changeGrid();
      		++genCount;
          usleep(100000);
      	}
      }
      else
      {
        while ((*newGame).getStable() == false && genCount < 500)
      	{
      		cout << genCount << endl;
      		(*newGame).printBoard();
      		(*newGame).changeGrid();
      		++genCount;
        }
      }
    }
    delete newGame;
  	if ((randomOrFile == "f" || randomOrFile == "file") && genCount <= 1)
      cout << "If your results aren't what you expected, check to make sure your file is formatted properly!";
    return 0;

  }
