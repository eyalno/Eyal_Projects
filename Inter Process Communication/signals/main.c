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
#include <signal.h>
#include <sys/types.h> 
#include <sys/wait.h> 



int signalParent;
int signalChild;
int sleepMili;

/*signal action example*/
void SignalChildHandler(int _signal, siginfo_t* _signalInfo, void * _info)
{
	printf("I am child ,recevied parent signal %d\n", _signal);
	kill(_signalInfo->si_pid ,signalChild);
	
}

/*signal handler*/
void SignalParentHandler(int _signal)
{
	printf("I am parent,received child signal %d\n", _signal);
}

int main(int argc, char** argv)
{
	struct sigaction sa;
	int opt;
	pid_t pid;	 	
	
	/*tokeneize all options and their values: signal time*/
   	while ((opt = getopt(argc, argv, "c:p:s:")) != -1)
	{
		switch (opt)
		{
			case 'c':
			    	signalChild = atoi(optarg);
				break;
			case 'p':
			    	signalParent = atoi(optarg);
			    	break;
			
			case 's':
			    	sleepMili = atoi(optarg);
			    	break;
			default: 
				break;
		}
	}	
	
	
	if((pid = fork())) /*parent process*/
	{
		/*initilize struct to handler unmask and flags*/
		sa.sa_handler = SignalParentHandler;
		sa.sa_flags = SA_RESTART;
		sigemptyset(&sa.sa_mask);

   		/*link parent to signal */
		if (sigaction(signalChild, &sa, NULL) == -1) 
		{
			perror("sigaction");
			exit(1);
        	}
		
		usleep(1000*sleepMili);   
        
       		kill(pid, signalParent);
     		

		wait(NULL);	
     			 
    	}
	else /*child 0*/
	{
		/*initilize struct to handler unmask and flags*/
		sa.sa_sigaction = SignalChildHandler;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);

   		/*signal to change*/
   		if (sigaction(signalParent, &sa, NULL) == -1) 
		{
        		perror("sigaction");
       			exit(1);
     		}  
    	    	
     		pause();	
     	
     		exit(0);
		
	}
    
    return 0;
    
}  

 

 
