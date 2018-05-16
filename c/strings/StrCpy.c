#include <stdio.h>
#include <string.h>

int StrCmp(char *s1 ,char * s2)
{
while((*s1 && *s2) && (*s1++ == *s2++));
return *(--s1)-*(--s2);

}

       		 
int main()
{
char s1[]={"eyal"};
char s2[]={"eyal"};

printf("%d",StrCmp(s1,s2));
return 1;
}
