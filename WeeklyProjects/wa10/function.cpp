#include "function.h"

/***************************************************************************//**
 * @brief Routine to initialize the disjoint set
 *
 * @param[in] ds : The disjoint set to initilize
 * @param[in] size : The size of the universe of items
 ******************************************************************************/
void initializeDS(DisjointSet &ds, int size)
{
   for (int i = 0 ; i < size ; i++)
      ds.makeSet(i);

   ds.makeSet(TOP_SET);
   ds.makeSet(BOTTOM_SET);
}

/***************************************************************************//**
 * @brief Routine to update the title of the display window
 *
 * @param[in] openCount : The number of cells that have been opened so far
 * @param[in] size : The size of the universe of items
 ******************************************************************************/
void updateTitle(int openCount, int size)
{
   stringstream ss;
   ss << "Open: " << fixed << setprecision(5) << (static_cast<double>(openCount)/(static_cast<double>(size))) << " Press any <esc> or 'q' to quit - <spc> to pause";
   glutSetWindowTitle(ss.str().c_str());
}   

/***************************************************************************//**
 * @brief Routine to check if there is a percolation path from top to bottom
 *
 * @param[in] ds : The disjoint set
 ******************************************************************************/
bool checkForPath(DisjointSet& ds)
{
   return (ds.findSet(TOP_SET) == ds.findSet(BOTTOM_SET));
}

/***************************************************************************//**
 * @brief Routine to check if there is a percolation path from top to bottom
 *
 * @param[inout] grid : The grid used to display the state of the network
 * @param[in] whichCell : The latest cell to be opened
 * @param[inout] ds : The disjoint set
 ******************************************************************************/
void colorConnected(vector<CellStatus>& grid, unsigned int whichCell, DisjointSet& ds)
{
   unsigned int N = sqrt(grid.size());
   grid[whichCell] = OPEN_CELL;
   if (whichCell / N != 0 && grid[whichCell-N] == OPEN_CELL)
      ds.Union(whichCell-N, whichCell);
   if (whichCell / N != N-1 && grid[whichCell+N] == OPEN_CELL)
      ds.Union(whichCell+N, whichCell);
   if (whichCell % N != 0 && grid[whichCell-1] == OPEN_CELL)
      ds.Union(whichCell-1, whichCell);
   if (whichCell % N != N-1 && grid[whichCell+1] == OPEN_CELL)
      ds.Union(whichCell+1, whichCell);

   if (whichCell / N == 0)
      ds.Union(whichCell, TOP_SET);
 
   if (whichCell / N == N-1)
      ds.Union(whichCell, BOTTOM_SET);
}

/***************************************************************************//**
 * @brief Routine to open up a currently blocked cell
 *
 * @par Description 
 *    Pick a random cell that is blocked and open it
 *
 * @param[inout] grid : The grid used to display the state of the network
 ******************************************************************************/
int openACell(vector<CellStatus>& grid)
{
   int openCell = rand() % GRID_SIZE;
   while (grid[openCell] != BLOCKED_CELL)
      openCell = rand() % GRID_SIZE;

   grid[openCell] = OPEN_CELL;
   drawCell(openCell, OPEN_CELL, grid.size());
   return openCell;
}
