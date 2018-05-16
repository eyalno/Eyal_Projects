

#ifndef _TOKENAYZER_H
#define _TOKENAYZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "analyzer.h"

using namespace std;

//tokenize line tokens into a string
class Tokenayzer  
{
	public:

	//ctor
	inline Tokenayzer();

	//the split function returns the tokenized vector
 	inline vector<string>& SplitToVector(const string & _str);
	
		
  	private:
	string m_delimiter;
	vector<string> m_vec;
};

//ctor 
inline Tokenayzer::Tokenayzer()
{
	m_delimiter=" \t()[]{};<>=+-*&";
}

//split sting into tokenized vector
inline vector<string>& Tokenayzer::SplitToVector(const string & _str )
{
	
	size_t found,start=0,length;

	//find the first token calulate if more than 1 char and push to vector
	do
  	{
		
		found=_str.find_first_of(m_delimiter,start);

		length= (found != start)? (found -start):1;

		m_vec.push_back(_str.substr(start,length));	
		
		start=found+1;	
  		
	}
	while (found != string::npos);
	
	return m_vec;

}
#endif
