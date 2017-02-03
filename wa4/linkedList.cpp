#include "linkedList.h"
#include <iostream>

using namespace std;


//g++ -o main linkedList.h linkedList.cpp main.cpp node.cpp node.h -std=c++0x -g
LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList()
{
	tail = head;
	while (tail != nullptr)
	{
		head = head->next;
		delete tail;
		tail = head;
	}
}


void LinkedList::append(Node *newNode)
{
	if (head == nullptr) // List empty
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}


void LinkedList::prepend(Node *newNode)
{
	if (head == nullptr) // list empty
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}


void LinkedList::insertAfter(Node* curNode, Node* newNode)
{
	if (head == nullptr)  // List empty
	{
		head = newNode;
		tail = newNode;
	}	   
	else if (curNode == tail) // Insert after tail
	{	     
		tail->next = newNode;
		tail = newNode;
	}
	else 
	{ 
		newNode->next = curNode->next;
		curNode->next = newNode;
	}
}


void LinkedList::removeAfter(Node* curNode)
{
	if (curNode == nullptr && head != nullptr)
	{
	Node *sucNode = head->next;
	Node *temp;
	temp = head;
	head = sucNode;
	delete temp;

	if (sucNode == nullptr)
		tail == nullptr;
	}

	else if( curNode->next != nullptr)
	{
	Node *temp;
	temp = curNode->next;
	curNode->next = temp->next;
	delete temp;
	
	if (curNode->next == nullptr)
		tail = curNode;
	}

	
}



void LinkedList::print() const
{
	Node *temp;
	temp = head;
	while(temp->next != nullptr)
	{
		cout << temp << " ";
		temp = temp->next;
	}
	cout << temp << endl;
}


Node *LinkedList::find(int d)
{
	Node *temp;
	temp = head;
	while(temp != nullptr)
	{	
		if(temp->data == d)
			return temp;
		temp = temp->next;
	}
	return nullptr;
		
}
