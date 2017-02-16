/***************************************************************************//**
 * @file WA6.cpp
 ******************************************************************************/
#include <iostream>
#include "node.h"
#include "WA6.h"

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
	temp->ht = prev->ht + 1;
	if ( temp->right == nullptr)
		r = -1;
	else
		r = temp->right->ht;
	if ( temp->left == nullptr)
		l = -1;
	else
		l = temp->left->ht;

	if ( l - r > 1 || l - r < -1)	//temp=large / prev = mid / prev2 = small
	{

		if( prev2->data > temp->data)
			swap(prev2, temp);
		if( prev->data > temp->data)
			swap(prev, temp);
		if( prev2->data > prev->data)
			swap(prev2, prev);		
		rotate(temp, prev, prev2);
		swap(temp, prev);
		//cout << temp->data << " " << temp << " " << temp->ht << endl;
		//cout << temp->left->data << " " << temp->left->parent << " " << temp->left->ht << endl;
		//cout << temp->right->data << " " << temp->right->parent << " " << temp->right->ht <<endl;
		//cout << endl;

	}
	}
	root = temp;
	return root;
}



void rotate(Node* &large, Node* &mid, Node* &small)
{
	if (mid->parent == small && small->parent == large) //left right
	{
		mid->parent = large;
		small->parent = mid;
		small->right = mid->left;
		mid->left = small;
		large->left = mid;
	}

	if (small->parent == mid && mid->parent == large)//left left
	{
		mid->parent = large->parent;
		large->parent = mid;
		large->left = mid->right;
		mid->right = large;
		mid->left = small;
		large->ht = small->ht;	
	}

	if (mid->parent == large && large->parent == small) //right left
	{
		mid->parent = small;
		large->parent = mid;
		large->left = mid->right;
		mid->right = large;
		small->right = mid;

	}

	if (large->parent == mid && mid->parent == small) //right right
	{
		mid->parent = small->parent;
		small->parent = mid;
		small->right = mid->left;
		mid->right = large;
		mid->left = small;
		small->ht = large->ht;
	}


}

void swap(Node* &a, Node* &b)
{
	Node * temp;
	temp = a;
	a = b;
	b = temp;
}
