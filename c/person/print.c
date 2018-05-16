#include <stdio.h>

#include "person.h"

void print(int size,person_t* arr){
        
        int i=0;
                        
        for (i=0;i<size;i++)    
                puts(arr[i].name);
                
}                      
