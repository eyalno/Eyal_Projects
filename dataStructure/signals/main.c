/************************************************************************

		Author: Eyal Noy
		Creation date: 11.11.12
		Last modified date: 13.11.12
		Description: My Malloc main function , functionality and test
		Text Editor: 	gVim
***********************************************************************/



 







#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h> 
#include <string.h> 
#include <ctype.h>
#include <sys/wait.h> 



int signalParent = 5;
int signalChild = 6;

void SignalChildHandler(int _signal, siginfo_t* _signalInfo, void * _info)
{
	printf(" I am child ,recevied parent signal %d\n", _signal);
	kill(_signalInfo->si_pid ,signalChild);
	
}

void SignalParentHandler(int _signal)
{
	printf("I am parent,received child signal %d\n", _signal);
}

int main(int argc, char** argv)
{
	struct sigaction sa;
	/*int opt;*/
	pid_t pid;	 	
	
	/*
   	while ((opt = getopt(argc, argv, "c:p:")) != -1)
	{
		switch (opt)
		{
			case 'c':
			    signalChild = atoi(optarg);
					break;
			case 'p':
			    signalParent = atoi(optarg);
			    break;
			
			default: 
			    fprintf(stderr, "Usage: %s [-c] [-n numberOfTasks] \n",
				    argv[0]);
			    exit(EXIT_FAILURE);
		}
	}	
	
	*/
	if((pid = fork())) /*parent*/
	{
		sa.sa_handler = SignalParentHandler;
		sa.sa_flags = SA_RESTART;
		sigemptyset(&sa.sa_mask);

   		if (sigaction(signalChild, &sa, NULL) == -1) 
		{
			perror("sigaction");
			exit(1);
        	}
		sleep(1);   
        
       		kill(pid, signalParent);
     		wait(NULL);	
     			 
    	}
	else /*child*/
	{
		sa.sa_sigaction = SignalChildHandler;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);

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

 

 
