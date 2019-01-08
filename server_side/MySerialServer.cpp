//
// Created by ori on 1/8/19.
//

#include "MySerialServer.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include <thread>

int start(int port){
    int sockfd, newsockfd, portno, clilen;
    portno = port;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    return sockfd;
}
void clientHandeling(int port,ClientHandler* clientHandler){
    ////////////////////////////SET TIMEOUT!!!!!!!!!!!
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    while(true){
        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        clientHandler->handleClient(port);
    }
}
void server_side::MySerialServer::open(int port,ClientHandler* c) {
   sock_id = start(port);
   std::thread s(clientHandeling,port,c);
   s.detach();
}

void server_side::MySerialServer::stop() {
    close(sock_id);
}

int main( int argc, char *argv[] ) {

    return 0;
}
