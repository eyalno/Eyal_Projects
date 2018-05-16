#include "square.h"
#include <fstream>
#include <iomanip>

#define COORD 3
#define NO_OF_PARAM 6
#define SQUARE 1
#define SQUARE_SIZE 12

void Square::Write(fstream &fs) //could i have not write it 3 times save the enum as member?
{
	fs << SQUARE;
	fs << setfill('0') << setw(COORD) << x1;
	fs << setfill('0') << setw(COORD) << y1;
	fs << setfill('0') << setw(COORD) << x2;
	fs << setfill('0') << setw(COORD) << y2;
}

Square::Square(fstream &fs)
{
	char sBlock[COORD * NO_OF_PARAM + 1];
	string strBlock;

	fs.read(sBlock, SQUARE_SIZE);
	sBlock[SQUARE_SIZE] = 0;
	strBlock = sBlock;
	x1 = atoi(strBlock.substr(0, 3).c_str());
	y1 = atoi(strBlock.substr(3, 3).c_str());
	x2 = atoi(strBlock.substr(6, 3).c_str());
	y2 = atoi(strBlock.substr(9, 3).c_str());
}