#include "Cache.h"
#include <iostream>
int main()
{
	// Let cache can hold 4 pages
	
	Cache cache;

	cache.referencePage(1);
	cache.referencePage(2);
	cache.referencePage(3);
	cache.referencePage(1);
	cache.referencePage(4);
	cache.referencePage(5);
	cache.referencePage(2);
	cache.referencePage(8);
	cache.referencePage(7);
	cache.referencePage(2);

	cache.printCache();
	
	return 0;
}