#include "functions.h"
using namespace std;
//jeff-rectangle
//luke-line
//ben-elipse
//g++ -o main line.cpp ellipse.cpp FilledEllipse.cpp rectangle.cpp 
//FilledRectangle.cpp functions.cpp main.cpp -lglut -lGL -lGLU -lm -std=gnu++0x
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(750, 520);
	glutCreateWindow("SDSM&T Paint");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutReshapeFunc(reshape);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	return 0;
}
