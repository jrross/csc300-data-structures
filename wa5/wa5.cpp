#include <iostream>
#include <GL/freeglut.h>

using namespace std;

	//g++ -o wa5 wa5.cpp -lglut -lGL -lGLU -lm

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
		glutLeaveMainLoop();
}

void mouseClick(int button, int state, int x, int y)
{
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutCreateWindow("wa5");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	return 0;
}
