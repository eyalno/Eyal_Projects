#ifndef SHAPES_H
#define SHAPES_H

#include <fstream>
#include <vector>
using namespace std;

class Shape{
public:

	static void Store(const vector<Shape*> & shapes, fstream &fs);  //should the func recevie istream;

	static void Retreive(vector<Shape*> & shapes, fstream &fs);
	
	virtual void Write(fstream &fs) = 0 ;
};

#endif


