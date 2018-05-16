/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    
		Last modified date: 27.11.2012
		Description:        generic container list or vector
		File Type:  	    cpp File
***********************************************************************/


/* standard libaries */
#include <iostream>

/*local libaries*/
#include "T9.h"

using namespace std;

int main()
{
	DataStructure t9;
	char number;
	
	string word;
	
	do
	{
		cout<<"enter word to dictionary"<<endl;
		cin>>word;
		t9.InsertWord(word);
	}while(word != "exit");

	
	DataStructure * ptr=&t9;
	do
	{

		cout <<"enter number or 1 to change word 0 to reset"<<endl; //cant cin #
		cin >>number;
		
		if (!(number-'0'))
		{
			ptr =&t9;
		}
		
		cout << ptr->SearchWord(number,&ptr) <<endl;			
		
	
	}while(1);
	
	
	
	return 0;
}
