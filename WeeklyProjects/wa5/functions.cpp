#include "functions.h"


void DrawFilledRectangle(float x1, float y1, float x2, float y2, const float color[])
{
   glBegin(GL_POLYGON);
      glColor3fv(color);
      glVertex2f(x1, y1);
      glVertex2f(x2, y1);
      glVertex2f(x2, y2);
      glVertex2f(x1, y2);
   glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
		glutLeaveMainLoop();
	event *ev = new kb(key, x, y);
	print(ev);
	delete ev;
}

void mouseClick(int button, int state, int x, int y)
{
	event *ev = new mouse(button, state, x, y);
	print(ev);
	delete ev;
}

void print(event *ev)
{
	glClear(GL_COLOR_BUFFER_BIT);
	ev->draw();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
    glMatrixMode( GL_PROJECTION );      // use an orthographic projection
    glLoadIdentity();                   // initialize transformation matrix
    gluOrtho2D( 0.0, w, 0.0, h );       // make OpenGL coordinates
    glViewport( 0, 0, w, h );           // the same as the screen coordinates
}

void DrawCharacter(char ch, int x, int y, const float color[])
{
   glColor3fv(color);
   glRasterPos2i(x, y);
   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch);
}


