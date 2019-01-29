/***************************************************************************//**
 * @file
 * @brief Functions to be used with quadtree.h
 ******************************************************************************/
#include "quadTree.h"

/*********************************************************************//*
 * @par Description:
 * Constructor
 *
 * @returns nothing
 ************************************************************************/
QuadTree::QuadTree() {

}

/*********************************************************************//*
 * @par Description:
 * Constructor for a quad tree. It takes the data from the image and converts
 * it into monochrome, and initializes the compressed image.
 *
 * param[in] img - the image to create a quad tree of
 *
 * @returns nothing
 ************************************************************************/
QuadTree::QuadTree(Image *img) {
    originalImage = img;
    compressedImage = new BmpImage(img->getWidth(), img->getHeight(), img->getData());
    grayImage = new BmpImage(img->getWidth(), img->getHeight(), img->getData());

    grayImage->convertToMonochrome();
}

/*********************************************************************//*
 * @par Description:
 * The destructor for the quad tree.
 *
 * @returns nothing
 ************************************************************************/
QuadTree::~QuadTree() {
    clearTree(root);
    delete[] originalImage;
    delete[] grayImage;
    delete[] compressedImage;
}

/*********************************************************************//*
 * @par Description:
 * Sets the original image in the quad tree to be used. It also creates a gray
 * image, and initializes the compressed image.
 *
 * param[in] img - the image to put into the quad tree.
 *
 * @returns nothing
 ************************************************************************/
void QuadTree::setOriginalImage(Image *img) {
    originalImage = img;

    compressedImage = new BmpImage(img->getWidth(), img->getHeight(), img->getData());
    grayImage = new BmpImage(img->getWidth(), img->getHeight(), img->getData());
    grayImage->convertToMonochrome();
}

/*********************************************************************//*
 * @par Description:
 * Used to get the original image the tree is based on.
 *
 * @returns an image class containing the original image
 ************************************************************************/
Image* QuadTree::getOriginalImage() {
    return originalImage;
}

/*********************************************************************//*
 * @par Description:
 * This function clears the quad tree, then if color is set builds the quad tree
 * in color. If color is not set it builds the quad tree using the gray image.
 * Then convertes the quad tree back into an array to be returned.
 *
 * @returns an image containing the compressed image.
 ************************************************************************/
Image* QuadTree::getCompressedImage() {
    leafCount = 0;

    // Clear the old quadtree
    clearTree(root);
    root = nullptr;

    // Make the quadtree
    if(color)
        makeTree(originalImage, qCF);
    else
        makeTree(grayImage, qCF);

    // Convert the quad tree into an array
    buildArray(root);

    return compressedImage;
}

/*********************************************************************//*
 * @par Description:
 * Used to set the compression factor of a quad tree
 *
 * param[in] temp - the compression factor
 *
 * @returns nothing
 ************************************************************************/
void QuadTree::setCompressionFactor(int temp) {
    qCF = temp;
}

/*********************************************************************//*
 * @par Description:
 * This function returns the compression factor used to calculated the tree
 *
 * @returns the compression factor
 ************************************************************************/
int QuadTree::getCompressionFactor() {
    return qCF;
}

/*********************************************************************//*
 * @par Description:
 * Used to get the total number of leaves in the tree.
 *
 * @returns total leaves in the tree
 ************************************************************************/
int QuadTree::getTotalLeaves() {
    return leafCount;
}

/*********************************************************************//*
 * @par Description:
 * This is a function which creates a quadtree to represent an image. It creates
 * the root for the tree and then calls a recursive function to fill in the rest
 * of the tree.
 *
 * param[in] origin - a structure representing an image to be made into a tree
 * param[in] CF     - the compression factor
 *
 * @returns nothing
 ************************************************************************/
void QuadTree::makeTree(Image *origin, int CF) {
    int width = origin->getWidth();
    int height = origin->getHeight();

    byte *pixels = origin->getData();
    Node *temp = new Node(0, 0, 0, width, height);

    root = temp;
    // Build the tree
    recurse(temp, pixels, 0, 0, width, height, CF);
}

/*********************************************************************//*
 * @par Description:
 * This is a recursive function which starts by building the entire quad tree.
 * Using the original image it breaks itself into four equal areas, until each
 * area is representing one pixel. Then on returning the four areas are checked,
 * and if all the pixels in each are close in color with reference to the
 * compression factor, they are compressed into the parent. A node can
 * either be a leaf or have 4 children. If the 4 parts of the node are similar
 * enough in color it is counted as a leaf and return back up to previous call.
 *
 * param[in] parent - the node that represents the area
 * param[in] pixels - an array containing the color values of the original image
 * param[in] x1     - represents x value of bottom left corner
 * param[in] y1     - represents y value of bottom left corner
 * param[in] x2     - represents x value of top right corner
 * param[in] y2     - represents y value of top right corner
 * param[in] CF     - the compression factor to be compared to
 *
 ************************************************************************/
