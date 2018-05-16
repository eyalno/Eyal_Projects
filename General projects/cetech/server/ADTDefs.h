/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 28.10.12
		Description: ADT h file error enumuration and  handle error function
***********************************************************************/





#ifndef ADT_DEFS
#define ADT_DEFS

#define STUB 0xdeadbeef
#define TRUE 1
#define FALSE 0

void handleError(int error,char * );

typedef enum 
{

	ERR_OK=0,
	ERR_GENERAL,
	ERR_ALLOC_FAILED,
	ERR_REALLOC_FAILED,
	ERR_NOTINITILIZED,
	ERR_INDEX_BOUNDRIES,
	ERR_OVERFLOW,

/* VECTOR ERR*/

/*STACK ERR */

	ERR_END
}ADTErr;

typedef enum
{
	ZERO=0,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE

}Decimal;

typedef enum 
{

	PRE_ORDER=1,
	IN_ORDER,
	POST_ORDER

}TraverseMode;

#endif
