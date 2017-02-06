#include <iostream>
#include <GL/freeglut.h>

using namespace std;

void reshape(int w, int h);
void DrawFilledRectangle(float x1, float y1, float x2, float y2, const float color[]);
void display();
void keyboard(unsigned char key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void DrawCharacter(char ch, int x, int y, const float color[]);
