/************************************************************************

		Author: Eyal Noy
		Creation date: 5.11.12
		Last modified date: 5.11.12
		Description: exception handler
		Text Editor: 	gVim
***********************************************************************/
/* standard libaries */
#include <iostream>

/*local libaries*/
#include "exceptionHandler.h"

using namespace std;

void Div(int _num)
{
	if (!_num)
	{
		TException_t<int> exception(_num,"division by zero",__FILE__,__LINE__);
		throw  exception;
	}

}


int main( )
{
	try
	{
		Div(0);			

	}catch (TException_t<int>& object)
	{
		cout << object.what()<<" "<< object.FileName()<<" "<<object.LineNumber()<<" " <<endl;
	}
	

	return 0 ;
}

	
