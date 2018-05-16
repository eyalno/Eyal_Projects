/************************************************************************

		Author: Eyal Noy
		Creation date: 5.11.12
		Last modified date: 5.11.12
		Description: Stack  header file nested class implementation using linkedlist 
		Text Editor:  gVim
***********************************************************************/


#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

using namespace std;


// 2 nested classes linked list and node class is template 
// and so are the nested classes 
template <class T>
class Stack_t
{
	public:
		
		Stack_t(){}   //default constructor
		
		virtual ~Stack_t(){} //virtual destructor
		
		//stack API
		void Push(const T& _data)
		{
			m_list.Insert(_data);		
		}
		
		const T& Pop()
		{
			return m_list.Remove();
		}
		
		const T& Peek() const
		{
			return m_list.GetDataList();	
		}
	
	private:
		
		class List_t
		{
			public:

				List_t()		//default constructor
				{
					m_head=NULL;
				}
				virtual ~List_t(){}	//virtual destructor
				
				//creates a new node insert and link and set as head pf link
				void Insert(const T& _data)
				{
					Node_t* newNode = new Node_t(_data);
					
					newNode->SetNext(m_head);
					m_head=newNode;
				}	
				
				//return the data of the head node delete the head and 
				//set head next to head
				const T& Remove()
				{
					if (!m_head)
					{
						return *(T*)0;
					}
					
					const T& tmpData = m_head->GetData();
					
					Node_t* tmp = m_head->NextNode(); 
					delete m_head;
					m_head=tmp;
					return tmpData;
				}
				
				//return the head data
				const T& GetDataList()const
				{
					return !m_head ? *(const T*)0 : m_head->GetData();
				}

			private:
	
			class Node_t
			{
				public:
					
					Node_t(){}  //default constructor
					
					virtual ~Node_t(){} //default destructor
					
					//creates new node with data
					Node_t(const T& _data)
					{
						m_data=_data;
						m_next=NULL;
					}
					
					//returns the next pointer
					Node_t* NextNode()const
					{
						return m_next;
					}

					// set the node to point to argument node
					void SetNext(Node_t* _node)
					{
						m_next=_node;
					}
			
					//returns data from node
					const T& GetData()const

					{
						return m_data;
					}
				private:
					
					T m_data; //data template
					Node_t* m_next; 
			};
			Node_t* m_head;
		};

		List_t m_list;

};
#endif
