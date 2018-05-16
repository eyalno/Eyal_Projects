#ifndef	_ANALAIZER_H_
#define	_ANALAIZER_H_

#include <map>
using std::vector;
using std::string;
using std::map;


typedef enum {PREDEFINED , TYPE , CONDITION , LOOP , KEY , DELIM ,NUMBER , NOT_DEFINED } Token	;
typedef vector<string>::iterator Iter;

//the class analyze a line of text tokenized into vector and warns according to compiler rules
class Analyzer 
{
	public:
		
		//ctor destructor
		Analyzer( );
		virtual ~Analyzer();
		
		//the analyzing function input @ line number
		void Analyze( vector<string> & _tokens,size_t _line );
		
	
	protected:	

		
		
		//analyze and specify each token. used token ?		
		bool IsDefined ( string & _token );
		bool IsCondition( string & _token );
		bool IsNumber(string & _token );
		bool IsKey ( string & _token );
		bool IsLoop( string & _token );
		bool IsTypeName( string & _token ) ;
		bool IsDelimiter( string & _token );
		
		//encapsulate the above functions
		Token TokenType( string & _token );
		
		
		void HandleType (Iter & _iter, vector<string> & _tokens);
		void HandleDelimiter(Iter & _iter , vector<string> & _tokens);
		
		//print the error with the illegel rule
		void PrintError(const string & _msg );	
		 
		
		//holds types words and delimiters to compare to tokens
		vector<string> m_definedTypes;
		vector<string> m_keyWords;
		string m_delimiters;
		
		
		//holds already defined variable
		map<string,string> m_userDefined;
		
		
		size_t m_line; //error number
		
		//increment open decrement close 
		int m_conditionCount; 	
		int m_bracesCount;
		int m_parethesisCount;
		int m_barcketsCount;
		
		
		
		
		
	
};


#endif

