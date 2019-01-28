#include "events.h"
#include "functions.h"

void event::draw()
{}

void mouse::draw()
{
	float color[3] = {1.0, 0.0, 0.0};
	float w = glutGet(GLUT_WINDOW_WIDTH);
	float h = glutGet(GLUT_WINDOW_HEIGHT);
	DrawFilledRectangle(w/2 - 100, h/2 - 100, w/2 + 100, h/2 + 100, color);

}
mouse::mouse (int b, int s, int i, int j)
{
	button = b;
	state = s;
	x = i;
	y = j;

}

kb::kb (unsigned char k, int i, int j)
{
	key = k;
	x = i;
	y = j;
}

void kb::draw()
{
	float color[3] = {1.0, 1.0, 1.0};
	float h = glutGet(GLUT_WINDOW_HEIGHT);
	DrawCharacter((char)key, x, h - y, color);
}
