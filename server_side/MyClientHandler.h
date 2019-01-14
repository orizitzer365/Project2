//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_MYCLIENTHANDLER_H
#define PROJECT2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "../cache_manager/CacheManager.h"
#include "../Matrix.h"
#include "../MatrixSolution.h"
#include "../cache_manager/FileCacheManager.h"
#include "../Solver.h"

class MyClientHandler :ClientHandler{
private:
    cache_manager::CacheManager<Problem,Solution> *cacheManager;
    Solver *solver;

public:
    MyClientHandler();

    MyClientHandler(cache_manager::CacheManager<Problem, Solution> *cacheManager,Solver* solver1);

    void handleClient(int port) override;
};


#endif //PROJECT2_MYCLIENTHANDLER_H
