#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shapes.h"
#include <fstream>

class Circle :public Shape{
public:

	Circle(fstream &fs);
	void Write(fstream &fs);

private:

	int xC, yC, radius;
};

#endif CIRCLE_H