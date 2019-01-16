#include <iostream>
#include "MySolver.h"
#include "cache_manager/FileCacheManager.h"
#include "server_side/MySerialServer.h"
#include "server_side/MyParallelServer.h"
#include "server_side/MyClientHandler.h"
#include "StateType.h"
#include "AStar.h"
using cache_manager::FileCacheManager;
int main(int argc, char* argv[]) {
    if(argc!=2)
        throw "Invalid Argument";
    server_side::Server *server= new server_side::MyParallelServer();
    Solver<Problem,Solution> * s = new MySolver(new ALGO);
    ClientHandler * clientHandler = new MyClientHandler(new FileCacheManager(),s);
    server->open(std::stoi(argv[1]),clientHandler);
    delete server;
    delete(clientHandler);
}