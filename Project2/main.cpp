/*************************************************************************//**
 * @file
 *
 * @brief This is a quad tree image compression program
 *
 * @mainpage PA2 - quadTree
 *
 * @section course_section Course Information
 *
 * @author Naomi Green, Jeff Ross
 *
 * @date 4/2/2017
 *
 * @par Professor:
 *         Paul Hinker
 *
 * @par Course:
 *         CSC 300
 *
 * @par Location:
 *         McLaury - Room 205
 *
 * @section program_section Program Information
 *
 * @details
 * This program uses a quad tree to compress images. The compressed image is
 * then converted back to an array and printed to the screen along with the
 * original image. When the program is running pressing 'w' will increase the
 * quality factor for lossy encoding, pressing 's' will decrease it. Space is
 * used to turn the lines on and off, showing where the quadtree split the image.
 * 'c' will switch the image between color and monochrome, and pressing 'n' will
 * switch between displaying a negated image, and not.
 *
 * Glut is used to display the images. On the title bar of the glut display
 * window are the statistics for the quad tree as well as the image, dimensions
 * and how to use it. If the image was written into memory from the quad tree it
 * would only take 2 times the number of leaves in the tree to store the image.
 * This is how the mem section was calculated.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
 @verbatim
 c:\>  main image.bmp quality_factor
 @endverbatim
 *
 * @par Modifications and Development Timeline:
 *       <a href="https://7355267@gitlab.mcs.sdsmt.edu/7275982/csc300_Spring2017_Project2.git">
 *       Please see the git repository </a>
 *
 *****************************************************************************/
#include <iostream>
#include <GL/freeglut.h>
#include "util.h"
#include "image.h"

/**************************************************************************//**
 * @par Description:
 * This function prints a usage statement if the program wasn't called corectly.
 *****************************************************************************/
void printUsage(char *exeName) {
    std::cerr << "\nUsage: " << exeName << " image.bmp quality_factor\n\n";
}

/**************************************************************************//**
 * @par Description:
 * Main initializes doxygen with the commandline arguments, and loads the bmp
 * image.
 *
 * @returns -1  if the program was called incorrectly
 * @returns -2  if the bmp image could not be read
 *****************************************************************************/
int main(int argc, char **argv) {
    // Verify the provided path is a valid BMP Image
    if (argc < 3) {
        printUsage(argv[0]);
        return -1;
    }

    BmpImage *image = new BmpImage(argv[1]);
    if (!image->loadImage()) {
        std::cerr << "Could not load BMP Image file\n";
        return -2;
    }

    // Initialize the OpenGL/glut library
    glutInit(&argc, argv);

    // Set the callback hooks

    initOpenGL(image,argv[2]);
    glutMainLoop();
}
