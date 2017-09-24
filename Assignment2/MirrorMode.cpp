#include "GameMode.h"
#include "GameMode.cpp"
#include "MirrorMode.h"

using namespace std;

   MirrorMode::MirrorMode(int row, int col)
   {
   	  new GameMode(row, col) mode; 
      genCount = 0;
      thisGen == &grid[0][0];
   }
   
   MirrorMode::~MirrorMode()
   {
   
   }
   
   int MirrorMode::checkNeighbors(int row, int col)
   {
      int numNeighbors = 0;
      
      if (row > 0 && row < GameMode::getRow() && col > 0 && col < GameMode::getCol())
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
      
      else if (row == 0)
      {
         if (col == 0)
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
                     if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
                        numNeighbors += 2;
                     else
                        ++numNeighbors;
                  }
               }
            }
         }
         
         else if (col == GameMode::getCol())
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
                     if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
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
            for (int i = row; i < row + 2; ++i)
            {
               for (int j = col - 1; j < col + 2; ++j)
               {
                  if (i == row && j == col)
                     continue;
                  else if (GameMode::isOccupied(thisGen[i][j]))
                  {
                     if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
                        numNeighbors += 2;
                     else
                        ++numNeighbors;
                  }
               }
            }
         }
      } //end row == 0
      
      else if (row == GameMode::getRow())
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
                     if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
                        numNeighbors += 2;
                     else
                        ++numNeighbors;
                  }
               }
            }
         }
         
         else if (col == GameMode::getCol())
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
                     if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
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
                     if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
                        numNeighbors += 2;
                     else
                        ++numNeighbors;
                  }
               }
            }
         }
      } //end row == GameMode::getRow()
      
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
      	  	  	  	  	  if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
      	  	  	  	  	  	  numNeighbors += 2;
      	  	  	  	  	  else
      	  	  	  	  	  	  ++numNeighbors;
      	  	  	  	  }
      	  	  	  }
      	  	  }
      	  }
      	  
      	  else if (row == GameMode::getRow())
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
      	  	  	  	  	  if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
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
      	  	  	  	  	  if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
      	  	  	  	  	  	  numNeighbors += 2;
      	  	  	  	  	  else
      	  	  	  	  	  	  ++numNeighbors;
      	  	  	  	  }
      	  	  	  }
      	  	  }
      	  }      	  	  
      }//end col == 0
      
      else if (col == GameMode::getCol())
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
      	  	  	  	  	  if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
      	  	  	  	  	  	  numNeighbors += 2;
      	  	  	  	  	  else
      	  	  	  	  	  	  ++numNeighbors;
      	  	  	  	  }
      	  	  	  }
      	  	  }
      	  }
      	  
      	  else if (row == GameMode::getRow())
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
      	  	  	  	  	  if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
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
      	  	  	  	  	  if (i == 0 || j == 0 || i == GameMode::getRow() || j == GameMode::getCol())
      	  	  	  	  	  	  numNeighbors += 2;
      	  	  	  	  	  else
      	  	  	  	  	  	  ++numNeighbors;
      	  	  	  	  }
      	  	  	  }
      	  	  }
      	  }      	  	  
      }//end col==GameMode::getCol()
      return numNeighbors;
   }
   
   void MirrorMode::changeGrid()
   {
   	   
   }
