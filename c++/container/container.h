
/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    
		Last modified date: 27.11.2012
		Description:        generic container list or vector
		File Type:  	    cpp File
***********************************************************************/

#ifndef _T_CONTAINER_H
#define _T_CONTAINER_H


#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include <list>

using namespace std;

//template<typename T, class Collection>
template<typename T, template <class T,class Allocator=allocator<T> > class Collection>
class Tcontainer_t
{
	public:
		

		//const
		Tcontainer_t(){} //ctor
		
		~Tcontainer_t(){}//dtor

		bool IsEmpty() { return m_items.empty();}
		
		int Size() { return m_items.size(); }

		void InsertEnd(T* _element) 
		{ 
			T* temp = new T;
			*temp= *_element;
			m_items.push_back(temp); 
		}

		T* FirstElement()  {return m_items.front();}

		T* LastElement() {return m_items.back();}

		
		bool Find(T& _element)
		{
			MyPred pred;
			pred.x=_element;
			return  m_items.end() != find_if(m_items.begin(), m_items.end(), pred);
		}

		
		T* RemoveElement(T& _element)
		{
			MyPred pred;
			pred.x=_element;
			typename Items::iterator itr;
			itr = find_if(m_items.begin(), m_items.end(), pred);
					
			
			return itr== m_items.end() ? NULL : *(m_items.erase(itr));
		}

		void RemoveAll() 
		{
			m_items.erase(m_items.begin(),m_items.end());
		}

		void DeleteElement(T& _element)
		{
			delete RemoveElement(_element);
			
		}

		void DeleteAll()
		{
			while (m_items.begin() != m_items.end())
			{
				delete * m_items.erase(m_items.begin());
			}
		}
		
		T* operator[](size_t _num)
		{
			if (typeid (m_items) == typeid(vector<T*>))
			{
				vector<T*> *vec = (vector<T*> *) &m_items;	
				return (*vec)[_num];
			}
			else
			{
				Iter itr=m_items.begin();

				for(size_t i=0; i<_num; ++i,++itr);
				return *itr;
					
			}
		}

	private:
		typedef Collection<T*> Items;
			
		typedef typename Items::const_iterator Iter;

		Items m_items;        

		Tcontainer_t (const Tcontainer_t & _container);

		const Tcontainer_t& operator=(const Tcontainer_t & _container);

		struct MyPred
		{
		    T x;

		    bool operator()(T* i)
		    {
			return (*i == x);
		    }
		};
};
/*inline functions*/


#endif /*_DATA_STORAGE_H */
