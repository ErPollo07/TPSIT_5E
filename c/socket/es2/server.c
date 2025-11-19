// Lo fa martino
#include <stdio.h>      // std in-out
#include <stdlib.h>     // per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> // funz. accept+bind+listen
#include <sys/types.h>  // funz. accept
#include <netinet/in.h> // definiscono la struttura degli indirizzi
#include <string.h>     // funz. stringhe
#include <errno.h>      // gestioni errori connessione
#include <ctype.h>      // bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX


#define SERVER_PORT 6967


int main(int argc, char *argv[]) {
    struct sockaddr_in destination;

    destination.sin_family = AF_INET;
    destination.sin_addr.s_addr = htonl(INADDR_ANY);
    destination.sin_port = htons(SERVER_PORT);

    int socketfd, soa, destlen = sizeof(destination);  
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr*)&destination, sizeof(destination)); // Serve per permettere che la socket sia raggiungibile dal client
    listen(socketfd, 10);

    char message[20] = "";
    char msg_received[17] = "MESSAGE RECEIVED\0";
    
    while (1) {
        printf("Server in ascolto ...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr*)&destination, &destlen);
        
        read(soa, message, sizeof(message));
        write(soa, msg_received, sizeof(msg_received));

        printf("Message received: %s\n", message);
        close(soa);
    }

    close(socketfd);

    printf("\n\n");
    return 0;
}
