#include "functions.h"
#include "rectangle.h"

int used = 0;

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
	if (used == 1)
	{
		rectangle r;
		static float x;
		static float y;
		x = glutGet(GLUT_WINDOW_WIDTH) / 2;
		y = glutGet(GLUT_WINDOW_HEIGHT) / 2;
		r.setCenter(x, y);
		float color[3] = { 1.0, 0.0, 0.0};
		float d[4];
		d[0] = r.getx1();
		d[1] = r.gety1();
		d[2] = r.getx2();
		d[3] = r.gety2();
		DrawFilledRectangle(d[0], d[1], d[2], d[3], color);
	}
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
		glutLeaveMainLoop();
}

void mouseClick(int button, int state, int x, int y)
{
	if (button == 0)
		used = 1;
	display();
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

