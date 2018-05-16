/************************************************************************

		Author: Eyal Noy
		Creation date: 17.11.12
		Last modified date: 17.11.12
		Description: Signals exercise , send signal between 2 process
		Text Editor: 	gVim
***********************************************************************/

#ifndef _XOPEN_SOURCE_
	#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h> 
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FAIL -1
#define FILE_NAME 32
#define PRIVLIGES 0777
#define MSG_SIZE 64

int main(int argc, char** argv)
{
	int opt,err,fd,bytesRead;
        
	char msg[MSG_SIZE];
	
	
	int verbose;
	useconds_t sleepTime;
	char fileName[FILE_NAME];
	
	/*tokeneize all options and their values: signal time*/
   	while ((opt = getopt(argc, argv, "v:f:s:")) != FAIL)
	{
		switch (opt)
		{
			case 'v':
			    	verbose = atoi(optarg);
				break;
			
			case 's':
			    	sleepTime = atoi(optarg);
			    	break;

			case 'f':
				/*no need*/
			    	strcpy(fileName,optarg);
				break;

			default: 
				break;
		}
	}	
	


	if((fd=open(fileName,O_WRONLY) )== FAIL)
	{
		err=errno;
		perror("open file failed");
		return err;
	}
	

	while ((bytesRead=read(fd,msg,MSG_SIZE)!=EOF))
	{
		
		msg[bytesRead]='\0';
		puts(msg);

		
		if(verbose)
		{
			puts("bytes read");
			/*
			printf("Sends Ping #%d Pid:%d",i,pid);
			*/
		}
		

		
		usleep(sleepTime);
        }

	if (close(fd)==FAIL)
	{
		err=errno;
		perror("write to file failed");
		return err;
	}



    return 0;
    
}  

 

 
