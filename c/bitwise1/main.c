/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
		Text Editor: 	gVim
***********************************************************************/
/* standard libaries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_binary(int n) 
{
    if (n == 0 || n ==1) 
        printf("%d",n);
    else {
        print_binary(n >> 1);
        printf("%d",n & 0x1);
    }
}



int main()
{
	unsigned int num=652;
	
	char hexa[]="0123456789ABCDEF";
	int i=0;
	char output[8];

	print_binary(num);
	puts("");
	
	while (num > 0 ) 
    	{
        	output[i] = hexa[(num & 0xF)];
        	++i;
		num >>= 4;            
    	}
	--i;
	for (;i>=0;i--)
	{
		printf("%c",output[i]);
	}
	puts("");	


	return 0;
}
