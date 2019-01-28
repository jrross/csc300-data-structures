/***************************************************************************//**
@file
@brief interface for the utilityCentral
*******************************************************************************/
#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "drawGrid.h"
#include "disjoint.h"
#include "event.h"

using namespace std;

/// Pick a grid size that is equal to some integer N x N or it is likely to fail
#define GRID_SIZE 900
#define TOP_SET GRID_SIZE+1
#define BOTTOM_SET TOP_SET+1

/// convenience typedef
typedef unsigned char byte;

#define ESC 27

void display(void);
void reshape(int, int);
void ticktock(int);

/// The main hub for collecting the various events into a central location.
void utilityCentral(Event * event);
#endif /* UTIL_H_INCLUDED */
