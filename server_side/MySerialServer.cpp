//
// Created by ori on 1/8/19.
//

#include "MySerialServer.h"
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>
#include <thread>

void clientHandeling(int port,ClientHandler* clientHandler){
    ////////////////////////////SET TIMEOUT!!!!!!!!!!!
    clientHandler->handleClient(port);
}
void server_side::MySerialServer::open(int port,ClientHandler* c) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        std::cerr << "Bad!" << std::endl;
    }

    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    while (true){
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        new_sock = accept(s, (struct sockaddr*)&client, &clilen);
        if (new_sock < 0)	{
            if (errno == EWOULDBLOCK)	{
                std::cout << "timeout!" << std::endl;
                exit(2);
            }	else	{
                perror("other error");
                exit(3);
            }
        }
        std::thread server(clientHandeling,port,c);
        server.detach();
        currentThread = &server;
        sock_id = new_sock;

    }

}

void server_side::MySerialServer::stop() {
    close(sock_id);
    if(currentThread!= nullptr)
        currentThread->join();
}

int main( int argc, char *argv[] ) {

    return 0;
}



