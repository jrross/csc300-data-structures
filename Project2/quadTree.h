/***************************************************************************//**
 * @file
 * @brief Header file to be used with quadtree.cpp
 ******************************************************************************/
#ifndef QUADTREE_H
#define QUADTREE_H
#include "image.h"

using namespace std;

/*!
 * @brief Node structure for the quad Tree
 */
struct Node {
    int data;           /*!< Color of the node */
    int min;            /*!< Minimum pixel value */
    int max;            /*!< Maximum pixel value */
    Node* ne{nullptr};  /*!< Pointer to node to the northeast */
    Node* nw{nullptr};  /*!< Pointer to node to the northwest */
    Node* se{nullptr};  /*!< Pointer to node to the southeast */
    Node* sw{nullptr};  /*!< Pointer to node ot the southwest */
    bool leaf = false;  /*!< Whether this node is a leaf or not */
    int xstart;         /*!< Starting x coordinate */
    int ystart;         /*!< Starting y coordinate */
    int xend;           /*!< Ending x coordinate */
    int yend;           /*!< Ending y coordinate */

    /// Constructor
    Node(int d, int x1, int y1, int x2, int y2): data(d), xstart(x1),
        ystart(y1), xend(x2), yend(y2) {}
};

/*!
 * @brief The class for the quadTree
 */
class QuadTree {
    Image *originalImage;   /*!< Pointer to the original image */
    Image *grayImage;       /*!< Pointer to the grayscale image */
    Image *compressedImage; /*!< Pointer to the compressed image */
    Node *root{nullptr};    /*!< Pointer to the quad tree */
    int qCF;                /*!< Compression factor */
    int leafCount;          /*!< Number of leaves in the quad tree */
    public:
        bool lines = false; /*!< Whether or not to show lines */
        bool color = false; /*!< Whether to show color or grayscale */
        bool negate = false;/*!< Whether or not to negate the image */

        QuadTree();
        QuadTree(Image *img);   /*!< Constructor when passed an image */
        ~QuadTree();            /*!< Destructor */

        void setOriginalImage(Image *); /*!< Sets the original image */
        Image* getOriginalImage();      /*!< Returns the original image */
        Image* getCompressedImage();    /*!< Returns the compressed image */
        void setCompressionFactor(int); /*!< Sets the compression factor */
        int getCompressionFactor();     /*!< Returns the compression factor */
        int getTotalLeaves();/*!<Returns the number of leaves in the quad tree*/
    private:
        void makeTree(Image *origin, int CF);
        void recurse(Node *parent, byte *pixels, int x1, int y1, int x2, int y2, int CF);
        int getAverage(int a, int b, int c, int d);
        int getCF(int min, int max);
        int getMax(int a, int b, int c, int d);
        int getMin(int a, int b, int c, int d);
        void buildArray(Node* curr);
        void clearTree(Node* curr);
};

#endif
