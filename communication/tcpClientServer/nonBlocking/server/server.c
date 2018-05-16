

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>





#include "ServerClient.h"

void handler(int _sig);
static int flag = 1;

int main(void)
{
	int serverSocket = 0;
	struct sockaddr_in serverAddr = {0};	
	int clientSockets[NUMBER_OF_CLIENTS] = {0};
	struct sockaddr_in clientAddr = {0};
	socklen_t clientAddrLen = 0;
	int optval = 0;
	char recMsg[BUFF_SIZE] = "";
	char sendMsg[BUFF_SIZE] = "";
	int i = 0;


	int clientNum = 0;
	int socketNum = 0;
	
	struct timespec delay = {0, 100};
	
	size_t numOfBytes = 0;
	
	
	int flags;	

	/*sigaction*/
	struct sigaction sig;
	
	sig.sa_handler = handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags =  0;
	
	sigaction(SIGINT, &sig, (struct sigaction *)NULL);

	/*open socket*/
	if(-1 == (serverSocket = socket(AF_INET, SOCK_STREAM, 0)))
	{
		HANDLE_ERROR;
	}

	if(-1 == setsockopt(serverSocket, SOL_SOCKET ,SO_REUSEADDR, &optval , (socklen_t)sizeof(optval)))
	{
		HANDLE_ERROR;	
	}

	/*set serverSocket to be Non-Blocking*/
	flags =fcntl(serverSocket,F_GETFL,0);
	fcntl(serverSocket,F_SETFL,flags | O_NONBLOCK);

	memset(&serverAddr, 0 , sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERVER_PORT);
	serverAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);

	/*bind*/
	if(-1 == bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
	{
		HANDLE_ERROR;
	}

	/*listen*/
	if(-1 == listen(serverSocket, NUMBER_OF_CLIENTS))
	{
		HANDLE_ERROR;
	}


	
	/*comm with clients*/
	while(flag)
	{
		memset(&clientAddr, 0 , sizeof(clientAddr));

		/*conncet to cilent*/
			
		clientAddrLen = sizeof(clientAddr);
		if(-1 == (clientSockets[socketNum] = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen)) && EAGAIN !=errno)
		{
		    if(EINTR == errno && !flag)
	    	{	
				close(serverSocket);
				return errno;
			}

			HANDLE_ERROR;
		}		
		else if(EAGAIN !=errno)
		{
			++socketNum;
			
			/* Non-Blocking*/
			flags =fcntl(clientSockets[socketNum],F_GETFL,0);
			fcntl(clientSockets[socketNum],F_SETFL,flags | O_NONBLOCK);

		}
		
		for(i = 0 ;i < socketNum; ++i)
		{
						
			if(clientSockets[i])
			{
				if(-1 == (numOfBytes = recv(clientSockets[i], recMsg, BUFF_SIZE, 0)) && EAGAIN !=errno)
				{
					if(EINTR == errno && !flag)
					{
						close(serverSocket);
						return errno;
					}
					HANDLE_ERROR;
				}
		
				if(0 == numOfBytes)
				{
					close(i); 
            	    clientSockets[i] = 0;
				}
				
				else
				{
						
					nanosleep(&delay,NULL);
							
					recMsg[numOfBytes] = '\0';

					puts(recMsg);

					/*Send answer*/
			
					sscanf(recMsg,"%d", &clientNum);
				
					sprintf(sendMsg, "recieved hello from %d ",clientNum);

					if(strlen(sendMsg) != send(clientSockets[i], sendMsg, strlen(sendMsg), 0))
					{
						if(EINTR == errno && !flag)
						{
							close(serverSocket);
							return errno;
					
						}
						HANDLE_ERROR;
					}
			
				}
			
				
			}
		}
	}
	close(serverSocket);

		
	return 0;
}

void handler(int _sig)
{
	flag = 0;
}

