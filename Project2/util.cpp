/**************************************************************************//**
 * @file
 *****************************************************************************/
#include "util.h"

using namespace std;

// glut callback functions
/**************************************************************************//**
 * @brief callback function that calls a function to modify the quad tree
 *
 * @param[in] event pointer to an event
 *****************************************************************************/
void utilityCentral(Event *event) {
    static QuadTree *quadTree = new QuadTree();

    event->action(quadTree);
}

/**************************************************************************//**
 * @brief callback function that calls utilitycentral with a diplay event
 *****************************************************************************/
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    utilityCentral(new DisplayEvent());
    glFlush();
}

/**************************************************************************//**
 * @brief callback function that calls a utility central with a reshape event
 *
 * @param[in] width   the width
 * @param[in] height  the height
 *****************************************************************************/
void reshape(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
    glViewport(0, 0, width, height);
    utilityCentral(new ReshapeEvent(width, height));
}

/**************************************************************************//**
 * @brief callback function that calls utility central with a keyboard event
 *
 * @param[in] key  the key pressed
 * @param[in] x    the x coordinate
 * @param[in] y    the y coordinate
 *****************************************************************************/
void keyboard(unsigned char key, int x, int y) {
    utilityCentral(new KeyboardEvent(key, x, y));
}

/**************************************************************************//**
 * @brief Glut initialization function
 *
 * @param[in] image  pointer to an image
 * @param[in] argv   commandline arguments
 *****************************************************************************/
void initOpenGL(Image *image, char* argv) {
    char name[] = "QuadTree ImageCompression";
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

    glutInitWindowSize(image->getWidth() * 2, image->getHeight());

    glutInitWindowPosition(50,50);      // initial window  position
    glutCreateWindow(name);      // window title

    utilityCentral(new InitEvent(image, argv));

    glClearColor(0,0,0,0);              // use black for glClear command
    glutDisplayFunc(display);           // how to redisplay window
    glutKeyboardFunc(keyboard);           // how to redisplay window
    glutReshapeFunc(reshape);           // how to resize window
}
