/**************************************************************************//**
 * @file
 * @brief functions to be used with image.cpp
 *****************************************************************************/
#ifndef __IMAGE_H
#define __IMAGE_H
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

/// Byte is an unsigned char
typedef unsigned char byte;

/*!
 * @brief Class that holds an image
 */
class Image {
    public:
        Image(std::string);             /*!< Constructor */
        bool virtual loadImage() = 0;   /*!< Pure virtual load Image function */
        virtual void convertToMonochrome() = 0;/*!< Pure virtual convert function */
        int getWidth();                 /*!< Returns the width of the image */
        int getHeight();                /*!< Returns the height of the image */
        std::string getName();          /*!< Returns the image name */
        byte* getData();                /*!< Returns the image data */

    protected:
        std::string fileName;           /*!< The filename */
        byte *data;                     /*!< Image array */
        int width;                      /*!< Image width */
        int height;                     /*!< Image Height */
};

/*!
 * @brief Class that holds a bmp image
 */
class BmpImage : public Image {
    public:
        BmpImage(std::string);      /*!< Constructor */
        BmpImage(int, int, byte*);  /*!< Constructor */
        bool loadImage();           /*!< Loads a bmp image */
        void convertToMonochrome(); /*!< Converts image to Monochrome */
};

#endif
