/************************************************************************

		Author: Eyal Noy
		Creation date: 5.11.12
		Last modified date: 5.11.12
		Description: 
***********************************************************************/
/* standard libaries */
#include <iostream>

/*local libaries*/
#include "memPage.h"
#include "memPool.h"
using namespace std;



int main( )
{

	#ifdef UNITEST_1
	int a=1;
	int b=2;
	int c=3;

	cout<<"int extend page"<<endl;		
	memPool_t pool(5,10);

	pool.write(&a,4);
	pool.write(&b,4);
	pool.write(&c,4);
	
	
	pool.read(&c,4,0);
	pool.read(&a,4);
	pool.read(&b,4);

	cout <<  c <<endl<<a<<endl<<b<<endl;
	#endif

	#ifdef UNITEST_2
	int a=1;
	int b=2;
	int c=3;

	cout<<"add new pages if full"<<endl;		
	memPool_t pool(1,10);

	pool.write(&a,4);
	pool.write(&b,4);
	pool.write(&c,4);
	
	
	pool.read(&c,4,0);
	pool.read(&a,4);
	pool.read(&b,4);

	cout <<  c <<endl<<a<<endl<<b<<endl;
	#endif



	return 0 ;
}

	
/*
	try
	{
		Div(0);			

	}catch (TException_t<int>& object)
	{
		cout << object.what()<<" "<< object.FileName()<<" "<<object.LineNumber()<<" " <<endl;
	}
	
*/
