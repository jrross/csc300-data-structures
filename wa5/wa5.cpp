#include "functions.h"

	//g++ -o wa5 wa5.cpp functions.cpp functions.h rectangle.h rectangle.cpp -lglut -lGL -lGLU -lm

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutCreateWindow("wa5");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutReshapeFunc(reshape);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	return 0;
}
