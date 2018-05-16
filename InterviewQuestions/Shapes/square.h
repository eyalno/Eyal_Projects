#ifndef SQUARE_H
#define SQUARE_H

#include "Shapes.h"
#include <fstream>

class Square :public Shape{
public:

	Square(fstream &fs);
	void Write(fstream &fs);
private:

	int x1, y1, x2, y2;

};

#endif