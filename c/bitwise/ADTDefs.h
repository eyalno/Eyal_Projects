/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: ADT h file error enumuration and  handle error function
***********************************************************************/
#ifndef ADT_DEFS
#define ADT_DEFS

#define STUB 0xdeadbeef
#define TRUE 1
#define FALSE 0
#define DECK 52
#define NUM_PLAYERS 4
#define NUM_CARDS_SYMBOL DECK/NUM_PLAYERS


typedef enum
{

        T=10,
        J,
        Q,
        K,
        A

}VALUE;

typedef enum
{
        HEART,
        SPADE,
        DIAMOND,
        CLUB
}SYMBOL;



#endif
