//
// Created by ori on 1/8/19.
//

#include "MyClientHandler.h"
#include "../Matrix.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>
using std::string;
#include <sys/socket.h>
std::pair<int,int> makePairOutOfCordinates(string line){
    int j=0;
    string val1,val2;
    while (line.at(j)!=',')
        val1+=line.at(j);
    j++;
    while (line.at(j)!='\0')
        val2+=line.at(j);
    return std::make_pair(stoi(val1),stoi(val2));
}
void MyClientHandler::handleClient(int port) {
    int  n;
    string size(256,0),start(256,0),end(256,0);
    n = read( port,&size[0],255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    Matrix mat(stoi(size));
    n = read( port,&start[0],255 );
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    mat.setStart(makePairOutOfCordinates(start));
    n = read( port,&end[0],255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    mat.setEnd(makePairOutOfCordinates(end));
    int i=0;
    while (true){
        string buffer(256,0);
        buffer.resize(256);
        /* If connection is established then start communicating */
        n = read( port,&buffer[0],255 );

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        if(buffer=="end")
            break;
        mat.add(buffer,i);
        i++;
    }

}


