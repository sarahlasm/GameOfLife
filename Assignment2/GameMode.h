/** Reads through arrays, checks neighbors, facilitates generation changes,
*/

#include <iostream>

using namespace std;

class GameMode
{
  public:
    GameMode(char thisGen[6][5]);
    ~GameMode();
    virtual int checkNeighbors(int row, int col);
    void changeGrid();
    bool isOccupied(char c);
  private:
    char thisGen[6][5];
    char nextGen[6][5];
    int genCount;
};
