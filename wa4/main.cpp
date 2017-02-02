#include <iostream>
#include "node.h"
#include "linkedList.h"

using namespace std;

int main()
{

   LinkedList ll;
   for (int i = 0 ; i < 5 ; i++)
      ll.append(new Node(i));

   for (int i = 0 ; i < 5 ; i++)
      ll.prepend(new Node(100-i));

   for (int i = 0 ; i < 5 ; i++)
   {

     Node *curNode = ll.find(i);
     ll.insertAfter(curNode, new Node((i+1)*2));

   }
   for (int i = 0 ; i < 5 ; i++)
   {
      Node *curNode = ll.find(i);
   }

   cout << "Before exiting:\n";
   ll.print();
}
