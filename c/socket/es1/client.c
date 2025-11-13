#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     //file header che consente l'accesso alle API dello standard POSIX


#define Serverport 1450


int main() {
    struct sockaddr_in servizio;
    
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl("192.168.60.162"); // Converte l'indirizzo in bit
    servizio.sin_port = htons(Serverport);
    
    char stringa[20];
    int socketfd;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));
    
    printf("Inserisci la stringa\n");
    scanf("%s", stringa);
    
    write(socketfd, stringa, sizeof(stringa));
    close(socketfd);
}
