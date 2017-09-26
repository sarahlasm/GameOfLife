#include "GameMode.h"

class Classic : public GameMode
{
  public:
    Classic(const int ROWS, const int COLS);
    ~Classic();
    int checkNeighbors(int row, int col);
  private:
};
