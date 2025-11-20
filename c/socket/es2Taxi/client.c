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

/*
Il codice del server lo fa martino
*/

#define SERVER_PORT 6967

int main() {
    struct sockaddr_in destination;

    destination.sin_family = AF_INET;
    destination.sin_port = htons(SERVER_PORT);

    inet_pton(AF_INET, "127.0.0.1", &destination.sin_addr);

    
    int socketfd;
    char message[20];
    char serverMessage[20];

    for (;;) {
        socketfd = socket(AF_INET, SOCK_STREAM, 0);

        if (socketfd < 0) {
            printf("[ERROR] - Error to open the socket");
            break;
        }

        int connection = connect(socketfd, (struct sockaddr*)&destination, sizeof(destination));

        if (connection < 0) {
            perror("[ERROR] - connection");
            break;
        }

        printf("Inserisci il codice della citta' di partenza: ");
        fgets(message, sizeof(message), stdin);
        printf("Message: %s", message);

        write(socketfd, message, strlen(message));
        read(socketfd, serverMessage, sizeof(serverMessage));

        printf("Server message: %s\n", serverMessage);

        close(socketfd);
    }

    printf("\n\n");
    return 0;    
}
