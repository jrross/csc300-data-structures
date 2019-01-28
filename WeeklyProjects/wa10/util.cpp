#include "util.h"

// callback function that tells OpenGL how to handle keystrokes
void keyboard(const byte key, const int x, const int y) {
   switch (key)
   {
       case 'q':
       case 'Q':
       case ESC:
           glutLeaveMainLoop();
   }
	utilityCentral(new KeyboardEvent(key,x,y));
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   utilityCentral(new DisplayEvent);
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   glLoadIdentity();           // initialize transformation matrix
   gluOrtho2D(0.0,w,0.0,h);
   glViewport(0,0,w,h);        // adjust viewport to new window
   glutPostRedisplay();
   utilityCentral(new ReshapeEvent(w, h));
}

void ticktock(int value)
{
   utilityCentral(new TickTockEvent);
   glutTimerFunc(value, ticktock, value);
}

void utilityCentral(Event *event)
{
   static vector<CellStatus> grid(GRID_SIZE, BLOCKED_CELL);
   static DisjointSet ds;

   event->action(grid, ds);
   delete event;
}
