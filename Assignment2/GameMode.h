/** Reads through arrays, checks neighbors, facilitates generation changes,
*/

#include <iostream>

using namespace std;

class GameMode
{
  public:
    GameMode(const int ROWS, const int COLS);
    ~GameMode();
    virtual int checkNeighbors(int row, int col);
    void changeGrid();
    bool isOccupied(char c);
    char** getThisGen();
    char** getNextGen();
    int getRows();
    int getCols();
  private:
    char** thisGen;
    char** nextGen;
    int genCount;
    // const int ROWS;
    // const int COLS;
};
