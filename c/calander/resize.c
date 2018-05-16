#include <stdio.h>
#include "array.h"
#include <stdlib.h>



void resize(array_t * unit){

unit->arr=(Meeting**)realloc(unit->arr,sizeof(Meeting*)*(unit->capacity+unit->expandValue));
unit->capacity+=unit->expandValue;
}
