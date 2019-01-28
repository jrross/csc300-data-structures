#ifndef __SORT_H
#define __SORT_H
#include <iostream>
#include <string>
#include <vector>
struct Node
{
   int data;
   Node* left;
   Node* right;
   Node* parent;
   int ht;

   Node(int d, Node* l=nullptr, Node* r=nullptr, Node* p=nullptr, int h=0): data(d), left(l), right(r), parent(p), ht(h) {}
};

class Sort
{
   protected:
      std::string name; 
      bool quadratic;
      std::vector<int> values;

   public:
      Sort(std::string, bool, std::vector<int>);
      Sort(std::string, bool);

      virtual ~Sort() {};

      virtual void sort() = 0;
      std::string Name();
      void addVal(int val);
      std::vector<int>& getValues();
      void printValues();
      bool isQuadratic();
};
#endif
