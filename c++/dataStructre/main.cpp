/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    1.11.12
		Last modified date: 1.11.12
		Description:        data storage main file fo unit test and functionlity test
		Text Editor:	    gVim
		File Type:  	    cpp File
***********************************************************************/


/* standard libaries */
#include <iostream>
#include <cstring>

/*local libaries*/
#include "dataStructre.h"
using namespace std;

int main()
{
#ifdef _UNITTEST
	/*initilize*/
	DataStorage_t ds(64);
	ds.XpndValue(16);
		
	bool Bool=false,Obool;
	char Char='1',Ochar;
	unsigned char Uchar='2',Ouchar;
	int Int=3,Oint;
	unsigned int Uint=4,Ouint;
	short Short=5,Oshort;
	unsigned short Ushort=6,Oushort;
	long	Long=7,Olong;
	unsigned long Ulong=8,Oulong;
	float Float=9,Oflaot;
	double Double=10,Odouble;	 
	
	cout << "Unit test 1 input to buffer all types"<<endl;
	cout << "cursor position"<< ds.ByteSize() <<endl;

	ds << Bool;	
	ds << Char;
	ds << Uchar;
	ds << Int;
	ds << Uint;
	ds << Short;
	ds << Ushort;
	ds << Long;
	ds << Ulong;
	ds << Float;
	ds << Double;
	cout << "cursor position after input"<<ds.ByteSize()<<endl;

	cout <<"read buffer"<<endl;
	
	ds >> Obool;
	cout << Obool <<endl;

	ds >> Ochar;
	cout << Ochar <<endl;

	ds >> Ouchar;
	cout << Ouchar <<endl;

	ds >> Oint;
	cout << Oint <<endl;

	ds >> Ouint;
	cout << Ouint <<endl;
	
	ds >> Oshort;
	cout << Oshort <<endl;

	ds >> Oushort;
	cout << Oushort <<endl;

	ds >> Olong;
	cout << Olong <<endl;

	ds >> Oulong;
	cout << Oulong <<endl;

	ds >> Oflaot;
	cout << Oflaot <<endl;

	ds >> Odouble;
	cout << Odouble <<endl;
	
	/*unit test 2 rewind cursor and print*/
	cout<<"rewind cursor and print again"<<endl;
	ds.Reset();

	ds >> Obool;
	cout << Obool <<endl;

	ds >> Ochar;
	cout << Ochar <<endl;

	ds >> Ouchar;
	cout << Ouchar <<endl;

	ds >> Oint;
	cout << Oint <<endl;

	ds >> Ouint;
	cout << Ouint <<endl;
	
	ds >> Oshort;
	cout << Oshort <<endl;

	ds >> Oushort;
	cout << Oushort <<endl;

	ds >> Olong;
	cout << Olong <<endl;

	ds >> Oulong;
	cout << Oulong <<endl;

	ds >> Oflaot;
	cout << Oflaot <<endl;

	ds >> Odouble;
	cout << Odouble <<endl;
	cout << "cursor position"<< ds.ByteSize() <<endl;

	/*unit test 3 write to buffer after new*/
	cout<<"write to buffer after new buffer"<<endl;
	ds.New();

	Bool =true;
	Char='2';
	Uchar='3';
	Int=4;
	ds << Bool;	
	ds << Char;
	ds << Uchar;
	ds << Int;

	ds >> Obool;
	cout << Obool <<endl;

	ds >> Ochar;
	cout << Ochar <<endl;

	ds >> Ouchar;
	cout << Ouchar <<endl;

	ds >> Oint;
	cout << Oint <<endl;

	ds >> Ouint;
	cout << Ouint <<endl;
	
	ds >> Oshort;
	cout << Oshort <<endl;

	ds >> Oushort;
	cout << Oushort <<endl;

	ds >> Olong;
	cout << Olong <<endl;

	ds >> Oulong;
	cout << Oulong <<endl;

	ds >> Oflaot;
	cout << Oflaot <<endl;

	ds >> Odouble;
	cout << Odouble <<endl;
	cout << "cursor position"<< ds.ByteSize() <<endl;
#endif
	return 0;
}
