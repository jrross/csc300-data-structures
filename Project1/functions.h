/**************************************************************************//**
 * @file
 *****************************************************************************/

#include <iostream>
#include <GL/freeglut.h>
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include <vector>
using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void reshape(int w, int h);
void display();
void keyboard(unsigned char key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void printPalette(int action, currentProperties *curr);
vector<Shape*> makePalette();
void checkPalette(int x, int y, float (&rtcolor)[3]);
bool editShapes(int action, Shape *temp, int x = 0, int y = 0);

#endif
