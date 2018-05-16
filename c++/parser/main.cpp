/**************************************************************************************
    Author : 
    Creation date :      29.10.12
    Date last modified :
    Description : 
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "parser.h"

using namespace std;

/************************************************main***********************************************************************/


int main( int argc ,const char** argv)
{

	Parser parser;
	parser.Run(argv[1]);	
	

	return 0 ;
}

	
