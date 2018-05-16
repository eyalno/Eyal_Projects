#include "Cache.h"
#include <iostream>

#define CACHE_SIZE 4

void Cache::deQueue()
{
	lstQueue.pop_back();
}

void Cache::enQueue(unsigned int iPageNo)
{
	if (CACHE_SIZE == lstQueue.size())
	{
 		mapHash[lstQueue.back()->iPageNo] = lstQueue.end();
		deQueue();
	}

	auto* pQNode = new QNode(iPageNo);
	lstQueue.push_front(pQNode);
	
	auto  it = lstQueue.begin();
	mapHash[iPageNo] = it;
}

void Cache::referencePage(unsigned int iPageNo)
{
	auto  itMap = mapHash.find(iPageNo); //iterator map so i wont access twice should i use find or []
	
	if (itMap == mapHash.end() || itMap->second == lstQueue.end())
	{
		enQueue(iPageNo);
	}
	else
	{
		lstQueue.push_front(*(itMap->second));

		lstQueue.erase(itMap->second);
		mapHash[iPageNo] = lstQueue.begin();
	}
}

void Cache::printCache()
{
	cout << "Cache contains:";
	for (auto it = lstQueue.begin(); it != lstQueue.end(); ++it)
		cout << ' ' << (*it)->iPageNo;

	cout << '\n';
}