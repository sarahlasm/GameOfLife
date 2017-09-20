#include "GameMode.h"

class Doughnut : GameMode
{
private:
  char thisGen[6][5];
public:
  Doughnut(char thisGen[6][5]);
  ~Doughnut();
   int checkNeighbors(int row, int col);
};
