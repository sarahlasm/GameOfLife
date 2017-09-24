#include "GameMode.h"

class Doughnut : public GameMode
{
private:
public:
  Doughnut(const int ROWS, const int COLS);
  ~Doughnut();
   int checkNeighbors(int row, int col);
};
