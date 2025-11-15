#include <stdio.h>      // std in-out
#include <stdlib.h>     // per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> // funz. accept+bind+listen
#include <sys/types.h>  // funz. accept
#include <netinet/in.h> // definiscono la struttura degli indirizzi
#include <string.h>     // funz. stringhe
#include <errno.h>      // gestioni errori connessione
#include <ctype.h>      // bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#include <arpa/inet.h>

#define SERVER_PORT 6967

int main() {
    struct sockaddr_in destination;

    destination.sin_family = AF_INET;
    destination.sin_port = htons(SERVER_PORT);

    inet_pton(AF_INET, "127.0.0.1", );

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(socketfd, (struct sockaddr*)&destination, sizeof(destination));

    write(socketfd, "WOW\0", 4);

    char message[20];
    
    
}
