/***************************************************************************//**
 * @file
 * @brief Header file to be used with event.cpp
 ******************************************************************************/
#ifndef __EVENT_H_
#define __EVENT_H_
#include "image.h"
#include "quadTree.h"
#include <GL/freeglut.h>

/// Escape key is 27
#define ESCAPE_KEY 27

/*!
* @brief abstract base class for Events
*/
class Event {
    public:
        void virtual action(QuadTree*) = 0;/*!<action function*/
};

/*!
* @brief class for the display
*/
class DisplayEvent : public Event {
    public:
        void action(QuadTree*);/*!<action function*/
};

/*!
* @brief class for the keyboard
*/
class KeyboardEvent : public Event {
    unsigned char key;/*!<key that was pressed*/
    int x;/*!<x value of keypress*/
    int y;/*!<y value of keypress*/
    public:
        KeyboardEvent(unsigned char, int, int);/*!<constructor*/
        void action(QuadTree*);/*!<action function*/
};

/*!
* @brief class for reshaping event
*/
class ReshapeEvent : public Event {
    int width;/*!<new width*/
    int height;/*!<new height*/
    public:
        ReshapeEvent(int, int);/*!<constructor*/
        void action(QuadTree*);/*!<action function*/
};

/*!
* @brief class for initialization events
*/
class InitEvent : public Event {
    Image *image;/*!<pointer to array for original image*/
	char *CF;/*!<original compression factor*/
    public:
        InitEvent(Image*,char* argv);/*!<constructor*/
        void action(QuadTree*);/*!<action function*/
};

#endif
