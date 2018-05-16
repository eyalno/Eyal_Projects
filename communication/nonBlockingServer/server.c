/*
** server.c -- a stream socket server demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/time.h>

#define PORT "3490"  // the port users will be connecting to
#define MAXDATASIZE 10
#define BACKLOG 10     // how many pending connections queue will hold
#define MAX_MSG 30


void sigchld_handler(int s)
{
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) 
	{
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


// the function initilize variable hints of structure addrinfo parameters  to the desired internet host and service 
// the variable act as a filter for the avilable structure addrinfo.
// the function builds a Linked List(serverinfo) of structure addrinfo  which holds internet addresses  according to the filter
int build_ip_Linked_List_alloc(struct addrinfo *hints,struct addrinfo **servinfo)
{
	int rv;

	memset(hints, 0, sizeof( struct addrinfo));
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = SOCK_STREAM;
	hints->ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo(NULL, PORT, hints, servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 0;
	}

	return 1;
}
//the function create socket file descriptor and bind it to the first avilable internet address from the Linked List serverinfo
//after the binding the function set the socket to listen mode for incoming connection
int wait_for_clients(struct addrinfo *servinfo,int *sockfd)
{
	struct sigaction sa; 
	struct addrinfo *p;
	int yes=1;

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) 
	{
		if ((*sockfd = socket(p->ai_family, p->ai_socktype,p->ai_protocol)) == -1) 
		{
			perror("server: socket");
			continue;
		}

		if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,sizeof(int)) == -1) 
		{
			perror("setsockopt");
			exit(1);
		}



		if (bind(*sockfd, p->ai_addr, p->ai_addrlen) == -1) 
		{
			close(*sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	if (p == NULL)  
	{
		fprintf(stderr, "server: failed to bind\n");
		return 0;
	}


	if (listen(*sockfd, BACKLOG) == -1)
	{
		perror("listen");
		exit(1);
	}

	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	if (sigaction(SIGCHLD, &sa, NULL) == -1) 
	{
		perror("sigaction");
		exit(1);
	}

	printf("server: waiting for connections...\n");

	return 1;
}

void communicate_Client_Server(int new_fd)
{
	char string [256];
	char buf[MAXDATASIZE];
	unsigned int  numbytes=0;
	char * command;
	char * temp_Command=NULL;
	int command_Num_Bytes;
	int i=0;
	int counter_Words=0;
	char **  argv;
	char * pch;
	char menu;
	int stdout_Copy;
	


	printf("Press enter to recieve command from client` or other key to exit\n");
	while( (menu=getchar()) == '\n' )
	{
		command_Num_Bytes=0;
		counter_Words=0;
		command=NULL;

		//receive dynamicly the command
		do
		{
			numbytes = recv(new_fd, buf, MAXDATASIZE, 0);

			if (numbytes == -1)
			{
				perror("recv");
				exit(1);
			}

			temp_Command = (char*)realloc(command,command_Num_Bytes + numbytes);

			if (temp_Command!=NULL) 
				command=temp_Command;

			else 
			{
				free (command);
				puts ("Error (re)allocating memory");
				exit (1);
			}

			command[command_Num_Bytes]=NULL;

			//concentratethe recv
			strncat(command, buf, numbytes);

			//counting command length
			command_Num_Bytes += numbytes;

		}
		while (numbytes  == MAXDATASIZE );

		printf("The command is: %s\n",command);

		// counts space / words
		for(i=0; i< command_Num_Bytes; i++)
			if (command[i] == ' ' )
				counter_Words++;
		counter_Words++;

		//creats array of strings 
		argv=(char **)malloc(sizeof(char*) * (counter_Words+1));
		i=0;

		//gets the command tokens
		pch = strtok (command," ");
		while (pch != NULL)
		{
			//copy the token 
			strcpy( argv[i++] = (char*)malloc(sizeof(pch)) , pch );

			pch = strtok (NULL, " ");
		}
		//add last argument NULL
		argv[i] =NULL;

		//redirecting   stdout to  the new connection
		stdout_Copy=dup(STDOUT_FILENO);
		

		dup2( new_fd, STDOUT_FILENO ); 
		dup2( new_fd, STDERR_FILENO ); 
		
		
		//execute the command to the socket
		if (!fork())
		{
			
			execvp(argv[0], argv);
			exit(0);	
		}
		//free allocated memory
		free(command);
		for (;i>0;free(argv[--i]));
		free(argv);

		//redirecting   stdout to out put
		dup2( stdout_Copy, STDOUT_FILENO ); 
		

		printf("Press enter to recieve command from client` or other key to exit\n");
	}
	
	close( new_fd );
	exit(0);
}

//the function is the core of the server accepting each incoming connection and fork each connection to a process.
void accept_connections_and_communication(int sockfd)
{
	socklen_t sin_size;
	int new_fd;  // listen on sock_fd, new connection on new_fd
	struct sockaddr_storage their_addr; // connector's address information
	char s[INET6_ADDRSTRLEN];
	int fdmax;
	fd_set read_flags,write_flags,master; // the flag sets to be used
	struct timeval waitd;          // the max wait time for an event
	int stat;                      // holds return value for select();
	int i,j;	
  	fcntl(sockfd,F_SETFL O_NONBLOCK);

	waitd.tv_sec = 1;  // Make select wait up to 1 second for data
	waitd.tv_usec = 0; // and 0 milliseconds.

 	FD_ZERO(&read_flags); // Zero the flags ready for using
	FD_ZERO(&write_flags);
	
	// add the listener to the master set
	FD_SET(sockfd, &master);

	// keep track of the biggest file descriptor
	fdmax =sockfd ; // so far, it's this one 

	sin_size = sizeof their_addr;
	
	// main accept() loop
	while(1) 
	{   
		read_fds = master; // copy it
		
		if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
			perror("select");
			exit(4);
		}
		
		// run through the existing connections looking for data to read
		for(i = 0; i <= fdmax; i++) {
			if (FD_ISSET(i, &read_fds)) { // we got one!!
				if (i == listener) {
					// handle new connections
					// deleted addrlen = sizeof remoteaddr;	
					new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
					if (newfd == -1) {
						perror("accept");
						continue;
					} else {
						FD_SET(newfd, &master); // add to master set
						if (newfd > fdmax) { // keep track of the max
							fdmax = newfd;
						}
						inet_ntop(their_addr.ss_family,get_in_addr((struct sockaddr *)&their_addr),s, sizeof s);
						printf("server: got connection from %s\n", s);
					} else {
					    // handle data from a client
					    if ((nbytes = recv(i, buf, sizeof buf, 0)) <= 0) {
					 	 // got error or connection closed by client
						 if (nbytes == 0) {
						// connection closed

		



		communicate_Client_Server(new_fd);

		if (!fork())  // this is the child process
		{ 
			close(sockfd); // child doesn't need the listener

			close(new_fd);
			exit(0);
		}

		close(new_fd);  // parent doesn't need this
	}
}
//the fucntion implement the client - server send,recevie messages


// free struct addrinfo *servinfo
void build_ip_linked_list_free(struct addrinfo *servinfo)
{
	freeaddrinfo(servinfo); // all done with this structure
}

int main(void)
{

	int sockfd;  // listen on sock_fd, new connection on new_fd
	struct addrinfo hints, *servinfo;


	if (!build_ip_Linked_List_alloc(&hints,&servinfo))
		return 1;

	if (!wait_for_clients(servinfo,&sockfd)) 
		return 2;

	build_ip_linked_list_free(servinfo);


	accept_connections_and_communication(sockfd);

	return 0;
}
