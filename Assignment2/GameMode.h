/** Reads through arrays, checks neighbors, facilitates generation changes,
*/

#include <iostream>

using namespace std;

class GameMode
{
  public:
    GameMode();
    ~GameMode();
    int checkNeighbors();
  private:
    char** thisGen;
    char** nextGen;
    int genCount;
}
