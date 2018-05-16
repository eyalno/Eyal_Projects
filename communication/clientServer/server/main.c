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



#define SERVER_IP "192.168.1.37"
#define SERVER_PORT 5060
/*   Server   */
int main()
{
	
	int sock =socket(AF_INET,SOCK_DGRAM,0);
	
	char msg[20];

	struct sockaddr_in mySocketAddr;
 
	socklen_t fromlen;

	memset(&mySocketAddr, 0, sizeof (mySocketAddr));
	
	mySocketAddr.sin_family=AF_INET ;
	mySocketAddr.sin_port=htons(SERVER_PORT);
	mySocketAddr.sin_addr.s_addr=inet_addr(SERVER_IP);

  	if (bind(sock, (struct sockaddr*)&mySocketAddr, sizeof(mySocketAddr)) == -1) 
	{
            close(sock);
	}



	
  	if (bind(sock, (struct sockaddr*)&mySocketAddr, sizeof(mySocketAddr)) == -1) 
	{

	}

	recvfrom(sock,msg,sizeof(msg),0,(struct sockaddr*)&mySocketAddr,&fromlen);
	puts(msg);

	return 0;
}
