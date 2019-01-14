//
// Created by ori on 1/14/19.
//

#ifndef PROJECT2_MATRIXSOLUTION_H
#define PROJECT2_MATRIXSOLUTION_H

#include "Solution.h"

class MatrixSolution: public Solution{
private:
    int sol;
public:
    MatrixSolution() {}

    MatrixSolution(int sol) : sol(sol) {}

    std::string to_string() override {
        return "$"+std::to_string(sol)+"$\n";
    }

    void from_string(std::string line) override {
        int i =1;
        std::string buf;
        while (line.at(i)!='$'){
            buf+=line.at(i);
            i++;
        }
        sol = std::stoi(buf);
    }
};
#endif //PROJECT2_MATRIXSOLUTION_H
