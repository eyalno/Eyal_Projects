/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    3.9.12
		Last modified date: 4.9.12
		Description:        ADT handle error function
		Text Editor:	    gVim
		File Type:  	    c File
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*local libaries*/

typedef struct Logger
{
	char* m_logName;	
	char m_modes;
	FILE *pFile;
	int m_counter;
}Logger;

static Logger log;

int LogCreate( char _modes, const char* _logName )
{
	log.m_logName = (char*)malloc(1 + strlen(_logName));
	strcpy(log.m_logName,_logName);
	
	log.m_modes=_modes;
	log.pFile = fopen(_logName,"w");
	log.m_counter=1;
return 1;
}

void LogDestroy()
{
	fclose(log.pFile);
}

void LogRegister(char _mode,  const char* _message, const char* _Module, const char* _function)
{
	char *timeV, *p;
	time_t rawTime;
	time(&rawTime);

	timeV=ctime(&rawTime);
	p = strchr(timeV,'\n');	
	*p='\0';
	
	if(_mode & log.m_modes)
	{
		
		fprintf(log.pFile,"%d %s %s %s %s\n",log.m_counter,timeV,_Module,_function,_message);
	}

	++log.m_counter;

}

