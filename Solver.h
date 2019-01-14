//
// Created by ori on 1/14/19.
//

#ifndef PROJECT2_SOLVER_H
#define PROJECT2_SOLVER_H

#include "Solution.h"
#include "Problem.h"

class Solver{
public:
    virtual Solution* solve(Problem* problem) = 0;
};
#endif //PROJECT2_SOLVER_H
