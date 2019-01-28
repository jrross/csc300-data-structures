#ifndef __DRAWGRID_H_
#define __DRAWGRID_H_
#include <cmath>
#include <vector>
#include <iostream>
#include <GL/freeglut.h>
#include "disjoint.h"

using namespace std;

typedef unsigned char byte;

enum CellStatus { BLOCKED_CELL, OPEN_CELL, CONNECTED_CELL };

const float Colors[][3] = {
   {0.0, 0.0, 0.0},
   {1.0, 1.0, 1.0},
   {0.2, 0.2, .88},
}; 

void drawCell(int, CellStatus, int);
void drawGrid(vector<CellStatus> grid, DisjointSet& ds, int top_set, bool);
void DrawRectangle(float x1, float y1, float x2, float y2, const float color[], bool filled=false);
void DrawTextString(std::string str, int x, int y, const float color[] );

#endif
