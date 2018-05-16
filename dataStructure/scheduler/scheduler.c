/************************************************************************

		Author: Eyal Noy
		Creation date: 7.11.12
		Last modified date: 7.11.12
		Description: Scheduler implementation
		Text Editor:  gVim
***********************************************************************/



/* standard libaries */
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>

/*local libaries*/
#include "ADTDefs.h"
#include "scheduler.h"
#include "vector.h"
#include "heap.h"
#include "logger.h"

#define ONE_SEC_IN_NANO 1000000000

/*struct macro*/



/*Task local paramaters*/
struct Task
{
	DF m_func; 		/*task function returns the m_data which state if the task finished*/
	
	Data* m_data;		/*data is used as a stop condtion to indicate when the task "fully" finished */
				/*after the function finishes 1 itteration the data is changed e.g decremented -- */

	Timespec m_interval; 	/*interval time . the period when to call the task*/
	
	Timespec m_nextTimeToRun;	/*priority calculated at each task priority = current time + interval of task */
};

/*heap is data structure to manage priorities minimum heap the minimum extract min*/
struct Scheduler
{
	Heap* m_heap;
	Vector* m_vec;
	size_t m_isPaused;
};

/*compare time nano resolution*/
static int compareTime(Timespec* _time1,Timespec * _time2)
{
	
	if (_time1->tv_sec > _time2->tv_sec)
	{
		return 1;
	}
	else if (_time1->tv_sec < _time2->tv_sec)
	{
		return 0;	
	}
	
	return (_time1->tv_nsec > _time2->tv_nsec) ? 1:0;
}

/*compare tasks left bigger return 1 */
static int compareTaskTime(void* _time1,void* _time2 )
{
	Timespec* time1 = &(((Task*)_time1)->m_nextTimeToRun);
	Timespec* time2 = &(((Task*)_time2)->m_nextTimeToRun);
	
	return compareTime(time1,time2);
			
}

/*creates and initilize all data structers according to parameters*/
/*checks for allocation error */
Scheduler * SchedulerCreate()
{
	Scheduler * tmp;
	
	if (!(tmp=(Scheduler*)malloc(sizeof(Scheduler))))
	{
		LogRegister(ERR,"Scheduler allocated failed",__FILE__,__func__)	;
		return NULL;
	}		
	
	if (!(tmp->m_vec = VectorCreate(8,8)))
	{
		free(tmp);
		return NULL;
	}
	
	if (!(tmp->m_heap= HeapBuild(tmp->m_vec,compareTaskTime)))
	{
		VectorDestroy(tmp->m_vec);
		free(tmp);
		return NULL;
	}		
	
	tmp->m_isPaused=0;
	LogRegister(DEB,"scheduler created successfully",__FILE__,__func__)	;
	return tmp;
	
}

/*deallocate all allocated memmory*/
/*checks if heap is empty and destroy it */
/* */
void SchedulerDestroy(Scheduler* _scheduler)
{
	Task* task;
	assert(_scheduler);

	/*check free tasks*/
	if (HeapSize(_scheduler->m_heap))
	{
		LogRegister(DEB,"SchedulerDestroy free tasks",__FILE__,__func__)	;
		
	}	
	while (HeapSize(_scheduler->m_heap))
	{
		task = (Task*)HeapExtract(_scheduler->m_heap);		
		free(task);
	}
	
	
	HeapDestroy(_scheduler->m_heap);
	free(_scheduler);	
	LogRegister(DEB,"scheduler destroyed successfully",__FILE__,__func__)	;
}
/*
	check if all tasks finished 
	free heap if finished
*/

/*multiply the time by -1*/	
static void NegetiveTime(Timespec* _time)
{
	_time->tv_nsec*=-1;
	_time->tv_sec*=-1;
}

