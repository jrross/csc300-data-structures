#include <iostream>
#include "myHash.h"

using namespace std;

int main()
{
   Hash hash(5);

   hash.insert("Mickey", "Mouse");
   hash.insert("Minnie", "Mouse");
   hash.insert("Daisy", "Duck");
   hash.insert("Donald", "Duck");
   hash.insert("Scrooge", "McDuck");
   hash.insert("Huey", "Duck");
   hash.insert("Dewey", "Duck");
   hash.insert("Lewy", "Duck");

   hash.remove("NOTREAL");
   hash.remove("Daisy");

   return 0;
}
