#include <stdio.h>
#include <string.h>
#include <ctype.h>

int a2i(char *s1){
	
	
	int num=0;
	int symbol=1;

	/* whitespace */
	for(;*s1 && isspace(*s1);s1++);
		
	if (*s1 =='+')
		s1++;
	
	if (*s1 == '-'){
		symbol=-1;
		s1++;
	}
	
	for(;*s1 && isdigit(*s1);s1++)
		num= num *10 + *s1 - '0';
		
	if (symbol==-1)
		num*=-1;
	
	return num;
	
}

       		 
int main(){

	char s1[10];

	while(1){	
	puts("Enter string");
	gets(s1);

	printf("The number is:%d \n",a2i(s1));
	}
	return 0;
}
