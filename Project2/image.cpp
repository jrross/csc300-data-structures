/**************************************************************************//**
 * @file
 * @brief functions to be used with image.h
 *****************************************************************************/
#include "image.h"

// Constructors for Image objects
Image::Image(std::string fileName) : fileName(fileName) {}
BmpImage::BmpImage(std::string fileName) : Image(fileName) {}
BmpImage::BmpImage(int width, int height, byte *data) : Image("") {
    this->data = new byte[width * height * 3];
    this->width = width;
    this->height = height;
    memcpy(this->data, data, width*height*3);
}

// Accessors
byte* Image::getData() {
    return data;
}

int Image::getHeight() {
    return height;
};

int Image::getWidth() {
    return width;
};

std::string Image::getName() {
    return fileName;
}

// Working functions

// This is a one-way conversion from 24-bit to 8-bit monochrome
// You will want to perform your quadtree compression on the 8-bit image
// first and if you get that working, try on the 24-bit color version as well
void BmpImage::convertToMonochrome() {
    byte *image = new byte[width * height];
    byte *imageptr = image;
    byte *ColorImage = data;
    for (int row = 0 ; row < height ; row++) {
        for (int col = 0 ; col < width ; col++) {
            *imageptr++ = 0.30 * ColorImage[0] +
                0.59 * ColorImage[1] +
                0.11 * ColorImage[2];
            ColorImage += 3;
        }
    }
    delete[] data;
    data = image;
}
/// Reorder bytes
unsigned int reorderBytes(byte *arr) {
    unsigned int b0 = arr[0];
    unsigned int b1 = arr[1];
    unsigned int b2 = arr[2];
    unsigned int b3 = arr[3];
    int big = (b0 | b1 << 8 | b2 << 16 | b3 << 24);
    return big;
}

bool BmpImage::loadImage() {
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int imageSize;

    FILE *file = fopen(fileName.c_str(), "rb");
    if (!file) {
        std::cout << "Image at " << fileName << " could not be opened\n";
        return false;
    }

    if (fread(header, 1, 54, file) != 54) {
        std::cout << "Header invalid: Not a BMP file\n";
        return false;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        std::cout << "Incorrect image identifier.  Not a BMP file!\n";
        return false;
    }

    width = reorderBytes(&header[0x12]);
    height = reorderBytes(&header[0x16]);
    dataPos = reorderBytes(&header[0x0A]);
    imageSize = reorderBytes(&header[0x22]);

    if (imageSize == 0)
        imageSize = width * height * 3;
    if (dataPos == 0)
        dataPos = 54;

    data = new unsigned char[imageSize];
    if(imageSize != fread(data, 1, imageSize, file))
        std::cout << "failed to read image\n";

    fclose(file);
    return true;
}