/**/
static void TaskNewTimeToRun(Task* _task,Timespec * _computerTime)
{
		_task->m_nextTimeToRun.tv_nsec = (_computerTime->tv_nsec + _task->m_interval.tv_nsec) % ONE_SEC_IN_NANO;
		_task->m_nextTimeToRun.tv_sec = (_computerTime->tv_sec + _task->m_interval.tv_sec ) + (_computerTime->tv_nsec + _task->m_interval.tv_nsec) /ONE_SEC_IN_NANO;
}

/*creates new task accords to paramaters calculate her priority and insret to the priority structure*/
/*build the Task with the parameters calculates is priority = current time + interval of task */
/*insert the the task to heap accords to his priority*/
ADTErr TaskInsert(Scheduler* _scheduler,DF _func,Data* _data, Timespec* _interval)
{
	ADTErr status;
	Task* task;
	Timespec computerTime ;
	
	assert(_scheduler);
	assert(_func);
	assert(_data);

	if(!(task=(Task*)malloc(sizeof(Task))))
	{
		LogRegister(ERR,"Task allocated failed",__FILE__,__func__)	;
		return ERR_ALLOC_FAILED;
	}			

	/*initilizing parameters*/
	task->m_interval = *_interval;
	task->m_data=_data;
	task->m_func=_func;
	
	/*return computer clock*/
	if ( clock_gettime( CLOCK_REALTIME, &computerTime) == -1 )
	{	
		LogRegister(ERR,"failed to return computer time",__FILE__,__func__)	;
		free(task);	
		return ERR_GENERAL;
	}

	/*calculate new time to run + computer current time *-1 insert to heap*/
	TaskNewTimeToRun(task, &computerTime);
	
	NegetiveTime(&task->m_nextTimeToRun);
	
	if ((status=HeapInsert(_scheduler->m_heap,task)))
	{
		free(task);	
		return status;
	}
	LogRegister(DEB,"Task inserted successfuly",__FILE__,__func__)	;
	
	return	status;	
}

/*the scheduler manage the priority structre and activate task to run mode */
/*the scheduler insert to heap new tasks accords to priority*/
/*when function finishes(not task ) check her status if task havent finished insert to heap with new priority (current time)*/
/*extract the minimum from heap id the current time isnt the modulue of the interval does wait for the difference*/
/*wait = interval - (currentTime % interval) */
ADTErr SchedulerRun(Scheduler* _scheduler)
{
	Timespec computerTime;
	ADTErr status;
	Task* maxTask;


	_scheduler->m_isPaused=0; 
	/*heap new compare -1*/
	if( !_scheduler->m_isPaused )
	{
		/*heap not empty*/	
		while(HeapSize(_scheduler->m_heap))
		{
			
			/*extract max task convert to positive*/
			maxTask = (Task*)HeapExtract(_scheduler->m_heap);		
			NegetiveTime(&maxTask->m_nextTimeToRun);
			
			/* if computer time smaller wait keep looping  */
			do
			{
				if ( clock_gettime( CLOCK_REALTIME, &computerTime) == -1 )
				{		
					LogRegister(ERR,"failed to return computer time",__FILE__,__func__)	;
					return ERR_GENERAL;
				}
			}	
			while( compareTime( &maxTask->m_nextTimeToRun  ,&computerTime)) ;
			

			/*function have not finished return 0*/
			if (! maxTask->m_func(maxTask->m_data))
			{
				TaskNewTimeToRun(maxTask, &computerTime);
				
				NegetiveTime(&maxTask->m_nextTimeToRun);
				
				/*insert with new times to heap*/
				if ((status=HeapInsert(_scheduler->m_heap,maxTask)))
				{
					return status;
				}
			}		
			
		}
		
		LogRegister(DEB,"Heap is empty no more tasks",__FILE__,__func__)	;
		return ERR_OK;

	}

	return ERR_OK;


}


/*pause scheduler*/
size_t SchedulerPause(Scheduler* _scheduler)
{
	return HeapSize(_scheduler->m_heap);
}