void QuadTree::recurse(Node *parent, byte *pixels, int x1, int y1, int x2,
        int y2, int CF) {
    int w = x2 - x1;
    int h = y2 - y1;
    static int wTotal = w; //wTotal is the width of the entire image
    // If we are at one pixel
    if( w == 1 && h == 1) {
        parent->leaf = true;
        leafCount++;
        // Store the color in the node
        if(!color)
            parent->data = pixels[wTotal*y1 + x1];
        else {
            parent->data = pixels[wTotal*y1*3 + x1*3]<<8;
            parent->data += pixels[wTotal*y1*3 + x1*3+1];
            parent->data = parent->data << 8;
            parent->data += pixels[wTotal*y1*3 + x1*3+2];
        }
        parent->min = parent->data;
        parent->max = parent->data;
        return;
    }

    // North West
    Node *temp = new Node(0, x1, y1, x1 + w/2, y1 + h/2);
    parent->nw = temp;
    recurse(temp, pixels, x1, y1, x1 + w/2, y1 + h/2, CF);

    // North East
    temp = new Node(0, x1 + w/2, y1, x2, y1 + h/2);
    parent->ne = temp;
    recurse(temp, pixels, x1 + w/2, y1, x2, y1 + h/2, CF);

    // South West
    temp = new Node(0, x1, y1 + h/2, x1 + w/2, y2);
    parent->sw = temp;
    recurse(temp, pixels, x1, y1 + h/2, x1 + w/2, y2, CF);

    // South East
    temp = new Node(0, x1 + w/2, y1 + h/2, x2, y2);
    parent->se = temp;
    recurse(temp, pixels, x1 + w/2, y1 + h/2, x2, y2, CF);

    if(parent->nw->leaf && parent->ne->leaf &&
            parent->sw->leaf && parent->se->leaf) {
        int avg1 = parent->nw->data;
        int avg2 = parent->ne->data;
        int avg3 = parent->sw->data;
        int avg4 = parent->se->data;
        // Get the min and max of all four quadrants
        int min = getMin(parent->nw->min, parent->ne->min, parent->sw->min, parent->se->min);
        int max = getMax(parent->nw->max, parent->ne->max, parent->sw->max, parent->se->max);
        // Get the average
        int avg5 = getAverage(avg1, avg2, avg3, avg4);
        // Compress if the max and min values are within the compression factor
        if( getCF(min, max) <= CF) {
            parent->data = avg5;
            parent->min = min;
            parent->max = max;
            parent->leaf = true;

            // Delete the nodes that were compressed
            delete parent->nw;
            parent->nw = nullptr;
            delete parent->ne;
            parent->ne = nullptr;
            delete parent->sw;
            parent->sw = nullptr;
            delete parent->se;
            parent->se = nullptr;
            leafCount -= 3;
        }
    }
}

/*********************************************************************//*
 * @par Description:
 * This function is used to find the average color for an area. It takes the
 * values of the four quadrants which are passed in. If using color is not set
 * It just returns the average. If color is set it splits each value passed in
 * into its three color values. Then the average of those values are taken
 * individually and returned in a single integer.
 *
 * param[in] a - the average value for the nw quadrant
 * param[in] b - the average value for the ne quadrant
 * param[in] c - the average value for the sw quadrant
 * param[in] d - the average value for the se quadrant
 *
 * @returns the average of the colors
 ************************************************************************/
int QuadTree::getAverage(int a, int b, int c, int d) {
    if(!color)
        return (a + b + c + d) / 4;
    // Split each value int the three colors
    int a1 = (a >> 16), a2 = ((a >> 8) & 255), a3 = (a & 255);
    int b1 = (b >> 16), b2 = ((b >> 8) & 255), b3 = (b & 255);
    int c1 = (c >> 16), c2 = ((c >> 8) & 255), c3 = (c & 255);
    int d1 = (d >> 16), d2 = ((d >> 8) & 255), d3 = (d & 255);

    // Get the average of each and return in one int
    a1 = (a1 + b1 + c1 + d1) / 4;
    a1 <<= 8;
    a1 += (a2 + b2 + c2 + d2) / 4;
    a1 <<= 8;
    a1 += (a3 + b3 + c3 + d3) / 4;
    return a1;
}

/*********************************************************************//*
 * @par Description:
 * This function takes in the minimum and maximum pixel value within the area
 * we are trying to combine, and calculates the distance they are from the
 * average. If color is set it converts them to gray scale first.
 *
 * param[in] min - the minimum pixel value
 * param[in] max - the maximum pixel value
 *
 * @returns the compression factor
 ************************************************************************/
int QuadTree::getCF(int min, int max) {
    if(!color)
        return max - (min + max) / 2;

    // Convert to grayscale
    int a1 = (min >> 16) * .3 + ((min >> 8) & 255) * .59 + (min & 255) * .11;
    int b1 = (max >> 16) * .3 + ((max >> 8) & 255) * .59 + (max & 255) * .11;
    return b1 - (a1 + b1) / 2;
}

/*********************************************************************//*
 * @par Description:
 * This function returns the maximum value for the quadrants. If color is set it
 * compares the grayscale for each of the color values, and returns the original
 * not grayscale value of the max.
 *
 * param[in] a - the max value for the nw quadrant
 * param[in] b - the max value for the ne quadrant
 * param[in] c - the max value for the sw quadrant
 * param[in] d - the max value for the se quadrant
 *
 * @returns the maximum value
 ************************************************************************/
