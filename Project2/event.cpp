/**************************************************************************//**
 * @file
 * @brief functions to be used with event.h
 *****************************************************************************/
#include <string>
#include "event.h"

using namespace std;

// Event Constructors
ReshapeEvent::ReshapeEvent(int w, int h) : width(w), height(h) {}
KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : key(k),x(x),y(y){}
InitEvent::InitEvent(Image *img,char* argv) : image(img), CF(argv) {}

// Action methods for the various events

/*********************************************************************//*
* @par Description:
* A function to display the quadTree to the screen alongside the original
* image. Calculates and displays the quality factor, # of leaves, amount of
* memory the compressed image takes, the compression size and displays
* instructions of how to use the program along with the image name and
* dimensions.
*
* param[in] quadTree - the tree to be displayed to the screen
*
* @returns nothing
*
************************************************************************/
void DisplayEvent::action(QuadTree *quadTree) {
    string title;
    Image *image = quadTree->getOriginalImage();
    Image *compressedImage = quadTree->getCompressedImage();

    // Get data about the image
    int width = image->getWidth();
    int height = image->getHeight();
	int leaves = quadTree->getTotalLeaves();
	int pixels = width * height;
    int percent = 200 * leaves / pixels;

    // Build the title string
    title = "Quality Factor [" + to_string(quadTree->getCompressionFactor());
    title += "] // Leaves: " + to_string(leaves);
	title += " // mem: " + to_string(2 * leaves);
	title += "b // compressed size: " + to_string(percent) + "%";
	title += " // <spc> for lines [w] to incease [s] to decrease [c] for color [n] for negate";
	 title += " // " + image->getName() + " " + to_string(width) +
              "x" + to_string(height);
    // Set the window title
    glutSetWindowTitle(title.c_str());

    glRasterPos2i( 0, 0 );
    glDrawPixels(width, height, GL_BGR, GL_UNSIGNED_BYTE, image->getData());
    glRasterPos2i(width, 0 );
    // If color image was selected print the color image else the gray scale
    if(quadTree->color)
        glDrawPixels(width, height, GL_BGR, GL_UNSIGNED_BYTE, compressedImage->getData());
    else
        glDrawPixels(width, height, GL_LUMINANCE, GL_UNSIGNED_BYTE, compressedImage->getData());
}

/*********************************************************************//*
* @par Description:
* Called when the user interacts with the keyboard. The "q" key will exit
* the program, the spacebar will display grid lines, the "s" key will
* decrease the compression factor by 1, and the "w" key will increase
* the compression factor by 1. The "c" key can also be pressed to switch
* between grayscale and color, and "n" will negate the image.
*
* param[in] quadTree - the the quadTree to act upon
*
* @returns nothing
************************************************************************/
void KeyboardEvent::action(QuadTree *quadTree) {
    if (key == 'q' || key == ESCAPE_KEY) {
        // Here you will do your cleanup processing

        glutLeaveMainLoop();
    }
    if(key == ' ') {
        // Turn on and off lines
        quadTree->lines = !quadTree->lines;
        glutPostRedisplay();
    }
    else if(key == 's') {
		int temp = quadTree->getCompressionFactor();
        // Change compression factor
		if(temp >= 1)
			temp--;
		quadTree->setCompressionFactor(temp);
        glutPostRedisplay();
    }
    else if(key == 'w') {
        int temp = quadTree->getCompressionFactor();
        // Change compression factor
		if(temp < 128)
            temp++;
		quadTree->setCompressionFactor(temp);
        glutPostRedisplay();
    }
    else if(key == 'c') {
        // Change from color to monochrome
        quadTree->color = !quadTree->color;
        glutPostRedisplay();
    }
    else if(key == 'n') {
        // Negate the image
        quadTree->negate = !quadTree->negate;
        glutPostRedisplay();
    }
}

/*********************************************************************//*
* @par Description:
* Sets the original image in the quad tree to be used, as well as the
* original compression factor to be used.
*
* param[in] quadTree - the class to act upon
*
* @returns nothing
************************************************************************/
void InitEvent::action(QuadTree *quadTree) {
    quadTree->setOriginalImage(image);
	int temp = atoi(CF);
	quadTree->setCompressionFactor(temp);
}

/*********************************************************************//*
* @par Description:
* Defines what happens on a reshape event, which is nothing at the moment.
*
* param[in] quadTree - the class to act upon
*
* @returns nothing
************************************************************************/
void ReshapeEvent::action(QuadTree *quadTree) {}
