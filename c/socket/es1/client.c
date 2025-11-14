#include <stdio.h>      // std in-out
#include <stdlib.h>     // per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> // funz. accept+bind+listen
#include <sys/types.h>  // funz. accept
#include <netinet/in.h> // definiscono la struttura degli indirizzi
#include <string.h>     // funz. stringhe
#include <errno.h>      // gestioni errori connessione
#include <ctype.h>      // bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX


#define SERVER_PORT 1500


int main(int argc, char *argv[]) {
    struct sockaddr_in destination;

    // Define the destination
    destination.sin_family = AF_INET;
    destination.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    destination.sin_port = htons(SERVER_PORT);
    
    char stringa[20] = "";
    int socketfd;

    // Enter the main loop
    // Every cycle: 
    // - create a socket
    // - establish a connection with the server
    // - send the message
    // - close the socket
    // NB: if the user insert a "q" this program finishes
    while (1) {
        // Create the socket
        socketfd = socket(AF_INET, SOCK_STREAM, 0);
        
        // Create a connection with the destination
        connect(socketfd, (struct sockaddr*)&destination, sizeof(destination));

        printf("\nInserisci stringa: ");
        scanf("%s", stringa);

        if (strcmp(stringa, "q") == 0) {
            printf("Closing the client\n");
            close(socketfd);
            break;
        }

        write(socketfd, stringa, sizeof(stringa));
        read(socketfd, stringa, sizeof(stringa));

        printf("Server response: %s", stringa);

        close(socketfd);
    }

    printf("\n\n");
    return 0;
}
