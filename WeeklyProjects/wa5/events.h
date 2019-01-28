#include <iostream>
#include <GL/freeglut.h>


using namespace std;
#ifndef EVENTS_H
#define EVENTS_H

class event
{
	public:
	virtual void draw() = 0;

};



class mouse : public event
{
	public:
	mouse (int b, int s, int i, int j); 
	void draw();

	private:
	int button;
	int state;
	int x;
	int y;

};

class kb : public event
{
	public:
	kb (unsigned char k, int i, int j);
	void draw();

	private:
	unsigned char key;
	int x;
	int y;
};







#endif
