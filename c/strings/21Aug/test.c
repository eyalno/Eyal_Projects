#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>





int main()
{

	char sentence []="Rudolph is 12 years old";
	  char str [20];

	  sscanf (sentence,"%s",str);
	puts(str);
	sscanf(sentence,"%s",str);
	puts(str);
	return 0;
}
