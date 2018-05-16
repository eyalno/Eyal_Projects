#include <stdio.h>
#include <stdlib.h>
#include "array.h"




void freeArr(array_t* school,int num){

int i;


for (i=0; i<num; i++)
	free((school+i)->arr);
free(school);



}
