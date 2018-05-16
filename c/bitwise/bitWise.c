/************************************************************************

		Author: Eyal Noy
		Creation date: 13.9.12
		Last modified date: 13.9.12
		Description: card game
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/*local libaries*/
#include "ADTDefs.h"
#include "bitWise.h"


/* struct bit informatio */
struct Bitmap
{
	int* features;
	int numFeatures;


};

/* allocating bytes accrods to number of features*/
void initilize(Bitmap* structBit,char *numFeatures)
{

	structBit->numFeatures = atoi(numFeatures);
	structBit->features=(int*)malloc(sizeof(int)*((structBit->numFeatures/32)+1));
	
}


int bitOn(int bit,Bitmap* structBit)
{
	structBit->features[bit/32] |= (bit%32);
return 1;
}

int bitOff(int bit,Bitmap* structBit)
{
	structBit->features[bit/32]&= (~(bit%32));
return 1;
}

int isBit(int bit,Bitmap* structBit)
{
	structBit->features[bit/32]&(bit%32) ? puts("Bit is Set"):puts("Bit not Set");
	return structBit->features[bit/32]&(bit%32);
 
}

void set(int,option,int bit,Bitmap* structBit)i
{
	bitW func[3]={bitOn,bitOff.isBit};
	func[option](bit,structBit);
	
	
}


