//
// Created by ori on 1/14/19.
//

#ifndef PROJECT2_SOLVER_H
#define PROJECT2_SOLVER_H

template <class P,class S>
class Solver{
public:
    virtual S* solve(P* problem) = 0;
};
#endif //PROJECT2_SOLVER_H
