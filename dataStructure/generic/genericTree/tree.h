/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 31.10.12
		Description: Generic linked tree h file functions forward declerations
		Text Editor:	    gVim
		File Type:  	    h File
***********************************************************************/



#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define NUM_OF_SONS 2

typedef struct Tree Tree;
typedef struct Node Node;
typedef Node* TreeItr;
typedef void TreeData;
typedef int (*IsLeftBigger)(TreeData*, TreeData*);
typedef void (*PrintFunc)(TreeData* );
typedef int (*CompFunc)(TreeData*,TreeData* );
typedef void (*DoFunc)(TreeData*,void* );

/*creates and initilize tree + stub */
Tree* TreeCreate(IsLeftBigger _isLeftBigger);

int AreSimilar(Node* ) ;

/*destroy linked tree bottom up*/
void TreeDestroy(Tree* _tree);

/*create and place data to head of tree*/
TreeItr TreeFind(Tree* _tree,TreeData* _data);

/*create and place data to head of tree*/
TreeItr TreeInsert(Tree* _tree,TreeData* _data);

/*count the data*/
int TreeCount(Tree *_tree);

/*checks if the tree is empty*/
int TreeIsEmpty(Tree*_tree);

/*generic print function for all data types*/
void TreePrint(Tree* _tree,PrintFunc);

/*returns iterator of the first item in the tree tail if NULL*/
TreeItr TreeBegin(Tree* _tree);

/*returns iterator of tail*/
TreeItr TreeEnd	(Tree* _tree);

/*returns the next iterator */
TreeItr TreeNext (TreeItr _itr);

/*returns the previous iterator*/
TreeItr TreePrev (TreeItr _itr);

/*retrieves the data in iterator*/
TreeData* TreeGetData(TreeItr _itr);

/*remove iterator and creates new links return the data*/
TreeData* TreeRemove(TreeItr _itr);

/*apply the function on data range*/
TreeItr TreeForEach(Tree* _tree, TraverseMode _travMode, DoFunc _doFunc, void* params);
#endif
