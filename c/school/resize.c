#include <stdio.h>
#include "array.h"
#include <stdlib.h>



void resize(array_t * unit){

unit->arr=(int*)realloc(unit->arr,sizeof(int)*(unit->capacity+unit->expandValue));
unit->capacity+=unit->expandValue;
}
