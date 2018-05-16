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

/*   Server   */
int main()
{
	
	int sock =socket(AF_INET,SOCK_DGRAM,0);
	
	char msg[20];

	struct sockaddr_in mySocketAddr;
 
	struct socklen_t fromlen;

	memset(&mySocketAddr, 0, sizeof (mySocketAddr));
	
  	if (bind(sockfd, (struct sockaddr*)&mySocketAddr, sizeof(mySocketAddr)) == -1) 
	{
            close(sockfd);
	}


	remoteSocketAddr.sin_family=AF_INET ;
	remoteSocketAddr.sin_port=htons(SERVER_PORT);
	remoteSocketAddr.sin_addr.s_addr=inet_addr(SERVER_IP);

	
  	if (bind(sockfd, (struct sockaddr*)mySocketAddr, sizeof(remoteSocketAddr)) == -1) 
	{

	}

	recvfrom(sock,msg,sizeof(msg),0,(struct sockaddr*)&remoteSocketAddr,&fromlen);
	puts(msg);

	return 0;
}
