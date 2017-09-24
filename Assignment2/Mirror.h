#include "GameMode.h"

class Mirror : GameMode
{
  public:
    Mirror (const int ROWS, const int COLS);
    ~Mirror();
    int checkNeighbors(int row, int col);
  private:
};
