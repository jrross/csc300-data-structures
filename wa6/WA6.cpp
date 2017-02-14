/***************************************************************************//**
 * @file WA6.cpp
 ******************************************************************************/
#include <iostream>
#include "node.h"

using namespace std;

/***************************************************************************//**
 * @brief reference insert node function
 ******************************************************************************/
Node* insert(Node* root, int data)
{
   if (root == nullptr)
      root = new Node(data);

   else if (data < root->data)
      root->left = insert(root->left, data);
   else
      root->right = insert(root->right, data);

   return root;
}
