//
// Created by ori on 1/11/19.
//

#ifndef PROJECT2_PROBLEM_H
#define PROJECT2_PROBLEM_H

#include <string>

class Problem{
public:
    virtual std::string to_string()=0;
    virtual void from_string(std::string )=0;
};
#endif //PROJECT2_PROBLEM_H
