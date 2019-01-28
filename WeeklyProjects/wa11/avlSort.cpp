#include "avlSort.h"

AVLSort::AVLSort(std::string n) : Sort(n, false) {
	root = nullptr;
}

AVLSort::AVLSort(std::string n, std::vector<int> v) : Sort(n, false, v) {
	root = nullptr;
}

// You need to implement the sort method for AVLSort.  See the InsertSort
// implementation for an example
void AVLSort::sort()
{	
	for(int i = 0; i < (int)values.size(); i++)
		this->addVal(values[i]);
	values.clear();
	recurse(this->root);
	recurseDelete(this->root);
}
void AVLSort::addVal(int data)
{
	if (root == nullptr)
	{
		root = new Node(data);
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
		if(data >= temp->data)
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

	if ( l - r > 1 || l - r < -1)
	{
		rotate(temp, prev, prev2);
	}
	}
	root = temp;
}

void AVLSort::recurseDelete (Node *temp)
{
	if (temp == nullptr)
		return;
	recurseDelete(temp->left);
	recurseDelete(temp->right);
	delete temp;
}
void AVLSort::recurse (Node *temp)
{
	if(temp == nullptr)
		return;
	recurse(temp->left);
	values.push_back(temp->data);
	recurse(temp->right);
}
void rotate(Node* top, Node* middle, Node* bottom)
{
	if (top->left == middle && middle->right == bottom)//left right
	{
		rotateLeft(middle, bottom, true);
		rotateRight(top, bottom, false);
		return;
	}
	if (top->left == middle && middle->left == bottom)//left left
	{
		rotateRight(top, middle, false);
		return; 
	}
	if (top->right == middle && middle->right == bottom)//right right
	{
		rotateLeft(top, middle, false);
		return;
	}
	if (top->right == middle && middle->left == bottom)//right left
	{
		rotateRight(middle, bottom, true);
		rotateLeft(top, bottom, false);
	}
}

void rotateRight(Node* upper, Node* lower, bool twoRotations)
{
	if (upper->parent)
	{
		if (upper->parent->left == upper)
			upper->parent->left = lower;
		if (upper->parent->right == upper)
			upper->parent->right = lower;
	}
	if (twoRotations == true)
	{
		upper->ht = upper->ht - 1;
		lower->ht = lower->ht + 1;
	}
	if (twoRotations == false)
	{
		upper->ht = upper->ht -2;
	}
	upper->left = lower->right;
	if ( lower->right)
		lower->right->parent = upper;
	lower->parent = upper->parent;
	lower->right = upper;
	upper->parent = lower;
}

void rotateLeft(Node* upper, Node* lower, bool twoRotations)
{
	if (upper->parent)
	{
		if (upper->parent->left == upper)
			upper->parent->left = lower;
		if (upper->parent->right == upper)
			upper->parent->right = lower;
	}
	if (twoRotations == true)
	{
		upper->ht = upper->ht - 1;
		lower->ht = lower->ht + 1;
	}
	if (twoRotations == false)
	{
		upper->ht = upper->ht -2;
	}
	upper->right = lower->left;
	if(lower->left != nullptr)
		lower->left->parent = upper;
	lower->parent = upper->parent;
	lower->left = upper;
	upper->parent = lower;
}
