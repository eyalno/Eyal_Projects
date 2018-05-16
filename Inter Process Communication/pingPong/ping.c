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
#define ON 1

int main(int argc, char** argv)
{
	int opt,err,fd,i;
        
	char msg[MSG_SIZE];
	
	
	int verbose;
	int numOfMessages;
	useconds_t sleepTime;
	char fileName[FILE_NAME];
	int create;
	int destroy;
	pid_t pid=getpid();
	
	/*tokeneize all options and their values: signal time*/
   	while ((opt = getopt(argc, argv, "v:n:f:s:c:d:")) != FAIL)
	{
		switch (opt)
		{
			case 'v':
			    	verbose = atoi(optarg);
				break;
			case 'n':
			    	 numOfMessages = atoi(optarg);
			    	break;
			
			case 's':
			    	sleepTime = atoi(optarg);
			    	break;

			case 'f':
			    	strcpy(fileName,optarg);
				break;
			case 'c':
			    	create = atoi(optarg);
			    	break;
			
			case 'd':
			    	destroy = atoi(optarg);
			    	break;

			default: 
				break;
		}
	}	
	


	if (create)
	{
		if (mkfifo(fileName,PRIVLIGES) == FAIL)
		{
			err=errno;
			perror("mkfifo failed");
			return err;
		}
	}

	if((fd=open(fileName,O_WRONLY) )== FAIL)
	{
			err=errno;
			perror("open file failed");
			return err;
	}
	
	
	for (i=1; i <= numOfMessages;++i)
	{
		sprintf(msg,"Ping #%d Pid:%d",i,pid);

		
		if(verbose)
		{
			printf("Sends Ping #%d Pid:%d",i,pid);
		}
		
		if (write(fd, msg, strlen(msg))==FAIL)
		{
			err=errno;
			perror("write to file failed");
			return err;
		}
		
		usleep(sleepTime);
        }

	if (close(fd)==FAIL)
	{
		err=errno;
		perror("write to file failed");
		return err;
	}

	if (destroy)
	{
		if (unlink(fileName)==FAIL)
		{
			err=errno;
			perror("unlink failed");
			return err;
		}
	}


    return 0;
    
}  

 

 
