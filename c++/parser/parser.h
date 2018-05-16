
#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include "tokenayzer.h"
#include "analyzer.h"

using namespace std;


class Parser:public Tokenayzer,public Analyzer
{
	public:
		
		inline void Run(const char* _fileName);

	private:

		
};

inline void Parser::Run(const char* _fileName)
{
	string str;
	Analyzer analyzeObject;

	ifstream inpFile;
	inpFile.open(_fileName);
	



	//main check

	vector<string> tmp;
	getline(inpFile,str);
	tmp=SplitToVector(str);
	
	Iter iter = tmp.begin();
	if ( iter == tmp.end() || *iter != "main" )
	{
		PrintError ("missing main statement");
	}
	else
	{
		/**erase main from line*/
		tmp.erase(tmp.begin() );
	}

	
	int counter=1;
	do
	{
		getline(inpFile,str);
		
		
		analyzeObject.Analyze(SplitToVector(str),counter);

		++counter;
	}
	while(!inpFile.eof());


	//end of file check
	if ( m_barcketsCount > 0 )
	{
		PrintError ("missing ']' " );
	}
	if ( m_conditionCount > 0 )
	{
		PrintError ("missing 'else' " );
	}
	if ( m_bracesCount > 0 )
	{
		PrintError ("missing ')'" );
	}
	if (m_parethesisCount  > 0 )
	{
		PrintError ( "missing '}'" );
	}



}
#endif
