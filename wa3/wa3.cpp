#include <iostream>
#include <GL/freeglut.h>

using namespace std;

#define ESCAPE_KEY 27

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
	cout << "Changed Display Dimensions" << endl;
}

void keyboard(unsigned char key, int x, int y)
{
   if (key == ESCAPE_KEY)
      glutLeaveMainLoop();
   else
      cout << key << " key pressed at location: " << x << ", " << y << endl;
}

void mouseClick(int button, int state, int x, int y)
{
	switch(button)
	{
		case 0: cout << "Left click ";
			break;
		case 1: cout << "Middle click ";
			break;
		case 2: cout << "Right click ";
			break;
		case 3: cout << "Scroll wheel forward ";
			break;
		case 4: cout << "Scroll wheel down ";
	}
	
	switch(state)
	{
		case 0: cout << "pushed ";
			break;
		case 1: cout << "released ";
			break;
	}
	
	cout << "at location: " << x << ", " << y << endl;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("wa3");
 	glutDisplayFunc(display);
    	glutKeyboardFunc(keyboard);
    	glutMouseFunc(mouseClick);
    	glClearColor(0.0f, 0.5f, 0.5f, 0.0f);
	glutMainLoop();
	return 0;
}
