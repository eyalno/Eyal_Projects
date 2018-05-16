/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: ADT handle error function
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>


/*local libaries*/
#include "ADTDefs.h"

#define STUB 0xdeadbeef 
#define TRUE 1
#define FALSE 0

void handleError(int error,char * additionalMsg){

char * arrErr[]= {"OK",
		  "General",
		  "Allocation Failed",
		  "Reallocation Failed",
		  "Not initilized",
		  "Index boundries",
		  "Overflow",
		  0};

		
		puts(arrErr[error]);
		if (additionalMsg)
			puts(additionalMsg);

}




