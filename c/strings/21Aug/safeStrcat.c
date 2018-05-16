#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void  strCat(char **dest,char *src){
	
	int length=strlen(*dest);
	char *pos;
	
	*dest= (char *) realloc(*dest,strlen(*dest)+strlen(src)+1);
	
	for(pos=*dest+length; (*pos++=*src++););
		
}

       		 
int main(){

	char s1[100];
	char s2[100];
	char *ptr1;
	char *ptr2;	

	puts("Enter first string");
	gets(s1);
	ptr1=(char*)malloc(sizeof(s1));
	
	puts("Enter second string");
	gets(s2);
	ptr2=(char*)malloc(sizeof(s2));	
	strcpy(ptr1,s1);
	strcpy(ptr2,s2);	
	
	strCat(&ptr1,ptr2);
	puts(ptr1);
		
	free(ptr1);
	free(ptr2);
	return 0;
}
