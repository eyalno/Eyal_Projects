
#ifndef PERSON_H
#define PERSON_H


struct person_t{
	char *name;
	int age;
};

typedef struct person_t person_t;

void sort(int size,person_t* arr);
	


void print(int size,person_t* arr);


void freeArr(int size,person_t*);




#endif
