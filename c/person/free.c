#include <stdio.h>
#include "person.h"
#include <stdlib.h>


void freeArr(int size, person_t* arr){

        int i;
        for(i=0;i<size;i++)
                free(arr[i].name);
	free(arr);
		
}
