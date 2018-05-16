/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 28.10.12
		Description: Generic linked list main function , functionality and test
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <string.h>

/*local libaries*/
#include "ADTDefs.h"
#include "linkedList.h"

typedef struct Person
{
	char *name;
	int age;
}Person;

/*print functions for diffrent data types*/
void Int(ListData* _data)
{
		printf("%d ",*(int*)_data)	;
}

void Pers(ListData* _data)
{
		printf("%s %d ",((Person*)_data)->name,((Person*)_data)->age)	;
}

int compare(ListData* _from,ListData* _to)
{
	Person* from=(Person*)_from,* to=(Person*)_to;

	return ((from->age == to->age) && !strcmp(from->name,to->name))?1:0;

}
/*Do function adds +3 to age*/
void Do(ListData* _data,void* _para)
{
	((Person*)_data)->age += *(int*)_para;
}

int main()
{

List* list,*list1;
int a=1,b=2,c=3;
char name1[]="Eyal";
char name2[]="Kobi";
char name3[]="moran";
Person p1,p2,p3;

p1.name=name1;
p2.name=name2;
p3.name=name3;
p1.age=28;
p2.age=28;
p3.age=26;

#ifdef _FUNC
/* functionality demonstration */
/*******************************/

list=ListCreate();
list1=ListCreate();

/*list is :empty*/
ListIsEmpty(list)?puts("empty"):puts("not empty");


/* push Head*/
puts(" push head 1 2 3");
ListPushHead(list,&a);
ListPushHead(list,&b);
ListPushHead(list,&c);
puts("The List:");
ListPrint(list,Int);

/* push tail*/
puts("push tail 1 2 3");
ListPushTail(list,&a);
ListPushTail(list,&b);
ListPushTail(list,&c);
puts("The List:");
ListPrint(list,Int);


/* counting items*/
puts("Number of Items:");
printf("%d\n",ListCountItems(list));


/* pop head and tail*/

puts("pop head and tail:");
ListPopTail(list);
ListPopHead(list);
puts("The List:");
ListPrint(list,Int);

/************************/
/*person data structure*/
puts("");
puts("Person data structure");

/*person list1 */
ListPushHead(list1,&p1);
ListPushHead(list1,&p2);

/*kobi 28 Eyal 28 */
puts("push head 2 items");
ListPrint(list1,Pers);

/*print begin kobi 28*/
puts("print begining");
Pers(ListGetData(ListBegin(list1)));
puts("");

/*print end eyal 28*/
puts("end");
Pers(ListGetData(ListEnd(list1)));
puts("");

/* print next eyal 28 */
puts("print next");
Pers(ListGetData(ListNext(ListBegin(list1))));
puts("");

/* print prev kobi 28*/
puts("print prev");
Pers(ListGetData(ListPrev(ListEnd(list1))));
puts("");

/*insert before data added moran 26*/
puts("insert before");
(ListInsertBefore(ListBegin(list1),&p3));
ListPrint(list1,Pers);

/*search kobi 28 */
puts("search item");
Pers(ListGetData(ListFindFirst(ListBegin(list1),ListEnd(list1),compare,&p2)));
puts("");

/*generic function adds 3 to age*/
puts("adds 3 to age.");
ListForEach(ListBegin(list1),ListEnd(list1),Do,&c);
ListPrint(list1,Pers);

/*remove moran */
puts("remove from the begining");
ListRemove(ListBegin(list1));
ListPrint(list1,Pers);
#endif

#ifdef _UNITTEST
/*Uni-Test                  */
/****************************/

/*1. Uni-test  listCreate*/
/*fail to allocate  */
if (!ListCreate())
{
	handleError(ERR_ALLOC_FAILED,NULL);
}


/*2. Uni-test function listPushTail\Head*/
/*fail initilize */

	handleError(ListPushTail(NULL,&a),"tail recevied null");
	handleError(ListPushHead(NULL,&b),"head recevied null");

/* Uni-test function listPopHead\Tail*/
/*fail initilize */


/*fail boundries*/
	list=ListCreate();
	ListPopHead(list);
	ListPopTail(list);

#endif


return 0;
}
