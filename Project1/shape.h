/**************************************************************************//**
 * @file
 *
 * @mainpage Program 1 - SDSM&T Paint
 *
 * @section course_section Course Information
 *
 * @authors Luke Videckis and Jeffrey Ross
 *
 * @date February 24, 2017
 *
 * @par Instructor:
 *         Dr. Hinker
 *
 * @par Course:
 *         CSC 300 - Section 1 - 10:00 am
 *
 * @par Location:
 *         McLaury - Room 205
 *
 * @par Description:
 * This program immitates Microsoft Paint with less features. There is a palette
 * in the bottom left corner of the window. Shapes  can be selected by left
 * clicking. Border colors are chosen by left clicking and fill colors are
 * chosen by right clicking. The top left square of the palette shows the
 * current color. Shapes are drawn by left clicking and dragging in the canvas.
 * Shapes which are drawn can be moved by right clicking and dragging. When
 * a shape is moved, it is redrawn on top of all other shapes.\n\n
 *
 * This project is an exercise in OOP, GUI developement in Glut, practicing
 * good repository citizenship, and working in a team.
 * 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      % make to compile, % ./main to run
 *
 * @par Usage:
   @verbatim
   c:\> main.exe
   d:\> C:\Project1
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug None
 *
 * @todo None
 *
 * @par Modifications and Development Timeline:
 @verbatim
 Date          Modification
 ------------  --------------------------------------------------------------
 https://gitlab.mcs.sdsmt.edu/7275982/Project1.git
 @endverbatim
 *
 *****************************************************************************/

#include <vector>
#ifndef SHAPE_H
#define SHAPE_H

/*!
* @brief This is the Shape class.
*/
class Shape
{
public:
    virtual ~Shape(){}/*!<Shape destructor*/
    virtual void draw() const = 0;/*!<shape draw function*/
    virtual bool contains(int a, int b) const = 0;/*!<shape contains function*/
    virtual void move(int x, int y) = 0;/*!<shape move function*/
    float color[3];/*!<fill color*/
    float border[3];/*!<border color*/
    std::vector<int>displayShapes;/*!<list of ints which tell what shape it is*/
};

/*!
* @brief This is the Shape class.
*/
struct currentProperties
{
    float color[3];/*!<RGB colors for the fill color*/
    float border[3];/*!<RGB colors for the border*/
    int shapeType;  /*!<1 = rectangle, 2 = ellipse, 3 = line, 4 = filled elipse, 
                        5 = filled rectangle*/
    bool ready; /*!<set to true if both color and shape are selected*/
};
#endif
