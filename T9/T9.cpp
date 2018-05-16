#include <iostream>
#include <string>
#include "T9.h"
using namespace std;

#define KEYPAD 8
#define UPPER_CASE_ASCII 65
#define LOWER_CASE_ASCII 97
#define KEYPAD_OFFSET 2
#define ABC 26
#define LOWER_CASE_BIT 32


//initilize the array according to keypad LUT
static int keyPadLut[ABC]={	0,0,0, //2
				1,1,1, //3
				2,2,2, //4
				3,3,3, //5
				4,4,4, //6 
				5,5,5,5, //7
				6,6,6,   //8
				7,7,7,7, //9
			  };


string DataStructure::m_emptyString;


void DataStructure::InsertWord(const string  &_word)
{
	char ch;
	int num;
	DataStructure * ptr=this;

	//create new structure if doesnt exist
	for (/*ptr=this,*/ string::const_iterator it=_word.begin() ; it != _word.end(); it++ ) //cplus plus example y plus plus
	{
		ch =*it;
		num = keyPadLut[ (ch | LOWER_CASE_BIT) - LOWER_CASE_ASCII]; // relation between upper lower case is 32 bit 

		if(! (ptr->m_classArray[num]))
		{
			ptr->m_classArray[num]= new DataStructure;	//vector destructor destroy it>?i
		}

		ptr=ptr->m_classArray[num];
	}

	//insert the word
	ptr->m_words.push_back(_word);
	ptr->itWords=ptr->m_words.begin(); // don't know why i do this/
	//cout << * (ptr->itWords) <<endl;

}

DataStructure::DataStructure()
{
	m_classArray.resize(KEYPAD);
	itWords=m_words.begin();	
	m_emptyString="";
}



const string & DataStructure::SearchWord(char _number,DataStructure** _ptr)
{

	if (!*_ptr || _number >'9' || _number< '0' )
	{
		return m_emptyString;
	}

	if (_number == '1')
	{
		//do i need allif next pointer
		if( itWords != m_words.end() )
		{
			++itWords; 
		}
			
		if( itWords == m_words.end() )
		{	 
		 	itWords=m_words.begin();
		}

		return *itWords;

	}
	else
	{
		DataStructure* ptr=m_classArray[_number  -'0' -KEYPAD_OFFSET];
		if(ptr)
		{	
			//
			*_ptr= ptr;
			
			if (ptr->itWords  !=  m_words.end() )
			{
				return * (ptr->itWords);
			}
		}
		return m_emptyString;

	}
	

}

