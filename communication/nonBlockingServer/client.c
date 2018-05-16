/*
** client.c -- a stream socket client demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT "3490" // the port client will be connecting to 

#define MAXDATASIZE 20 // max number of bytes we can get at once 
#define MAX_MSG 30



// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

//standard input test of the command argument 
void command_argument_check(int *argc)
{
	if (*argc != 2)
	{
		fprintf(stderr,"usage: client hostname\n");
		exit(1);
	}
}

// the function initilize variable hints of structure addrinfo parameters  to the desired internet host and service 
// the variable act as a filter for the avilable structure addrinfo.
// the function builds a Linked List(serverinfo) of structure addrinfo  which holds internet addresses  according to the filter
// and the address of the required server
int build_ip_Linked_List_alloc(char * argv[],struct addrinfo *hints,struct addrinfo **servinfo)
{
	int rv;

	memset(hints, 0, sizeof( struct addrinfo));
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(argv[1], PORT, hints, servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 0;
	}

	return 1;
}

//the function create socket file descriptor and connect to the first avilable internet address from the Linked List serverinfo
// and using it to connect to the server 
int connect_to_server(struct addrinfo *servinfo,int *sockfd)
{
	char s[INET6_ADDRSTRLEN];
	struct addrinfo *p;

	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next)
	{
		if ((*sockfd = socket(p->ai_family, p->ai_socktype,p->ai_protocol)) == -1)
		{
			perror("client: socket");
			continue;
		}

		if (connect(*sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(*sockfd);
			perror("client: connect");
			continue;
		}
		break;
	}

	if (p == NULL)
	{
		fprintf(stderr, "client: failed to connect\n");
		return 0;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),s, sizeof s);
	printf("client: connecting to %s\n", s);


	return 1;
}


//the fucntion implement the client - server send,recevie messages
void communicaton(int sockfd)
{
	char string [MAXDATASIZE];
	char buf[MAXDATASIZE];
	int  numbytes=0;
	int length;

	char menu;

	printf("Press enter to send command or other key to exit\n");
	while( (menu=getchar()) == '\n' )
	{
		string[0]=NULL;

		printf("Enter command to execute\n");

		//strlen - number of char
		//fgets will get size -1 characters  if in limitations will add newLine 
		while ( (fgets(string,MAXDATASIZE+1,stdin)) && ((length=strlen(string)) == MAXDATASIZE ) && (string[MAXDATASIZE-1] != '\n'))
			if (send(sockfd, string, length, 0) == -1)
				perror("send");

		string[length-1]=NULL;
		if (send(sockfd, string, length, 0) == -1)
			perror("send");

		do
		{
			buf[0]=NULL;
			numbytes = recv(sockfd, buf, MAXDATASIZE, 0);


			if (numbytes == -1)
			{
				perror("recv");
				exit(1);
			}

			buf[numbytes]=NULL;
			printf("%s",buf);	
		}		  
		while (numbytes  == MAXDATASIZE );

		printf("Press enter to send command or other key to exit\n");
	}

}

// free struct addrinfo *servinfo
void build_ip_linked_list_free(struct addrinfo *servinfo)
{
	freeaddrinfo(servinfo); // all done with this structure
}



int main(int argc, char *argv[])
{
	int sockfd;  
	struct addrinfo hints, *servinfo, *p;
	int i;
	int j;
	int *h;
	i = sizeof(int);
	j = sizeof(int*);
	i=sizeof (j);



	command_argument_check(&argc);

	if (!build_ip_Linked_List_alloc(argv,&hints,&servinfo))
		return 1;

	if (!connect_to_server(servinfo,&sockfd)) 
		return 2;

	build_ip_linked_list_free(servinfo);


	communicaton(sockfd);

	close(sockfd);

	return 0;
}




