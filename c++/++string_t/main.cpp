#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "string_t.h"

int main()
{

string_t p("Eyal");
string_t q;
string_t m;

m=q=p;
printf("The string %s\n",m.getString());
printf("The string %s\n",q.getString());
printf("The string %s\n",p.getString());

q.setString("Noy ");


printf("length :%d\n",p.length());

printf("The string %s\n",p.getString());

printf("The string %s\n",q.getString());

q.setString("Eyal");
printf("Compare result Eyal %d\n",p.compare(q));

q.setString("EYAL");	
printf("Compare result EYAL %d\n",p.compare(q));

q.setString("Eyladasdasd");	
printf("Compare result %d\n",p.compare(q));

printf("Contains result %d\n",p.contains("Ey"));

printf("Contains result %d\n",p.contains("Eysdfs"));

p.prepend("Noy ");
printf("Prepend result %s\n",p.getString());

p.prepend(q);
printf("Prepend result %s\n",p.getString());

p.setString("EYAl");
p.convertCase(tolower);
printf("Convert tp lower case: %s \n",p.getString());

p.convertCase(toupper);
printf("Convert tp upper case: %s \n",p.getString());
	
p.setString("a");
q.setString("b");
printf("a>b\n");
p>q ? puts("True"):puts("False");

printf("a<b\n");
p<q ? puts("True"):puts("False");
	
printf("a>=b\n");
p>=q ? puts("True"):puts("False");

printf("a<=b\n");
p<=q ? puts("True"):puts("False");
		
printf("a==b\n");
p==q ? puts("True"):puts("False");

printf("a!=b\n");
p!=q ? puts("True"):puts("False");
	
p+=q;
printf("a+=b %s\n",p.getString());

p+="bc";
printf("a+=b %s\n",p.getString());

p.setString("Eyal Eyal");
q=p(5,3);
printf("new q: %s\n",q.getString());

printf("first occurence : %d\n",p.findIndex(strchr,'a'));
printf("last occurence : %d\n",p.findIndex(strrchr,'a'));

printf("character num 1 : %c\n",p[1]);



	return 1;
}
