/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 28.10.12
		Description: Generic linked list h file functions forward declerations
***********************************************************************/



#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct List List;
typedef struct Node Node;
typedef Node* ListItr;
typedef void ListData;
typedef void (*PrintFunc)(ListData* );
typedef int (*CompFunc)(ListData*,ListData* );
typedef void (*DoFunc)(ListData*,void* );

/*creates and initilize list + stub */
List* ListCreate();

/*destroy linked list bottom up*/
void ListDestroy(List* _list);

/*create and place data to head of list*/
ADTErr ListPushHead(List* _list,ListData* _data);

/*create and place data to tail of list*/
ADTErr ListPushTail(List* _list,ListData* _data);

/*retrieves the the head data*/
ListData* ListPopHead(List *_list);

/*retrieves the the tail data*/
ListData* ListPopTail(List *_list);

/*count the data*/
size_t ListCountItems(List *_list);

/*checks if the list is empty*/
int ListIsEmpty(List*_list);

/*generic print function for all data types*/
void ListPrint(List* _list,PrintFunc);

/*returns iterator of the first item in the list tail if NULL*/
ListItr ListBegin(List* _list);

/*returns iterator of tail*/
ListItr ListEnd	(List* _list);

/*returns the next iterator */
ListItr ListNext (ListItr _itr);

/*returns the previous iterator*/
ListItr ListPrev (ListItr _itr);

/*retrieves the data in iterator*/
ListData* ListGetData(ListItr _itr);

/*insert item before the iterator*/
ListItr ListInsertBefore(ListItr _itr,ListData* _data);

/*search in the given range returns the iterator found*/
ListItr ListFindFirst(ListItr _from, ListItr _to, CompFunc compFunc, ListData* _data);

/*remove iterator and creates new links return the data*/
ListData* ListRemove(ListItr _itr);

/*apply the function on data range*/
ListItr ListForEach(ListItr _from, ListItr _to, DoFunc _doFunc, void* params);
#endif
