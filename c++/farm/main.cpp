#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "car_t.h"
#include "ford_t.h"
#include "subaru_t.h"

int main()
{

ford_t a;
ford_t b(2000);
subaru_t c;

a.print();
b.print();
c.print();


a.changeSpeed(Twenty);

a.compare(b)?puts("equal"):puts("not equal");
a.compare(c)?puts("equal"):puts("not equal");

a<b?puts(true):puts("false");

a.print();

	return 1;
}
