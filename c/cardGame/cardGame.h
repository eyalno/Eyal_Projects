/************************************************************************

		Author: Eyal Noy
		Creation date: 13.9.12
		Last modified date: 13.9.12
		Description: card game h file
***********************************************************************/



#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Card Card;
typedef struct Player Player;

struct Card
{
        SYMBOL m_Symbol;
        VALUE m_Value;
};

struct Player
{
        Card *m_Cards[4][13];

        int m_Size;
};





void initilizeGame(Card **_arr,Player* _players );

void shuffleCards(Card** _arr);
void printHand(Player*_players);

void dealCards(Card** _arr,Player* _players);

void play (Player*);


#endif
