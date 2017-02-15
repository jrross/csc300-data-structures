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
	{
		root = new Node(data);
		return root;
	}
	
	Node* temp = root;
	Node* prev = root;
	Node* prev2 = root;
	int d = 0; 		// an integer which signals if it is to the right or left
	int i = 1;
	int l;
	int r;

	while (temp != nullptr)
	{
		if(data > temp->data)
		{
			d = 1;
			prev = temp;
			temp = temp-> right;
		}
		else
		{
			d = 2;
			prev = temp;
			temp = temp->left;
		}
	}
	temp = new Node(data);
	if ( d == 1)
		prev->right = temp;
	if ( d == 2)
		prev->left = temp;
	temp->parent = prev;
	temp->ht = 0;
	
	while(temp->parent != nullptr)
	{
	prev2 = prev;
	prev = temp;
	temp = temp->parent;
	temp->ht = i;
	i = i + 1;
	if ( temp->right == nullptr)
		r = 0;
	else
		r = temp->right->ht;
	if ( temp->left == nullptr)
		l = 0;
	else
		l = temp->left->ht;
	}
	cout << l - r << endl;
	return root;
}
