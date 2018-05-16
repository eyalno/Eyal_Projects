/*************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    
		Last modified date: 
		Description:        
		File Type:  	    cpp File
***********************************************************************/

#ifndef _T_CONTAINER_H
#define _T_CONTAINER_H


#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <stack>
#include <list>
#include <string>
#include <map>

using namespace std;

template<class T>
list<T>  * Tops(list< stack <T>* > & _list)
{
	
	typedef typename list<stack<T>* >::iterator Iter;
	list<T>  * ptr = new list <T>; 

	Iter itr=_list.begin();


	while (itr != _list.end())
	{
		if( !(**itr).empty() )
		{
			(*ptr).push_back( (**itr).top());
		}
		
		++itr;	
	}
	return ptr;
}

string PreFix(const string& _word,const string& _target)
{
	size_t found;
	
	string tmp;
	found=_word.find_first_of(_target);
	
	tmp=_word;
	if (found == string::npos)
	{
		return "";
	}
	tmp.resize(found);
	
	return tmp;
	


}


string MostCommon(list<string>& _list)
{
	typedef typename list<string>::iterator Iter;
	
	map<string,int> mymap;	
	int max=0;
	string result;
	int tmp;
	Iter itr=_list.begin();

	while (itr != _list.end())
	{
		if (mymap.find(*itr) == mymap.end())
		{
			mymap[*itr]=0;
		}
		else
		{
			tmp = ++mymap[*itr];
			if (tmp > max)
			{
				max =tmp;
				result=*itr;
			}
		}

		itr++;
	}
return result;
}
#endif


