#include <stdio.h>
#include <string.h>

void squeeze(char *s1)
{
char * ptr = s1;
int i;

while (*ptr)
{
	for (i=0; *ptr++== ' ' ;i++);
	
	if (i > 1 )
	{	
		*(ptr-i)= '\0';
		strcat(s1,--ptr);
	}
	
}
if (*s1==' ')
{
	*s1='\0';
	strcat(s1,s1+1);

}
printf("%s\n",s1);

}

       		 
int main()
{
char s1[]={"  eyal    noy  "};

squeeze(s1);

return 1;
}
