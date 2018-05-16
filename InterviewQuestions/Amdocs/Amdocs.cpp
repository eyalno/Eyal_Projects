#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	List<int> lista;

	int h, k, j;
	h = 1;
	k = 2;
	j = 3;
	Node<int> e(h);
	Node<int> f(k);
	Node<int> g(j);

	
	//empty list
	lista.insert(&f);
	//insert b4 
	lista.insert(&e);
	lista.insert(&g);

	//delete end
	lista.deleteNode(&j);
	lista.insert(&g);

	//delete mid
	lista.deleteNode(&k);
	lista.insert(&f);

	//delete head
	lista.deleteNode(&h);
	lista.insert(&e);
	lista.find(&h);
////
	List<int> listaBetter;
	//empty list
	listaBetter.insertBetter(&f);
	//insert b4 
	listaBetter.insertBetter(&e);
	listaBetter.insertBetter(&g);

	//delete end
	listaBetter.deleteNodeBetter(&j);
	listaBetter.insertBetter(&g);

	//delete mid
	listaBetter.deleteNodeBetter(&k);
	listaBetter.insertBetter(&f);

	//delete head
	listaBetter.deleteNodeBetter(&h);
	listaBetter.insertBetter(&e);


	return 0;
}

