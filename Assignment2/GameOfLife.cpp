#include "GameMode.h"
#include "Doughnut.h"

class GameOfLife
{
  int main()
  {

    char thisGen[6][5];

    thisGen[3][3] = 'X';
    thisGen[4][2] = 'X';
    thisGen[3][2] = 'X';

    for (int i = 0; i < 6; ++i)
    {
      for (int j = 0; j < 5; ++j)
      {
        cout << thisGen[i][j];
      }
      cout << endl;
    }

    Doughnut myGame = new Doughnut(thisGen);
    cout << myGame.checkNeighbors(4, 3);

  }

};
