#include <iostream>
#include "node.h"
#include "linkedList.h"

using namespace std;

int main()
{

   LinkedList ll;
	cout << "appending 1-5" << endl;
   for (int i = 0 ; i < 5 ; i++)
      ll.append(new Node(i));
	ll.print();
	cout << "prepending 100-96" << endl;
   for (int i = 0 ; i < 5 ; i++)
      ll.prepend(new Node(100-i));
	ll.print();

   for (int i = 0 ; i < 5 ; i++)
   {

     Node *curNode = ll.find(i);
	cout << "inserting " << (i+1)*2 << " after " << curNode->data << endl;
     ll.insertAfter(curNode, new Node((i+1)*2));
	ll.print();
   }
   for (int i = 0 ; i < 5 ; i++)
   {
	cout << "removing after " << i << endl;
      Node *curNode = ll.find(i);
     ll.removeAfter(curNode);
	ll.print();
   }

   cout << "Before exiting:\n";
   ll.print();
}
