//
// Created by ori on 1/15/19.
//

#ifndef PROJECT2_STRINGREVERSER_H
#define PROJECT2_STRINGREVERSER_H

#include <algorithm>
#include "Solver.h"
#include "StringProblem&Solution.h"
class StringReverser: public Solver<Problem,Solution>{
public:
    Solution *solve(Problem *problem) {

        std::string s = problem->to_string() ;
        std::reverse(s.begin(),s.end());
        return new stringProblemAndSolution(s);
    }
};
#endif //PROJECT2_STRINGREVERSER_H
