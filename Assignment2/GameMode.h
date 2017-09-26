/** Reads through arrays, checks neighbors, facilitates generation changes,
*/
#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <iostream>

using namespace std;

class GameMode
{
  public:
    GameMode(const int ROWS, const int COLS);
    ~GameMode();
    virtual int checkNeighbors(int row, int col);
    void changeGrid();
    void printBoard();
    bool isOccupied(char c);
    char** getThisGen();
    char** getNextGen();
    int getRows();
    int getCols();
    void setArray(int row, int col);
    void compareGrid(char** thisGen, char** nextGen);
    bool getStable();
    void setUpBoard(double popDensity);
  private:
    char** thisGen;
    char** nextGen;
    int genCount;
    int rows;
    int cols;
    bool stable;
};
#endif
