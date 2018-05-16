#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <ctype.h>

using namespace std;

#include "analyzer.h"

Analyzer::Analyzer()  
{

	//initilize counters
	m_bracesCount=0;
	m_parethesisCount=0;
	m_conditionCount=0;
	m_barcketsCount=0;

	//initilize keywords and delimiters to compare
	m_delimiters="()[]{};<>=+-*&";
	
	m_definedTypes.push_back( "char" );
	m_definedTypes.push_back( "short" );
	m_definedTypes.push_back( "int" );
	m_definedTypes.push_back( "long" );
	m_definedTypes.push_back( "float" );
	m_definedTypes.push_back( "double" );
	m_definedTypes.push_back( "void" );
	
	m_keyWords.push_back( "class" );
	m_keyWords.push_back( "private" );
	m_keyWords.push_back( "public" );
	m_keyWords.push_back( "protected" );
	m_keyWords.push_back( "main" );
	m_keyWords.push_back( "const" );
	m_keyWords.push_back( "virtual" );
	
	//initilize error line
	m_line=1;
}

Analyzer:: ~Analyzer(){}

//print the error number line number and specified message
void Analyzer::PrintError(const string & _msg )		
{
	static int number=1;

	cout << "Error #"<< number << " Line number: " << m_line <<" " << _msg << endl ;
	++number;
	
}

/**analyze file main function*/
void Analyzer::Analyze( vector<string> & _tokens,size_t _line )
{
	Iter iter= _tokens.begin();
	
	m_line=_line;
	
	//runs on all tokens in vector
	while ( iter != _tokens.end() )
	{
		string token = *iter;

		
		switch ( TokenType ( token ) )
		{
			
			case NUMBER:
				
				iter++;
				continue;
			
			case PREDEFINED:
					
				iter++;
				continue;
			
			case CONDITION:
				
				//increment decrement condition words as paranthess
				if ( *iter == "if" ) 
				{
					m_conditionCount++;
				}
				if ( *iter == "else" )
				{
					if ( m_conditionCount >0 )
					{
						m_conditionCount--;
					}
					else
					{
						PrintError(" more else than  if");
						m_conditionCount=0;
					}
				} 
				
				iter++;
				continue;
				
			case DELIM:
				
				HandleDelimiter(iter,_tokens);
				continue;
				
			case TYPE: 
				
				HandleType ( iter , _tokens );
				continue;
			case NOT_DEFINED:
				
				PrintError ( *iter + " token not defined" );
				iter++;
				continue;
				
			default:
				iter++;	
		}
	}
	
}
//test type rules
void Analyzer::HandleType (Iter & _iter, vector<string> & _tokens)
{
	Iter next= _iter+1;
	
	//type at the end of line 
	if ( next == _tokens.end() )
	{
		PrintError ( "no name after struct");
		
		_iter++;// handle trailing error

		return;
	}	
		
	//2 types structs in a row
	if ( IsTypeName( *next ) )
	{
		PrintError ( *_iter + "+" +*next );
		_iter+=2;// handle trailing error

		return;
	}
	
	//already defined 
	if ( IsDefined( *next )	)
	{
		PrintError ( *next+" Already defined");
		_iter += 2;// handle trailing error

		return;
	}
	
	//no name after type
	if ( IsDelimiter(*next) || IsKey(*next) || IsCondition(*next) || IsLoop(*next))
	{
		PrintError ( "no name after type");
		_iter+=2;// handle trailing error

		return;
	}

	if ( IsNumber ( *next ) )
	{
		PrintError( "number no variable");
		_iter += 2;// handle trailing error

		return;
	}
	
	// passed all test enter name to map 
	m_userDefined[*next]=*_iter;
	_iter++;// handle trailing error

			
}

//
void Analyzer::HandleDelimiter(Iter & _iter , vector<string> & _tokens)
{
	Iter next = _iter+1;
	
	// checks for illeagel operator
	if  ( (*_iter).find_first_of("+-<>=",0)==0 )
	{
	    
		if ( next != _tokens.end() && *next == *_iter )
		{
			if ( ++next !=_tokens.end() && *next == *_iter )
			{
				PrintError("Invalid operator ");
				_iter=_iter+3;//trailing errors
			}
			else
			{
				_iter=_iter+2;//trailing errors
			}
		}
		else
		{
			_iter=_iter+1;
		}
		return;
	}
	
	//count paranthess
	
	switch ( (*_iter)[0] )
	{
		case '(' :  
			m_bracesCount++;
			break;
				   
		case ')' :	
			if ( m_bracesCount <= 0)
			{
				PrintError(" missing ( " );
				m_bracesCount=0;
			}
			else
			{
				m_bracesCount--;
			}
			break;
					
		case '[' :  
			m_barcketsCount++;
			break;
		
		case ']' : 	
			if ( m_barcketsCount <= 0)
			{
				PrintError(" missing [ " );
				m_barcketsCount=0;
			}
			else
			{
				m_barcketsCount--;
			}
			break;
					
		case '{' :	
			m_parethesisCount++;
			break;
		
		case '}' :  
			if ( m_parethesisCount <= 0)
			{
				PrintError(" missing { " );
				m_parethesisCount=0;
			}
			else
			{
				m_parethesisCount--;
			}
			break;
	}

	_iter++;
	
} 
	


//analyze and specify each token. used token ?		
Token Analyzer::TokenType( string & _token )
{	
	
	if ( IsDefined(_token) )
	{
		return PREDEFINED ;
	}
	
	if ( IsTypeName(_token) ) 
	{
		return TYPE;
	}

	if ( IsCondition (_token) ) 
	{
		return CONDITION;
	}
	
	if ( IsDelimiter(_token) )
	{
		return DELIM;
	}
	if ( IsLoop(_token) ) 
	{
		return LOOP;
	}
	
	if ( IsKey(_token) ) 
	{
		return KEY;
	}
	
	if ( IsNumber(_token) ) 
	{
		return NUMBER;
	}

	return NOT_DEFINED;
} 



bool Analyzer::IsTypeName ( string & _token ) 
{
	return ( find(m_definedTypes.begin(),m_definedTypes.end(),_token) != m_definedTypes.end() );
}

bool Analyzer::IsDefined ( string & _token )
{
	return ( m_userDefined.find(_token) !=  m_userDefined.end() );
}

bool Analyzer::IsCondition( string & _token )
{
	return  ( _token == "if" || _token == "else" );
}

bool Analyzer::IsLoop( string & _token )
{
	return  ( _token == "while" || _token == "for" );
}

bool Analyzer::IsKey ( string & _token )
{
	return ( find(m_keyWords.begin(),m_keyWords.end(),_token) != m_keyWords.end() ) ;
}

bool Analyzer::IsDelimiter( string & _token )
{
	return ( m_delimiters.rfind(_token) != string::npos );
}

bool Analyzer::IsNumber(string & _token )
{
	return isdigit ( _token[0] );
}


