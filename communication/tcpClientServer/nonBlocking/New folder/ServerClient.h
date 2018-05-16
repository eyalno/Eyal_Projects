#pragma once

#define IP_ADDRESS /* "10.0.0.5" */" 192.168.1.140"
#define SERVER_PORT 6017	

#define HANDLE_ERROR fprintf(stderr,"%s %s:%d\n",strerror(errno) ,__FILE__, __LINE__); \
					 return -1

#define BUFF_SIZE 256
#define FAIL -1

#define NUMBER_OF_CLIENTS 10
