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
	int minPort=1;
	int maxPort=100;
	int i=0;
	struct servent *service;

	if ( argc < 3 )
	{
		printf("Please provide a port ramge. eg ./knownports 45 160 \n");
		printf("Running in default range 1-100\n");
		printf("Please provide a port range if need other values\n");
		printf("./knownports 45 160\n");
	}
	else
	{
		minPort=atoi(argv[1]);
		maxPort=atoi(argv[2]);
	}
    	for(i=minPort; i<=maxPort; i++) {
		service = getservbyport(htons(i), "tcp");
		if (service != NULL)
			printf("\t%d\t%s\n", i , service->s_name);
		//printf("\t%d\t%s\n", i , (service == NULL) ? "UNKNOWN" : service->s_name);
    	}
    	exit(0);
}
