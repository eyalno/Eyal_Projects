#include "circle.h"
#include <fstream>
#include <iomanip>

#define CIRCLE 2
#define NO_OF_PARAM 6
#define COORD 3
#define CIRCLE_SIZE 9


void Circle::Write(fstream &fs)
{
	fs << CIRCLE;
	fs << setfill('0') << setw(COORD) << xC;
	fs << setfill('0') << setw(COORD) << yC;
	fs << setfill('0') << setw(COORD) << radius;

}

Circle::Circle(fstream &fs)
{
	char sBlock[COORD * NO_OF_PARAM + 1];
	string strBlock;

	fs.read(sBlock, CIRCLE_SIZE);
	sBlock[CIRCLE_SIZE] = 0;
	strBlock = sBlock;
	xC = atoi(strBlock.substr(0, 3).c_str());
	yC = atoi(strBlock.substr(3, 3).c_str());
	radius = atoi(strBlock.substr(6, 3).c_str());
}
