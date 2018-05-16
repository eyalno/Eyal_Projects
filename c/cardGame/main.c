/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <stdlib.h>
/*local libaries*/
#include "ADTDefs.h"
#include "cardGame.h"

int main()
{
Card * arr[DECK];
Player players[NUM_PLAYERS];

initilizeGame(arr,players);
shuffleCards(arr);

dealCards(arr,players);
printHand(players);

play(players);

return 0;
}
