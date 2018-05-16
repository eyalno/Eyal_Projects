/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*local libaries*/
#include "ADTDefs.h"
#include "bitWise.h"

int main(int argc,char* argv[])
{

Bitmap structBit;
int option;
int bit;	
	/* check command argument */
	if (argc !=2)
		return NULL;
	
	/* init struct according to arguments */
	initilize(&structBit,argv[1]);

	while(1)
	{

		puts("Choose option :");
		puts("0.Set Bit On");
		puts("1.Set Bit Off");
		puts("2.Is Bit ON/OFF");
		puts("3.Exit");
		
		scanf("%d",option);
		getchar();
		
		if (option==3)
		{
			return 0;
		}
		
		puts("Enter Bit to Explore");
		scanf("%d",bit);
		getchar();
		

		 set(option,1<<bit-1,&structBit);
		
	}	
	

return 0;
}
