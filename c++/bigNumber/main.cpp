#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "big.h"

int main()
{


BigNumber p("56");
BigNumber q;
BigNumber m;

m=q=p;
q=88;

p.Print();
q.Print();
m.Print();



m=q+p;

m.Print();

printf("m>p\n");
m>p ? puts("True"):puts("False");

printf("m<p\n");
m<p ? puts("True"):puts("False");
	
printf("a==b\n");
p==q ? puts("True"):puts("False");
	
	return 1;
}
