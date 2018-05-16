#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>

#include <sys/msg.h>

#include <fcntl.h>
#include <sys/stat.h>

#define FILE_NAME "eyal"
#define FAIL -1
#define PRIVLIGES 0644
#define SHM_SIZE 1024
#define SEMA_NUM 2

#define LOCK -1
#define FREE 1

void LockSemaphore(int id, int i)
{
	struct sembuf sb;
	sb.sem_num = i;
	sb.sem_op = LOCK;
	sb.sem_flg = 0;
	semop(id, &sb, 1);
}

void UnlockSemaphore(int id, int i)
{
	struct sembuf sb;
	sb.sem_num = i;
	sb.sem_op = FREE;
	sb.sem_flg = 0;
	semop(id, &sb, 1);
}

union semun
{
	int val; /* value for SETVAL*/
	struct semid_ds* buf; /* buffer for IPC_STAT, IPC_SET */
	unsigned short* array; /* array for GETALL, SETALL*/
	struct seminfo* __buf; /* buffer for IPC_INFO */
};

enum { SEM_USER_1, SEM_USER_2 } USERS;

/*ping user1 if*/
int main(int argc,char* argv[])
{
	int semid;
	int shmid;
	int key;
	int err;
	char* buf;
	unsigned short initialArr[SEMA_NUM]; 
	int mySem = SEM_USER_1 ;
	int yourSem = SEM_USER_2;

	union semun arg;
	pid_t pid;

	pid=getpid();

	if ((key = ftok(FILE_NAME, 'B')) == FAIL)
	{  
		err=errno;
		perror("ftok");
		return err;
	}

	if ((shmid = shmget(key, SHM_SIZE, PRIVLIGES | IPC_CREAT)) == FAIL)
	{
		err=errno;
		perror("shmget");
		return err;
	}

	buf= (char*)shmat(shmid,NULL,0);

	initialArr[SEM_USER_1]=0;
	initialArr[SEM_USER_2]=0;

	arg.array = initialArr;
	semctl(SEMA_NUM, 0, SETALL, arg);

	if ((semid = semget(key, SEMA_NUM, IPC_CREAT | PRIVLIGES)) == FAIL) 
	{
		err=errno;
		perror("semget");
		return err;
	}
	/*save sema id*/
	sprintf(buf,"pid: %d hello im pong ",pid);	
	
	UnlockSemaphore(semid,yourSem);
	
	for (;;)
	{
		sleep(1);
		LockSemaphore(semid, mySem);
		
		
		printf("Reply: %s \n", buf);
		
		sprintf(buf,"pid: %d hello im pong ",pid);	
		
		
		UnlockSemaphore(semid, yourSem);
		
	}

return 0;
}
