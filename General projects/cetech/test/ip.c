/*
 * sample of using getsockname
 *
 * this prints out the local port and IP address as well as the remote
 * port and IP address. 
 *
 * Tested under FreeBSD.
 *
 * Steve Shah (sshah@planetoid.org)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>



int main(int argc, char *argv[])
{
    int fdc;
    struct sockaddr_in  sa;
    socklen_t sin_len;


    fdc = socket(PF_INET, SOCK_STREAM, 0);
    sin_len = sizeof(struct sockaddr);

	getsockname(fdc,(struct sockaddr *) &sa, &sin_len);

 	printf("Local IP address is: %s\n", inet_ntoa(sa.sin_addr));


    close (fdc);

    return 0;
}



