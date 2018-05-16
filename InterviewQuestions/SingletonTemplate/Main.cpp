#include "Singleton.h"



int main()
{
	int * num = singleton<int>::getInstance();


	singleton<int>::getInstance();


	
}