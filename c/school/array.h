#ifndef ARRAY_H
#define ARRAY_H

typedef struct Metting{
int m_Start;
int m_Length;
char* m_Subject;
}Meeting;

typedef struct array_t{
	Meeting* arr;
	int capacity;
	int numOfElements;
	int expandValue;
}array_t;


void resize(array_t*);

void insert(array_t *);

void rmv(array_t *);

void freeArr(array_t*,int);

#endif


