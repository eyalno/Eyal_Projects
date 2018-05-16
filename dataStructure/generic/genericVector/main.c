/*************************************************************

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: vector main file unit test and functionality tests 
*************************************************************/

/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*local libaries*/
#include "ADTDefs.h"
#include "vector.h"

int main()
{

	Vector *tmp;
	int a=1,b=2,c=3,d=4;
	
	/*Unitest create add add set get destroy */
	tmp=VectorCreate(5,8);
	VectorAdd(tmp,&a);
	VectorAdd(tmp,&b);
	VectorAdd(tmp,&c);
	VectorAdd(tmp,&d);

	

	

return 0;
}
