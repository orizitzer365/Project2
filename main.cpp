#include <iostream>
#include "StringReverser.h"
#include "cache_manager/FileCacheManager.h"
#include "server_side/MySerialServer.h"
#include "server_side/MyParallelServer.h"
#include "server_side/MyClientHandler.h"
using cache_manager::FileCacheManager;
int main(int argc, char* argv[]) {
    if(argc!=2)
        throw "Invalid Argument";
    server_side::Server *server= new server_side::MyParallelServer();
    ClientHandler * clientHandler = new MyClientHandler(new FileCacheManager(),new StringReverser());
    server->open(std::stoi(argv[1]),clientHandler);
    delete server;
    delete(clientHandler);
}