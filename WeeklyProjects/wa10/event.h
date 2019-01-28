#ifndef __EVENT_H
#define __EVENT_H
#include "function.h"

class Event
{
public:
   void virtual action(vector<CellStatus>&, DisjointSet&) = 0;
   virtual ~Event(){};
};

class KeyboardEvent : public Event
{
   unsigned char key;
   int x, y;
public:
   KeyboardEvent(unsigned char, int, int);
   void action(vector<CellStatus>&, DisjointSet&);
};

class TickTockEvent : public Event
{
public:
   void action(vector<CellStatus>&, DisjointSet&);
};

class ReshapeEvent : public Event
{
   int w, h;
public:
   ReshapeEvent(int, int);
   void action(vector<CellStatus>&, DisjointSet&);
};

class DisplayEvent : public Event
{
public:
   void action(vector<CellStatus>&, DisjointSet&);
};

class InitEvent : public Event
{
public:
   void action(vector<CellStatus>&, DisjointSet&);
};
#endif
