#include <iostream>
#include <GL/freeglut.h>

using namespace std;

#define ESCAPE_KEY 27

void print(int type, int x, int y, char key, int state)
{
	if (type == 0) //type 0 for first 3 inputs
		{
		cout << "No Actions." << endl;
		return;
		}

	if (type == 1) //type 1 is mouse
		{
		switch(key)
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
		return;		
		}

	if (type == 2) //type 2 is keyboard
		{
		cout << key << " key pressed at location: " << x << ", " << y << endl;
		return;
		}

	if (type == 3) //type 3 is display
		{
		cout << "Changed Display Dimensions" << endl;
		return;
		}
}






void prev3 (int type, int x, int y, char key, int state )
{	
	static int tPrev[3] = {0, 0, 0}; //keeps track of last 3 elements
	static int xPrev[3] = {0, 0, 0};
	static int yPrev[3] = {0, 0, 0};
	static char kPrev[3] = {0, 0, 0};
	static int sPrev[3] = {0, 0, 0};

	//outputs most recent event first	
	cout << "==============================================" << endl;
	print(tPrev[0], xPrev[0], yPrev[0], kPrev[0], sPrev[0]);
	print(tPrev[1], xPrev[1], yPrev[1], kPrev[1], sPrev[1]);	
	print(tPrev[2], xPrev[2], yPrev[2], kPrev[2], sPrev[2]);
	cout << "==============================================" << endl;
	
	tPrev[2] = tPrev[1];	//moving everything down 1 after printing
	xPrev[2] = xPrev[1];
	yPrev[2] = yPrev[1];
	kPrev[2] = kPrev[1];
	sPrev[2] = sPrev[1];

	tPrev[1] = tPrev[0];
	xPrev[1] = xPrev[0];
	yPrev[1] = yPrev[0];
	kPrev[1] = kPrev[0];
	sPrev[1] = sPrev[0];	

	tPrev[0] = type;
	xPrev[0] = x;
	yPrev[0] = y;
	kPrev[0] = key;
	sPrev[0] = state;
	

	
}

void display() 
{
    	glClear(GL_COLOR_BUFFER_BIT);
    	glutSwapBuffers();
	prev3(3, 0, 0, 0, 0);
}

void keyboard(unsigned char key, int x, int y)
{
   	if (key == ESCAPE_KEY)
      		glutLeaveMainLoop();
   	else
      		prev3(2, x, y, (char)key, 0);
}

void mouseClick(int button, int state, int x, int y)
{
	prev3(1, x, y, char(button), state);
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
