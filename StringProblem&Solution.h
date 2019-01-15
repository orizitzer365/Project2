//
// Created by ori on 1/15/19.
//

#ifndef PROJECT2_STRINGPROBLEM_SOLUTION_H
#define PROJECT2_STRINGPROBLEM_SOLUTION_H

#include "Problem.h"
#include "Solution.h"

class stringProblemAndSolution: public Problem , public Solution{
private:
    std::string s;
public:
    stringProblemAndSolution(const std::string &s) : s(s) {}

    stringProblemAndSolution() {}

    std::string to_string()override {
        return s;
    }

    void from_string(std::string string) override {
        s =string;
    }
};
#endif //PROJECT2_STRINGPROBLEM_SOLUTION_H
