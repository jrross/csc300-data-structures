#include "event.h"

/// Constructors for the derived event classes
ReshapeEvent::ReshapeEvent(int w, int h) : w(w), h(h) {}
KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : key(k), x(x), y(y){}

/// The action method for the DisplayEvent
void DisplayEvent::action(vector<CellStatus>& grid, DisjointSet &ds)
{
   static int openCount = 0;
   int whichCell = openACell(grid);
   
   colorConnected(grid, whichCell, ds);
   openCount++;
   updateTitle(openCount, GRID_SIZE);
   drawGrid(grid, ds, TOP_SET, true);
}

/// The action method for the ReshapeEvent
void ReshapeEvent::action(vector<CellStatus>& grid, DisjointSet &ds)
{
   drawGrid(grid, ds, TOP_SET, true);
}

/// The action method for the TickTockEvent
void TickTockEvent::action(vector<CellStatus>& grid, DisjointSet &ds)
{
   if (!checkForPath(ds)) glutPostRedisplay();
}

/// The action method for the KeyboardEvent
void KeyboardEvent::action(vector<CellStatus>& grid, DisjointSet &ds) {}

/// The action method for the InitEvent
void InitEvent::action(vector<CellStatus>& grid, DisjointSet &ds)
{
   for (int i = 0 ; i < GRID_SIZE ; i++)
      ds.makeSet(i);

   ds.makeSet(TOP_SET);
   ds.makeSet(BOTTOM_SET);
   drawGrid(grid, ds, TOP_SET, true);
}
