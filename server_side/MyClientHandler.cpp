//
// Created by ori on 1/8/19.
//

#include "MyClientHandler.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>
#include <sys/socket.h>
#include <cstring>
using std::string;
//this function take a string of two numbers seperates with ',' and return pair of them
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
    Matrix* mat = new Matrix();
    vector<string> strings;
    int i=0;
    //reading the rows of the matrix
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
        if(i>=2){
            mat->add(strings.at(i-2),i-2);
        }
        i++;
        strings.push_back(buffer);
    }
    //set the start and the end of the matrix
    mat->setStart(makePairOutOfCordinates(strings.at(strings.size()-2)));
    mat->setEnd(makePairOutOfCordinates(strings.at(strings.size()-1)));
    Solution *sol;
    //check if the solution exist in the cache , if it if exists then we return it
    //otherwise we solve the problem
    if(cacheManager->isExists(mat))
        sol = cacheManager->get(mat);
    else
        sol = solver->solve(mat);
    send(port,sol->to_string().c_str(),sol->to_string().size(),0);
    if(!cacheManager->isExists(mat))
    cacheManager->set(mat,sol);
}

MyClientHandler::MyClientHandler() {}

MyClientHandler::MyClientHandler(cache_manager::CacheManager<Problem, Solution> *cacheManager,Solver<Problem,Solution>* solver1) :
cacheManager(cacheManager) ,solver(solver1){}




