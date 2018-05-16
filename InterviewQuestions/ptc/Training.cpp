#include<iostream>
#include "Node.h"

int main(int argc, char** argv) 
{
	Node a(1);
	Node b(2);
	Node c(3);
	
	a.left = &b;
	a.right = &c;
		

	
	Node d(4);
	Node e(5);
	Node f(6);
	c.right = &d;
	d.right = &e;
	e.right = &f;

	int heightP = treeHeightP(&a);
	int heightR = treeHeightR(a);

	vector<int> myvector;
	myvector = longestPath(&a);
	for (vector<int>::iterator it  = myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;

	
	vector<int> myvectorRef = longestPathRef(&a);
	for (vector<int>::iterator itR  = myvectorRef.begin(); itR<myvectorRef.end(); itR++)
		std::cout << ' ' << *itR;

	
	
	vector<int>* myvectorPtr = longestPathPtr(&a);
	for (vector<int>::iterator itP  = myvectorPtr->begin(); itP<myvectorPtr->end(); itP++)
		std::cout << ' ' << *itP;

	
	
	return 0;
}

/*
A Ctor
A
B
B
A
B
B

  */