#include "GameMode.h"

using namespace std;

class MirrorMode
{
   public:
      MirrorMode(int row, int col);
      ~MirrorMode();
      int checkNeighbors(int row, int col);
      void changeGrid();
   private:
      char** thisGen;
      char** nextGen;
      int genCount;
};