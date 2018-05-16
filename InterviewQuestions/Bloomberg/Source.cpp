#include "Filesystem.h"


#include <stdio.h>
#include <iostream>

void spaceRemove(char* str)
{	
	int space_counter = 0;
	int i = 0; //next index
	int idx = 0; //index 	
	
	for( ; str[i]; ++i)
	{
		if(str[i] == ' ')
		{
			++space_counter;
			//also reomve spaces from begining
			if(space_counter < 2 && idx != 0)
			{
				str[idx] = str[i];
				++idx;		
			}
		}		
		else
		{
			space_counter = 0;	
			str[idx] = str[i];
			++idx;
		}
	}
	str[idx] = 0;	
}


void spaceR()
{
	char str[] = "  eyal   noy  ";
	
	spaceRemove(str);
	puts(str);
	
	char str1[] = "  ab  cd  ef ";
	
	spaceRemove(str1);
	puts(str1);
	

}




void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// fix and continue
void permute(char * str, int pos ,int length )
{
	if (pos == length )
	{
		printf("%s\n",str);
		return;
	}
	
	if (pos > length )
	{
		return;
	}
	
	for (int j = pos ;j <= length ;j++)
	{
		swap (str + pos,str +j);
		permute(str,pos+1,length);
		swap (str + pos,str +j);
	}

}

void uniTestPermute()
{
	char a[] = "ABC";  
	permute(a, 0, 2);
	getchar();
}


void main()
{
	//fileSystem();

}



