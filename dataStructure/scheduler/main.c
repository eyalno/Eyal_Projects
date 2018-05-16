/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
		Text Editor: 	gVim
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

/*local libaries*/
#include "ADTDefs.h"
#include "scheduler.h"
#include "logger.h"

static Timespec startTime;



/*task functions*/ 
int A(void * _params)
{
	static int  params = 1;
	Timespec currentTime;
	
	clock_gettime( CLOCK_REALTIME, &currentTime);

	printf("Im Dwarf A       Call Number: %-10dTime: %d\n",params,(int)(currentTime.tv_sec-startTime.tv_sec));

	++params;
	if (params == *(int*)_params )
	{
		params=1;
		return 1;
	}
	return params == *(int*)_params ? 1:0 ;
}

int B(void * _params)
{
	static int  params = 1;
	Timespec currentTime;
	

	clock_gettime( CLOCK_REALTIME, &currentTime);

	printf("Im Dwarf B       Call Number: %-10dTime: %d\n",params,(int)(currentTime.tv_sec-startTime.tv_sec));

	++params;
	if (params == *(int*)_params )
	{
		params=1;
		return 1;
	}
	return params == *(int*)_params ? 1:0 ;
}

int C(void * _params)
{
	static int  params = 1;
	Timespec currentTime;
	
	clock_gettime( CLOCK_REALTIME, &currentTime);

	printf("Im Dwarf C       Call Number: %-10dTime: %d\n",params,(int)(currentTime.tv_sec-startTime.tv_sec));

	

	++params;
	if (params == *(int*)_params )
	{
		params=1;
		return 1;
	}
	return params == *(int*)_params ? 1:0 ;
}


int D(void * _params)
{
	static int  params = 1;
	Timespec currentTime;
	
	clock_gettime( CLOCK_REALTIME, &currentTime);

	printf("Im Dwarf D       Call Number: %-10dTime: %d\n",params,(int)(currentTime.tv_sec-startTime.tv_sec));

	

	++params;
	if (params == *(int*)_params )
	{
		params=1;
		return 1;
	}
	return params == *(int*)_params ? 1:0 ;
}


int main()
{
	int a=4,b=3,c=4,d=3; 
	Timespec aTime;
	Timespec bTime;
	Timespec cTime;
	Timespec dTime;
	Scheduler* scheduler;
		

	LogCreate(ERR | WARR | DEB |RMN,"logFileScheduler");
	
	clock_gettime( CLOCK_REALTIME, &startTime);

	aTime.tv_nsec=0;
	aTime.tv_sec=2;

	bTime.tv_nsec=0;
	bTime.tv_sec=4;

	cTime.tv_nsec=0;
	cTime.tv_sec=5;

	dTime.tv_nsec=0;
	dTime.tv_sec=3;

	/*unitest  insert and destroy without run destroy free tasks*/
	scheduler=SchedulerCreate();

	TaskInsert(scheduler,A,&a,&aTime);
	TaskInsert(scheduler,B,&b,&bTime);
	TaskInsert(scheduler,C,&c,&cTime);
	TaskInsert(scheduler,D,&d,&dTime);
	
	SchedulerDestroy(scheduler);
	

	/*unitest diffrent interval*/
	scheduler=SchedulerCreate();

	TaskInsert(scheduler,A,&a,&aTime);
	TaskInsert(scheduler,B,&b,&bTime);
	TaskInsert(scheduler,C,&c,&cTime);
	TaskInsert(scheduler,D,&d,&dTime);
	
	SchedulerRun(scheduler);
	SchedulerDestroy(scheduler);
	
	/*unitest nano resolution*/
	
	puts("nano resolution");
	aTime.tv_nsec=900000000;
	bTime.tv_nsec=900000000;
	cTime.tv_nsec=900000000;
	dTime.tv_nsec=900000000;
		
	scheduler=SchedulerCreate();

	TaskInsert(scheduler,A,&a,&aTime);
	TaskInsert(scheduler,B,&b,&bTime);
	TaskInsert(scheduler,C,&c,&cTime);
	TaskInsert(scheduler,D,&d,&dTime);
	
	SchedulerRun(scheduler);
	SchedulerDestroy(scheduler);
	
	LogDestroy();	
	
	return 0;
}
