/************************************************************************

		Author: Eyal Noy
		Creation date: 11.11.12
		Last modified date: 13.11.12
		Description: My Malloc main function , functionality and test
		Text Editor: 	gVim
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <stdlib.h>

/*local libaries*/
#include "myMalloc.h"
int main()
{
	void* a=NULL;
	void* b=NULL;
	void* c=NULL;
	void* d=NULL;
	void* mem1=malloc(80);
	void* mem2=malloc(80);
	
	/***********************UNIT TEST 1****************/
	puts("\n***** Unit Test 1 initilize 2 diffrent memmories *****");
	
	c=d=b=a;
	a=c;
	MyMallocInit(mem1,81);	
	MyMallocInit(mem2,83);



	/***********************UNIT TEST 2****************/
	puts("\n***** Unit Test 2 insert memmory and no space *****");
	
	a=MyMalloc(mem1,10);	
	b=MyMalloc(mem1,20);	
	c=MyMalloc(mem1,5);	
	d=MyMalloc(mem1,40);	

	/***********************UNIT TEST 3****************/
	puts("\n***** Unit Test 3 free memmory and defrag *****");


	MyFree(b);
	MyFree(a);
	MyFree(c);

	

	return 0;
}
