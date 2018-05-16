#include <stdio.h>
#include <stdlib.h>
#include "array.h"




void freeArr(array_t* calander){

int i;


for (i=0; i<calander->numOfElements; i++)
	free(calander->arr[i]);
free(calander
);



}
