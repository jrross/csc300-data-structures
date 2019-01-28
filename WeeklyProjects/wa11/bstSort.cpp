#include "bstSort.h"

BSTSort::BSTSort(std::string n) : Sort(n, false) {
	root = nullptr;
}

BSTSort::BSTSort(std::string n, std::vector<int> v) : Sort(n, false, v) {
	root = nullptr;
}

// You need to implement the sort method for BSTSort.  See the InsertSort
// implementation for an example
void BSTSort::sort() 
{
	for(int i = 0; i < (int)values.size(); i++)
		this->addVal(values[i]);
	values.clear();
	recurse(this->root);
	recurseDelete(this->root);
}

void BSTSort::addVal(int val)
{
	if (root == nullptr)
	{
		root = new Node(val);
		return;
	}
	
	Node* temp = root;
	Node* prev = root;
	int d = 0; 		// an integer which signals if it is to the right or left
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
}

void BSTSort::recurse (Node *temp)
{
	if(temp == nullptr)
		return;
	recurse(temp->left);
	values.push_back(temp->data);
	recurse(temp->right);
}

void BSTSort::recurseDelete (Node *temp)
{
	if (temp == nullptr)
		return;
	recurseDelete(temp->left);
	recurseDelete(temp->right);
	delete temp;
}
