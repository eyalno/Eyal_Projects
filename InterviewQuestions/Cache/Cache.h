
//#include <iostream>
#include <list>
#include <map>

using namespace std;



class Cache
{
public:	
	void referencePage(unsigned int iPageNo);
	void printCache();


private:
	
	struct QNode
	{
		QNode(unsigned int iPageNo):iPageNo(iPageNo){}
		unsigned int iPageNo;
	};

	list<QNode*> lstQueue;
	
	map<unsigned int, list<QNode*>::iterator>  mapHash; // iterator & would be better?   -----no ptr or & 

	void deQueue();
	void enQueue(unsigned int iPageNo);

};

