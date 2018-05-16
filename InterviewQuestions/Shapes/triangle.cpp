
#include <fstream>
#include <iomanip>
#include "triangle.h"

#define COORD 3
#define NO_OF_PARAM 6
#define TRIANGLE 0 
#define TRIANGLE_SIZE 18 

void Triangle::Write(fstream &fs)
{
	fs << TRIANGLE;
	fs << setfill('0') << setw(COORD) << x1;
	fs << setfill('0') << setw(COORD) << y1;
	fs << setfill('0') << setw(COORD) << x2;
	fs << setfill('0') << setw(COORD) << y2;
	fs << setfill('0') << setw(COORD) << x3;
	fs << setfill('0') << setw(COORD) << y3;
}

Triangle::Triangle(fstream &fs)
{
	char sBlock[COORD * NO_OF_PARAM + 1];
	string strBlock;

	fs.read(sBlock, TRIANGLE_SIZE);
	sBlock[TRIANGLE_SIZE] = 0;
	strBlock = sBlock;

	x1 = atoi(strBlock.substr(0, 3).c_str());
	y1 = atoi(strBlock.substr(3, 3).c_str());
	x2 = atoi(strBlock.substr(6, 3).c_str());
	y2 = atoi(strBlock.substr(9, 3).c_str());
	x3 = atoi(strBlock.substr(12, 3).c_str());
	y3 = atoi(strBlock.substr(15, 3).c_str());
}