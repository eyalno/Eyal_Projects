#include "Shapes.h"
#include <iomanip>
#include <string>

#include "circle.h"
#include "square.h"
#include "triangle.h"

enum Shapes{
	TRIANGLE,
	SQUARE,
	CIRCLE
};


void Shape::Store(const vector<Shape*> & shapes, fstream &fs)
{
	fs << ' ';
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		(*it)->Write(fs);
		fs << ' ';
	}
}

void Shape::Retreive(vector<Shape*> & shapes, fstream &fs)
{
	char cShape;

	while (fs.read(&cShape, 1))
	{
		Shape * shape;

		switch (cShape - '0')
		{
		case TRIANGLE:
			shape = new Triangle(fs);
			break;

		case CIRCLE:
			shape = new Circle(fs);
			break;

		case SQUARE:
			shape = new Square(fs);
			break;
		default:
			return;
		}

		shapes.push_back(shape);
	}
}


