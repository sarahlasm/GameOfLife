#include <GameMode.h>

class GameMode
{

  GameMode::GameMode()
  {
    genCount = 0;
  }

  GameMode::~GameMode()
  {

  }

  int GameMode::checkNeighbors(int row, int col)
  {
    return 0;
  }

  void GameMode::changeGrid()
  {
    int numNeighbors;
    for (int row = 0; row < thisGen.size(); ++row)
    {
      for (int col = 0; col < thisGen[0].size(); ++col)
      {
        numNeighbors = checkNeighbors(row, col);
        if (numNeighbors == 2)
          nextGen[row][col] = thisGen[row][col];
        else if (numNeighbors == 3)
          nextGen[row][col] = 'X';
        else
          nextGen[row][col] = '-';

      }
    }
    thisGen =& nextGen;
  }
}
