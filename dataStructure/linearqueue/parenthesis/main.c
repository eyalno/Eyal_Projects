/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "ADTDefs.h"
#include "vector.h"
#include "stack.h"

int main(){

char formula[100];
int status=-1;


#ifdef DEBUG
puts("Eyal Noy");
#endif

puts("Enter Formula:");
gets(formula);

if (((status=checkParenthesis(formula))==-1)){
	puts("O.K");
}
else{
	puts("Not O.K");
	printf("%d\n",status);
	
}


return 0;
}
