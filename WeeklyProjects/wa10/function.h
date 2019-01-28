#ifndef __FUNCTION_H
#define __FUNCTION_H
#include <vector>
#include <sstream>
#include <iomanip>
#include "drawGrid.h"
#include "disjoint.h"

using namespace std;

#define GRID_SIZE 900
#define TOP_SET GRID_SIZE+1
#define BOTTOM_SET TOP_SET+1

/// convenience typedef
typedef unsigned char byte;

#define ESC 27

void initializeDS(DisjointSet &, int);
void updateTitle(int, int);
bool checkForPath(DisjointSet&);
void colorConnected(vector<CellStatus>&, unsigned int, DisjointSet&);
int openACell(vector<CellStatus>&);

#endif
