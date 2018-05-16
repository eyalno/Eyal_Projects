#include <stdio.h>
#include <string.h>

#include "meeting.h"

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
printf("Compare result %d\n",p.compare(q));

q.setString("E");	
printf("Compare result %d\n",p.compare(q));

q.setString("Eyladasdasd");	
printf("Compare result %d\n",p.compare(q));

printf("Contains result %d\n",p.contains("Ey"));

printf("Contains result %d\n",p.contains("Eysdfs"));

p.prepend("Noy ");
printf("Prepend result %s\n",p.getString());

p.prepend(q);
printf("Prepend result %s\n",p.getString());



	return 1;
}
