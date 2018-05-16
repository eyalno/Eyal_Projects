/*
 ** selectserver.c -- a cheezy multiperson chat server
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <list>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <threadpool.hpp>
#include <boost/bind.hpp> //not sure of that

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>



using namespace std;
using namespace boost::threadpool;
using namespace xercesc_3_1;


#define PORT "9034"   // port we're listening on


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) 
	{
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main(void)
{
	fd_set master;    // master file descriptor list
	fd_set read_fds;  // temp file descriptor list for select()
	int fdmax;        // maximum file descriptor number

	int listener;     // listening socket descriptor
	int newfd;        // newly accept()ed socket descriptor
	struct sockaddr_storage remoteaddr; // client address
	socklen_t addrlen;

	char buf[256];    // buffer for client data
	int nbytes;

	char remoteIP[INET6_ADDRSTRLEN];

	int yes=1;        // for setsockopt() SO_REUSEADDR, below
	int i, j, rv;

	struct addrinfo hints, *ai, *p;

	//******************
	struct DataRecv
	{
		DataRecv(int _fd):m_fdCx(_fd),m_closedCx(false){}

		bool m_closedCx;
		list<string> m_dataList;
		int m_fdCx;
	};

	map<int,DataRecv & > recvDataMap;
	queue<DataRecv &> fifoCx;

	const int g_maxClients=1000;
	int g_incFileNum=1;

	//******************

	FD_ZERO(&master);    // clear the master and temp sets
	FD_ZERO(&read_fds);

	// get us a socket and bind it
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0)
	{
		fprintf(stderr, "selectserver: %s\n", gai_strerror(rv));
		exit(1);
	}

	for(p = ai; p != NULL; p = p->ai_next) 
	{
		listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (listener < 0)
		{ 
			continue;
		}

		// lose the pesky "address already in use" error message
		setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

		if (bind(listener, p->ai_addr, p->ai_addrlen) < 0)
		{
			close(listener);
			continue;
		}

		break;
	}

	// if we got here, it means we didn't get bound
	if (p == NULL) 
	{
		fprintf(stderr, "selectserver: failed to bind\n");
		exit(2);
	}

	freeaddrinfo(ai); // all done with this

	// listen
	if (listen(listener, 10) == -1) 
	{
		perror("listen");
		exit(3);
	}

	// add the listener to the master set
	FD_SET(listener, &master);

	// keep track of the biggest file descriptor
	fdmax = listener; // so far, it's this one

	// main loop
	for(;;) 
	{
		read_fds = master; // copy it
		//to add time wait 4 select sleep 1 sec so the for loop 
		if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) 
		{
			perror("select");
			exit(4);
		}

		// run through the existing connections looking for data to read
		for(i = 0; i <= fdmax; i++) 
		{
			if (FD_ISSET(i, &read_fds))
			{ // we got one!!
				if (i == listener)
				{
					// handle new connections
					addrlen = sizeof remoteaddr;
					newfd = accept(listener,(struct sockaddr *)&remoteaddr,&addrlen);


					if (newfd == -1)
					{
						perror("accept");
					} 
					else
					{
						DataRecv & newData=new DataRecv(newfd); //check if its working
						fifoCx.push(newData);


						FD_SET(newfd, &master); // add to master set
						if (newfd > fdmax) 
						{    // keep track of the max
							fdmax = newfd;
						}
						printf("selectserver: new connection from %s on " "socket %d\n", inet_ntop(remoteaddr.ss_family, get_in_addr((struct sockaddr*)&remoteaddr), remoteIP, INET6_ADDRSTRLEN), newfd);

					}
				} 
				else
				{
					// handle data from a client
					if ((nbytes = recv(i, buf, sizeof buf, 0)) <= 0)
					{
						// got error or connection closed by client
						if (nbytes == 0) 
						{
							recvDataMap[i].m_closedCx=true;

							//reset bit after thread finished
							// connection closed
							printf("selectserver: socket %d hung up\n", i);

						}
						else 
						{
							perror("recv");
						}
						close(i); // bye!
						FD_CLR(i, &master); // remove from master set
					} 
					//data recevied
					else
					{

						//mb i should /n and then remove
						recvDataMap[i].m_dataList.push_back()=buf;


						/*
						// we got some data from a client
						for(j = 0; j <= fdmax; j++) {
						// send to everyone!
						if (FD_ISSET(j, &master)) {
						// except the listener and ourselves
						if (j != listener && j != i) {
						if (send(j, buf, nbytes, 0) == -1) {
						perror("send");
						}
						}
						}
						}
						}
						*/
				} // END handle data from client
			} // END got new incoming connection
		} // END looping through file descriptors


		if (fifoCx.front().m_closedCx == true)
		{
			string fileName="file";
			stringstream oss;
			oss << g_incFileNum<<.xml;

			fileName += oss.str();

			ofstream myfile (fileName);
			if (myfile.is_open())
			{
				list<string> & mylist = fifoCx.front().m_dataList;					
				while (!mylist.empty())
				{
					
					myfile << mylist.front(); //ofsream dont thro exception
					mylist.pop_front();
				}
				
				tp.schedule(boost::bind(task_with_parameter, 4));  
				pool tp(2); // tp is handle to the pool should be allocated on top
				tp.size_controller().resize(2);//dont know if autoresize 
				schedule(tp, prio_task_func(10,&task_2)); //highest is moe prioritize dont if can put 2 in same priority
				scoped_pool<prio_pool, 0> tp;
				//add the 5 sec if
				//prioritize from poolk 2 using boost ::
				//how does namespace wor
				//if more than 3 change priority but
				//what does fifo means removed
				//anti starvation 3:1
				//what is that g++ -o access -g access.cpp -I xxx/include -lxerces-c

				thread recev fd data file
				clear fd queue and container

					 	
					myfile.close();
			}
			else cout << "Unable to open file";

		 
				
					

		}

	} // END for(;;)--and you thought it would never end!

	return 0;
}
