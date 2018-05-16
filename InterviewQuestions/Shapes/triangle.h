#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shapes.h"
#include <fstream>

class Triangle :public Shape{
public:
	Triangle(fstream &fs);
	void Write(fstream &fs);
private:

	int x1, y1, x2, y2, x3, y3;
};

#endif // !TRIANGLE_H