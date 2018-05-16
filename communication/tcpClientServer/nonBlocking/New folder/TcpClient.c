#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>


#include "ServerClient.h"

/*client*/
int main(void)
{
	int clientSocket[NUMBER_OF_CLIENTS ] = { 0};
	struct sockaddr_in serverAddr = {0};

	int j =0;
	
	char recMsg[BUFF_SIZE] = "";
	char sendMsg[BUFF_SIZE] = "";
	size_t numOfBytes = 0;

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERVER_PORT);
	serverAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);


	for(j = 0 ; j < NUMBER_OF_CLIENTS; ++j)
	{

		if(-1 == (clientSocket[j] = socket(AF_INET, SOCK_STREAM, 0)))
		{
			HANDLE_ERROR;
		}

		if(-1 == connect(clientSocket[j], (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
		{
			HANDLE_ERROR;
		}
	}	
	
	for(j = 0 ; j < NUMBER_OF_CLIENTS ; ++j)
	{
	
		sprintf(sendMsg, "%d send Hello", j);
		if(strlen(sendMsg) != write(clientSocket[j], sendMsg, strlen(sendMsg)))
		{
			HANDLE_ERROR;
		}

		if(-1 == (numOfBytes = read(clientSocket[j], recMsg, BUFF_SIZE)))
		{
			HANDLE_ERROR;
		}
	
		recMsg[numOfBytes] = '\0';

		puts(recMsg);
		
		close(clientSocket[j]);
	}	
		return 0;
}
