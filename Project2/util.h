/**************************************************************************//**
 * @file
 *****************************************************************************/
#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <iostream>
#include <GL/freeglut.h>
#include "event.h"
#include "image.h"

/// Convenience typedef to save typing
typedef unsigned char byte;

void utilityCentral(Event *event);
void display();
void keyboard(unsigned char, int, int);
void reshape(int, int);
void initOpenGL(Image *, char* argv);

#endif

