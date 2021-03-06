#include "bstSort.h"
BstSort::BstSort()
{
	root = nullptr;
}

BstSort::~BstSort()
{

}
void BstSort::addVal(int val)
{
	if (root == nullptr)
	{
		root = new Node(val);
		return;
	}
	
	Node* temp = root;
	Node* prev = root;
	Node* prev2 = root;
	int d = 0; 		// an integer which signals if it is to the right or left
	int l;
	int r;
	while (temp != nullptr)
	{
		if(val >= temp->data)
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
	temp = new Node(val);
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

	if ( l - r > 1 || l - r < -1)	//prev=large / temp = mid / prev2 = small
	{
		if( prev2->data >= prev->data)
			swap(prev2, prev);
		if( temp->data >= prev->data)
			swap(temp, prev);
		if( prev2->data >= temp->data)
			swap(prev2, temp);
		rotate(prev, temp, prev2);
	}
	}
	root = temp;

}
void BstSort::sort()
{
	recurse(this->root);
}

void BstSort::recurse (Node *temp)
{
	if(temp == nullptr)
		return;
	recurse(temp->left);
	values.push_back(temp->data);
	recurse(temp->right);
}
void rotate(Node* &large, Node* &mid, Node* &small)
{
	int height;

	if (mid->parent == small && small->parent == large) //left right
	{
		mid->parent = large;
		small->parent = mid;
		small->right = mid->left;
		if (small->right != nullptr)
			small->right->parent = small;
		mid->left = small;
		large->left = mid;
		height = small->ht;
		small->ht = mid->ht;
		mid->ht = height;
	}

	if (small->parent == mid && mid->parent == large)//left left
	{
		if(large->parent)
		{
			if(large->parent->right == large)
				large->parent->right = mid;
			if(large->parent->left == large)
				large->parent->left = mid;
		}
		mid->parent = large->parent;
		large->parent = mid;
		large->left = mid->right;
		if(large->left != nullptr)
			large->left->parent = large;
		mid->right = large;
		mid->left = small;
		large->ht = large->ht - 2;
			
	}

	if (mid->parent == large && large->parent == small) //right left
	{
		mid->parent = small;
		large->parent = mid;
		large->left = mid->right;
		if (large->left != nullptr)
			large->left->parent = small;
		mid->right = large;
		small->right = mid;
		height = large->ht;
		large->ht = mid->ht;
		mid->ht = height;
	}

	if (large->parent == mid && mid->parent == small) //right right
	{
		if(small->parent)
		{
			if (small->parent->right == small)
				small->parent->right = mid;
			if (small->parent->left == small)
				small->parent->left = mid;
		}
		mid->parent = small->parent;
		small->parent = mid;
		small->right = mid->left;
		if (small->right != nullptr)
			small->right->parent = small;
		mid->right = large;
		mid->left = small;
		small->ht = small->ht - 2;
	}


}

void swap(Node* &a, Node* &b)
{
	Node * temp;
	temp = a;
	a = b;
	b = temp;
}
