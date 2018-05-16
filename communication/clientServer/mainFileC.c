/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
		Text Editor: 	gVim
***********************************************************************/
/* standard libaries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

/* 20 */
#define SERVER_IP "192.168.1.37"
#define SERVER_PORT 5060

int main()
{
	
	int sock =socket(AF_INET,SOCK_DGRAM,0);
	
	char msg[]="Hello server";

	struct sockaddr_in remoteSocketAddr;

	memset(&remoteSocketAddr, 0, sizeof (remoteSocketAddr));
	
	remoteSocketAddr.sin_family=AF_INET ;
	remoteSocketAddr.sin_port=htons(SERVER_PORT);
	remoteSocketAddr.sin_addr.s_addr=inet_addr(SERVER_IP);

	if(sendto(sock,msg,sizeof(msg),0,(struct sockaddr*)&remoteSocketAddr,sizeof(remoteSocketAddr)))
	{

	}
	
	return 0;
}
