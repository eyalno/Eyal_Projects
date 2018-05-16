#include <stdio.h>
#include "person.h"
#include <string.h>


void sort(int size,person_t* arr){
	int j;
        int i;
        int min=0;
        char * temp;
        for(i=0;i<size-1;i++){
                for(j=i+1;j<size; j++)
                        if (strcmp(arr[i].name,arr[j].name)>0)
                                min=j;

                if (i!=min){
                        temp=arr[i].name;
                        arr[i].name=arr[min].name;
                        arr[min].name=temp;

                }
        }

}

