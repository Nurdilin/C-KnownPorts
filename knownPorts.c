#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int maxPort=0;
	int i=0;
	struct servent *service;
	maxPort=atoi(argv[1]);
    	for(i=1; i<=maxPort; i++) {
		service = getservbyport(htons(i), "tcp");
		if (service != NULL)
			printf("\t%d\t%s\n", i , service->s_name);
		//printf("\t%d\t%s\n", i , (service == NULL) ? "UNKNOWN" : service->s_name);
    	}
    	exit(0);
}