int QuadTree::getMax(int a, int b, int c, int d) {
    if(!color) {
        a = a > b ? a : b;
        a = a > c ? a : c;
        a = a > d ? a : d;
        return a;
    }

    // Convert to grayscale
    int a1 = (a >> 16) * .3 + ((a >> 8) & 255) * .59 + (a & 255) * .11;
    int b1 = (b >> 16) * .3 + ((b >> 8) & 255) * .59 + (b & 255) * .11;
    int c1 = (c >> 16) * .3 + ((c >> 8) & 255) * .59 + (c & 255) * .11;
    int d1 = (d >> 16) * .3 + ((d >> 8) & 255) * .59 + (d & 255) * .11;

    if(a1 > b1 && a1 > c1 && a1 > d1)
        return a;
    if( b1 > c1 && b1 > d1)
        return b;
    if(c1 > d1)
        return c;
    return d;
}

/*********************************************************************//*
 * @par Description:
 * This function returns the minimum value of the four quadrants passed in. If
 * color is set it compares the grayscale for each of the color values, and
 * returns the original not grayscale value of the min.
 *
 * param[in] a - the min value for the nw quadrant
 * param[in] b - the min value for the ne quadrant
 * param[in] c - the min value for the sw quadrant
 * param[in] d - the min value for the se quadrant
 *
 * @returns minimum color value
 ************************************************************************/
int QuadTree::getMin(int a, int b, int c, int d) {
    if(!color) {
        a = a < b ? a : b;
        a = a < c ? a : c;
        a = a < d ? a : d;
        return a;
    }

    // Convert to grayscale
    int a1 = (a >> 16) * .3 + ((a >> 8) & 255) * .59 + (a & 255) * .11;
    int b1 = (b >> 16) * .3 + ((b >> 8) & 255) * .59 + (b & 255) * .11;
    int c1 = (c >> 16) * .3 + ((c >> 8) & 255) * .59 + (c & 255) * .11;
    int d1 = (d >> 16) * .3 + ((d >> 8) & 255) * .59 + (d & 255) * .11;

    if(a1 < b1 && a1 < c1 && a1 < d1)
        return a;
    if( b1 < c1 && b1 < d1)
        return b;
    if(c1 < d1)
        return c;
    return d;

}

/*********************************************************************//*
 * @par Description:
 * This function is a recursive function that builds an array from the quad
 * tree. If negate is set it stores the negative of the image into the array. If
 * color is set it splits the value and stores it in three bytes instead of one.
 *
 * param[in] curr - a pointer to the current quad tree node
 *
 * @returns nothing
 ************************************************************************/
void QuadTree::buildArray(Node *curr) {
    // Base case
    if(curr == nullptr) {
        return;
    }
    // If curr is a leaf store values in array
    if(curr->leaf) {
        byte* data = compressedImage->getData();
        int w = compressedImage->getWidth();

        // Insert color into array
        for(int i = curr->ystart; i < curr->yend + 1; i++) {
            for(int j = curr->xstart; j < curr->xend + 1; j++) {
                if(color) {
                    if(negate) {
                        data[w * i*3 + j*3] = 255 - (curr->data >> 16);
                        data[w * i*3 + j*3+1] = 255 - ((curr->data >> 8) & 255);
                        data[w * i*3 + j*3+2] = 255 - (curr->data & 255);
                    }
                    else {
                        data[w * i*3 + j*3] = curr->data >> 16;
                        data[w * i*3 + j*3+1] = (curr->data >> 8)& 255;
                        data[w * i*3 + j*3+2] = curr->data & 255;
                    }
                    if(lines && (j == curr->xend || i == curr->yend)) {
                        data[w * i*3 + j*3] = 255;
                        data[w * i*3 + j*3+1] = 255;
                        data[w * i*3 + j*3+2] = 255;
                    }
                }
                // Not in color
                else {
                    if(negate)
                        data[w * i + j] = 255 - curr->data;
                    else
                        data[w * i + j] = curr->data;
                    if(lines && (j == curr->xend || i == curr->yend))
                        data[w * i + j] = 255;
                }
            }
        }
    }

    buildArray(curr->se);
    buildArray(curr->sw);
    buildArray(curr->ne);
    buildArray(curr->nw);
}

/*********************************************************************//*
 * @par Description:
 * This function clears the quad tree and frees the memory it used.
 *
 * param[in] curr - the current node
 *
 * @returns nothing
 ************************************************************************/
void QuadTree::clearTree(Node* curr) {
    // Base case
    if(curr == nullptr)
        return;

    if(curr->leaf == true) {
        delete curr;
        return;
    }

    // Call clearTree on each quadrant
    clearTree(curr->se);
    curr->se = nullptr;
    clearTree(curr->sw);
    curr->sw = nullptr;
    clearTree(curr->ne);
    curr->ne = nullptr;
    clearTree(curr->nw);
    curr->nw = nullptr;

    // Delete the current node
    delete curr;
    curr = nullptr;
}
