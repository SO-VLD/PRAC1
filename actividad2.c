/*
* Filename: actividad2.c
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
 #include <unistd.h>
#include <netinet/in.h>
#define TAMANO_BUFFER 512

void err_sys(char *mess) { perror(mess); exit(1); }

int main (int argc, char *argv[]) {

struct sockaddr_in echoserver;
char buffer[TAMANO_BUFFER];
unsigned int echolen;
int sock, result;
int received = 0;

/* Check input arguments */
if (argc != 4) {
fprintf(stderr, "Usage: %s <aaa.bbb.ccc.ddd> \n", argv[0]);
exit(1);
}

/* Try to create TCP socket */
sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
if (sock < 0) {
err_sys("Error de socket");
}

/* Set information for sockaddr_in */
memset(&echoserver, 0, sizeof(echoserver)); 	/* reset memory */
echoserver.sin_family = AF_INET; 			/* Internet/IP */
echoserver.sin_addr.s_addr = inet_addr(argv[1]); 	/* IP address */
echoserver.sin_port = htons(17); 			/* server port */


/* Convert IPv4 and IPv6 addresses from text to binary form*/
    	if(inet_pton(AF_INET, argv[1], & echoserver.sin_addr.s_addr)<=0) 
   	{
        printf("\Direccion no correcta \n");
        return -1;



/* Try to have a connection with the server */
result = connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver));
if (result < 0) {
err_sys("Error de conexion con el servidor");
}

/* Just wait */
while (1);

/* Close socket */
close(sock);

exit(0);
}
