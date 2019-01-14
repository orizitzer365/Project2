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
#include <cstring>

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
    string size(512,0),start(512,0),end(512,0);
    n = read( port,&size[0],511 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    Matrix* mat = new Matrix();

    int i=0;
    while (true){
        string buffer(512,0);
        buffer.resize(512);
        /* If connection is established then start communicating */
        n = read( port,&buffer[0],511 );

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        if(buffer=="end")
            break;
        mat->add(buffer,i);
        i++;
    }
    n = read( port,&start[0],511 );
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    mat->setStart(makePairOutOfCordinates(start));
    n = read( port,&end[0],511 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    mat->setEnd(makePairOutOfCordinates(end));
    Solution *sol;
    if(cacheManager->isExists(mat))
        sol = cacheManager->get(mat);
    else
        sol = solver->solve(mat);
    send(port,sol->to_string().c_str(),sol->to_string().size(),0);
    if(!cacheManager->isExists(mat))
        cacheManager->set(mat,sol);
}

MyClientHandler::MyClientHandler() {}

MyClientHandler::MyClientHandler(cache_manager::CacheManager<Problem, Solution> *cacheManager,Solver* solver1) :
cacheManager(cacheManager) ,solver(solver1){}


