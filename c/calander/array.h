#include <stdio.h>

#ifndef ARRAY_H
#define ARRAY_H

typedef struct Meeting{
int m_Start;
int m_End;
char m_Subject[20];
}Meeting;

typedef struct array_t{
	Meeting** arr;
	int capacity;
	int numOfElements;
	int expandValue;
}array_t;

void printCalander(array_t* calander);
void resize(array_t*);
int findMeeting(array_t*);
void insert(array_t *,Meeting*);
array_t * initilizeCalander();
void rmv(array_t *);
void enterMeeting(array_t*,int);
void freeArr(array_t*);

#endif


