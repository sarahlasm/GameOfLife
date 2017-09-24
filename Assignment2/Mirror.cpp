#include "Mirror.h"

using namespace std;

Mirror::Mirror (const int ROWS, const int COLS):GameMode(ROWS, COLS)
{

}

Mirror::~Mirror()
{

}

int Mirror::checkNeighbors(int row, int col)
{
  char** thisGen = getThisGen();
  int numNeighbors = 0;

  if (row > 0 && row < GameMode::getRows() && col > 0 && col < GameMode::getCols())
  {
     for (int i = row - 1; i < row + 2; ++i)
     {
        for (int j = col - 1; j < col + 2; ++j)
        {
           if (i == row && j == col)
              continue;
           else if (GameMode::isOccupied(thisGen[i][j]))
              ++numNeighbors;
        }
     }
  } //end center check
}

else if (row == GameMode::getRows())
{
   if (col == 0)
   {
      numNeighbors += 2;
      for (int i = row - 1; i < row + 1; ++i)
      {
         for (int j = col; j < col + 2; ++j)
         {
            if (i == row && j == col)
               continue;
            else if (GameMode::isOccupied(thisGen[i][j]))
            {
               if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                  numNeighbors += 2;
               else
                  ++numNeighbors;
            }
         }
      }
   }

   else if (col == GameMode::getCols())
   {
      numNeighbors += 2;
      for (int i = row - 1; i < row + 1; ++i)
      {
         for (int j = col - 1; j < col + 1; ++j)
         {
            if (i == row && j == col)
               continue;
            else if (GameMode::isOccupied(thisGen[i][j]))
            {
               if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                  numNeighbors += 2;
               else
                  ++numNeighbors;
            }
         }
      }
   }

   else
   {
      ++numNeighbors;
      for (int i = row - 1; i < row + 1; ++i)
      {
         for (int j = col - 1; j < col + 2; ++j)
         {
            if (i == row && j == col)
               continue;
            else if (GameMode::isOccupied(thisGen[i][j]))
            {
               if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                  numNeighbors += 2;
               else
                  ++numNeighbors;
            }
         }
      }
   }
} //end row == GameMode::getRows()

else if (col == 0)
{
    if (row == 0)
    {
        numNeighbors += 2;
        for (int i = row; i < row + 2; ++i)
        {
            for (int j = col; j < col + 2; ++j)
            {
                if (i == row && j == col)
                    continue;
                else if (GameMode::isOccupied(thisGen[i][j]))
                {
                    if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                        numNeighbors += 2;
                    else
                        ++numNeighbors;
                }
            }
        }
    }

    else if (row == GameMode::getRows())
    {
        numNeighbors += 2;
        for (int i = row - 1; i < row + 1; ++i)
        {
            for (int j = col; j < col + 2; ++j)
            {
                if (i == row && j == col)
                    continue;
                else if (GameMode::isOccupied(thisGen[i][j]))
                {
                    if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                        numNeighbors += 2;
                    else
                        ++numNeighbors;
                }
            }
        }
    }

    else
    {
        ++numNeighbors;
        for (int i = row - 1; i < row + 2; ++i)
        {
            for (int j = col; j < col + 2; ++j)
            {
                if (i == row && j == col)
                    continue;
                else if (GameMode::isOccupied(thisGen[i][j]))
                {
                    if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                        numNeighbors += 2;
                    else
                        ++numNeighbors;
                }
            }
        }
    }
}//end col == 0

else if (col == GameMode::getCols())
{
    if (row == 0)
    {
        numNeighbors += 2;
        for (int i = row; i < row + 2; ++i)
        {
            for (int j = col - 1; j < col + 1; ++j)
            {
                if (i == row && j == col)
                    continue;
                else if (GameMode::isOccupied(thisGen[i][j]))
                {
                    if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                        numNeighbors += 2;
                    else
                        ++numNeighbors;
                }
            }
        }
    }

    else if (row == GameMode::getRows())
    {
        numNeighbors += 2;
        for (int i = row - 1; i < row + 1; ++i)
        {
            for (int j = col - 1; j < col + 1; ++j)
            {
                if (i == row && j == col)
                    continue;
                else if (GameMode::isOccupied(thisGen[i][j]))
                {
                    if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                        numNeighbors += 2;
                    else
                        ++numNeighbors;
                }
            }
        }
    }

    else
    {
        ++numNeighbors;
        for (int i = row - 1; i < row + 2; ++i)
        {
            for (int j = col - 1; j < col + 1; ++j)
            {
                if (i == row && j == col)
                    continue;
                else if (GameMode::isOccupied(thisGen[i][j]))
                {
                    if (i == 0 || j == 0 || i == GameMode::getRows() || j == GameMode::getCols())
                        numNeighbors += 2;
                    else
                        ++numNeighbors;
                }
            }
        }
    }
}//end col==GameMode::getCols()
return numNeighbors;
}
