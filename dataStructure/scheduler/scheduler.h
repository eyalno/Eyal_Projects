/************************************************************************

		Author: Eyal Noy
		Creation date: 7.11.12
		Last modified date: 7.11.12
		Description: scheduler psuedo API
		Text Editor:  gVim
***********************************************************************/



#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*generic function*/

/*function macro*/
typedef int (*DF)(void* _params);

/*structs macro*/
typedef struct Task Task;
typedef struct Scheduler Scheduler;
typedef struct timespec Timespec;
typedef void Data;

/*creates and initilize all data structers according to parameters*/
Scheduler * SchedulerCreate();

/*deallocate all allocated memmory*/
void	SchedulerDestroy(Scheduler* _scheduler);
 	
/*creates new task according to paramaters calculate her priority and insret to the priority structure*/
ADTErr TaskInsert(Scheduler* _scheduler,DF _func,Data* _data,Timespec* _interval);

/*the scheduler manage the priority structre and activate task to run mode */
ADTErr SchedulerRun(Scheduler* _scheduler);

/*pause scheduler*/
size_t SchedulerPause(Scheduler*);



#endif
