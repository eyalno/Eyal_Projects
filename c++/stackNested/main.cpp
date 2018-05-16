/************************************************************************

		Author: Eyal Noy
		Creation date: 5.11.12
		Last modified date: 5.11.12
		Description: Stack main file unitest and functionality test
		Text Editor: 	gVim
***********************************************************************/
/* standard libaries */
#include <iostream>
#include <string>

/*local libaries*/
#include "stack.h"

#define ARRAY_SIZE 10
#define STRING_ARRAY_SIZE 5

using namespace std;

int main( int argc ,const char** argv)
{
	
	/*Unit test 1 Int type push items to stack peek and remove stack and print*/
	cout<< endl <<"Unit test 1 Int type push items to stack remove return data stack and print"<<endl<<endl;
	Stack_t<int> stackInt;
	int arr[ARRAY_SIZE];

	if (!&stackInt.Pop())
	{
		cout <<"stack is empty Pop"<<endl;
	}
	
	if (!&stackInt.Peek())
	{
		cout <<"stack is empty Peek"<<endl;
	}
	
	for (int i=0;i < ARRAY_SIZE; ++i)
	{
		arr[i]=(i+8)%7;
		stackInt.Push(arr[i]);
	}		
	
	for (int i=0;i < ARRAY_SIZE; ++i)
	{
		cout << "Item:  "<<stackInt.Pop() << endl;
	}

	if (!&stackInt.Pop())
	{
		cout <<"stack is empty Pop" <<endl;
	}
	
	if (!&stackInt.Peek())
	{
		cout <<"stack is empty Peek"<<endl;
	}
			
	/*Unit test 2 Int type push items to stack peek and remove stack and print*/
	cout<< endl <<"Unit test 1 Int type push items to stack peek and remove return peek data stack and print"<<endl<<endl;
	for (int i=0;i < ARRAY_SIZE; ++i)
	{
		arr[i]=(i+8)%7;
		stackInt.Push(arr[i]);
	}		
	
	for (int i=0;i < ARRAY_SIZE; ++i)
	{
		cout << "Item:  "<<stackInt.Peek() << endl;
		stackInt.Pop();
	}

	if (!&stackInt.Pop())
	{
		cout <<"stack is empty Pop"<<endl;
	}
	
	if (!&stackInt.Peek())
	{
		cout <<"stack is empty Peek"<<endl;
	}
	/*Unit test 3 Class string type push items to stack peek and remove stack and print*/
	cout<< endl <<"Unit test 3 string type push items to stack remove return data stack and print"<<endl<<endl;
	Stack_t<string> stackString;
	string arrString[ARRAY_SIZE];

	
		arrString[0]="Eyal";
		arrString[1]="Noy";
		arrString[2]="Eitan";
		arrString[3]="Alon";
		arrString[4]="Noy";
		
	for (int i=0;i < STRING_ARRAY_SIZE; ++i)
	{
		stackString.Push(arrString[i]);
	}
	
	for (int i=0;i <STRING_ARRAY_SIZE; ++i)
	{
		cout << "Item:  "<<stackString.Pop() << endl;
	}

	if (!&stackString.Pop())
	{
		cout <<"stack is empty Pop"<<endl;
	}
	
	if (!&stackString.Peek())
	{
		cout <<"stack is empty Peek"<<endl;
	}
			
	/*Unit test 4 string type push items to stack peek and remove stack and print*/
	cout<< endl <<"Unit test 4 string type push items to stack peek and remove return peek data stack and print"<<endl<<endl;
	
	for (int i=0;i < STRING_ARRAY_SIZE; ++i)
	{
		stackString.Push(arrString[i]);
	}
	
	for (int i=0;i < STRING_ARRAY_SIZE; ++i)
	{
		cout << "Item:  "<<stackString.Peek() << endl;
		stackString.Pop();
	}

	if (!&stackString.Pop())
	{
		cout <<"stack is empty Pop"<<endl;
	}
	
	if (!&stackString.Peek())
	{
		cout <<"stack is empty Peek"<<endl;
	}

	
	




	return 0 ;
}

	
