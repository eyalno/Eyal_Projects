/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    
		Last modified date: 27.11.2012
		Description:        generic container list or vector
		File Type:  	    cpp File
***********************************************************************/


/* standard libaries */
#include <stdio.h>
#include <iostream>
#include <stack>
#include <list>

/*local libaries*/
#include "stlExc.h"

using namespace std;

int main()
{

/***************************Tops*************************************************/
	stack<int> myStack1;
	stack<int> myStack2;
	stack<int> myStack3;

	list<stack<int>* > myList;

	list<int> * newList;

	
	for(int i=0; i<5; ++i)
	{
		myStack1.push(i);
	}
	
	for(int i=5; i<10; ++i)
	{
		myStack2.push(i);
	}
	
	for(int i=10; i<15; ++i)
	{
		myStack3.push(i);
	}
	
	myList.push_back(&myStack1);
	myList.push_back(&myStack2);
	myList.push_back(&myStack3);

	newList = Tops(myList);
	
	for (list<int>::iterator it=newList->begin(); it!=newList->end() ; ++it)
    		cout << " " << *it<<endl;

/*********************PreFix******************************************************************/
	cout<<endl<<"Prefix"<<endl;	

	cout<<PreFix("eyal","a")<<endl;
	cout<<PreFix("eyal","b")<<endl;
	cout<<PreFix("eyal noy","o")<<endl;
	cout<<PreFix("eyalnoy ","n")<<endl;




/**********************Most Common**************************************************************************/	

	list<string> stringList;

	for (int i=0; i<20;++i)
	{
		stringList.push_back("eyal");
	}

	for (int i=0; i<2;++i)
	{
		stringList.push_back("noy");
	}

	for (int i=0; i<4;++i)
	{
		stringList.push_back("eyal1");
	}

	cout<<endl<<"my common"<<endl;
	cout<<MostCommon(stringList)<<endl;


	return 0;
}
