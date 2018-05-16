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
#include "cardGame.h"


#define SWAP 100

static void reverse(char s[])
{
int c, i, j;
for (i = 0, j = strlen(s)-1; i < j; i++, j--)
{
c = s[i];
s[i] = s[j];
s[j] = c;
}
}

static char* itoa(int n, char s[])
{
int i, sign;
if ((sign = n) < 0) 
n = -n;

i = 0;
do {

s[i++] = n % 10 + '0'; 
} while ((n /= 10) > 0);

if (sign < 0)
s[i++] = '-';
s[i] = '\0';
reverse(s);
return s;
}






void initilizeGame(Card **_arr,Player* _players )
{
int i;
int j;


for (i=0; i<NUM_PLAYERS;++i)
{
	memset(&_players[i],0,sizeof(Card*)*DECK);
	_players[i].m_Size = DECK / NUM_PLAYERS;
}


for (i=0;i < NUM_PLAYERS; ++i)
{
	for (j=0;j<DECK/NUM_PLAYERS;++j)
	{
		_arr[i*DECK/NUM_PLAYERS+j]=(Card*)malloc(sizeof(Card));
		_arr[i*DECK/NUM_PLAYERS+j]->m_Value=2+j;
		_arr[i*DECK/NUM_PLAYERS+j]->m_Symbol=i;
	}
}

/*
for (i=0; i<DECK; i++)
	printf("%d %d ",_arr[i]->m_Value,_arr[i]->m_Symbol);
*/
}


void shuffleCards(Card** _arr)
{
	Card *tmp;
	int i;
	int num;
	srand(time(NULL));
	
	for (i=0; i<SWAP ;++i)
	{
		num=rand();
		tmp=_arr[num % DECK];
		_arr[num % DECK]=_arr[(num-2) % DECK];
		_arr[(num-2) % DECK]=tmp;
	}
	
}

void printHand(Player*_players)
{
int playerNum,j;
SYMBOL symbol;
char num[4];
char spc[5]="";
char spac[5]=" ";
for (playerNum=0;playerNum < NUM_PLAYERS; ++playerNum)
{	
	printf("Player %d Num of cards %d:\n\n",playerNum+1,_players[playerNum].m_Size);
	for (symbol=0; symbol<4;++symbol)
	{
		switch(symbol)
		{
			case HEART:
				puts("Heart:");
			 	break;
			case SPADE:
				puts("Spade:");
				break;
			case DIAMOND:
				puts("Diamond:");
				break;
			case CLUB:
				puts("Club:");		
				break;
		}
		for (j=0;j<DECK/NUM_PLAYERS;++j)
		{
				printf("%s",(_players[playerNum].m_Cards[symbol][j])? itoa(_players[playerNum].m_Cards[symbol][j]->m_Value,num) :spc );
				printf("%s",(_players[playerNum].m_Cards[symbol][j]) ? spac :spc );
			
		}
		puts("");
	}
}
puts("***************************************************************");
}


 void dealCards(Card** _arr,Player* _players)
{

int i;

for (i=0;i<DECK;++i)
{
	_players[i%NUM_PLAYERS].m_Cards[_arr[i]->m_Symbol][_arr[i]->m_Value-2] =_arr[i];
}

}

void play(Player* _players)
{

int playerNum=0;
int symbolNum,cardNum;
int i,j,first;
int round=1;	
srand(time(NULL));
	
	while(1)
	{
		/*
		if (round>3)
			return;	
		*/
		printf("Round No. %d\n\n",round++);
		printHand(_players);
	
		
		for (j=0; j < NUM_PLAYERS;++j)
		{	
			if(!_players[j].m_Size)
			{
				printf("player %d won !!!\n",j);
				
				if(!_players[(j+1)%NUM_PLAYERS].m_Size)
				{
					printf("player %d won too !!!\n",(j+1)&NUM_PLAYERS);
				}
				return;
			}
		}


		do
		{	
			symbolNum=rand() % 4;	
			cardNum = rand()% NUM_CARDS_SYMBOL;
			
		}while(!(_players[playerNum].m_Cards[symbolNum][cardNum]));
		
		first=playerNum;
		
		++playerNum;
		playerNum%=NUM_PLAYERS;
		
		for (i=12; i>0; --i)
		{
			
			if (_players[first].m_Cards[symbolNum][cardNum] < _players[playerNum].m_Cards[symbolNum][i])
			{
				break;
			}
			
		}

		if (i)
		{
			_players[playerNum].m_Cards[symbolNum][i]=NULL;
			--_players[playerNum].m_Size;
			++playerNum;
		}
		else
		{
			_players[playerNum].m_Cards[symbolNum][cardNum]=_players[first].m_Cards[symbolNum][cardNum];
		}

	_players[first].m_Cards[symbolNum][cardNum]=NULL;
	--_players[first].m_Size;
	
	
	}

}


