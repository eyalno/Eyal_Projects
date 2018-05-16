#include "Shapes.h"

#include <fstream>

int main()
{
	fstream fs;
	vector<Shape*> vec;
	fs.open("test.txt", fstream::out | fstream::in | fstream::app);

	Shape::Retreive(vec, fs);
	
	fs.clear();
	fs.seekg(0, ios::beg);

	Shape::Store(vec, fs);
	
	fs.close();

	return 1;
}