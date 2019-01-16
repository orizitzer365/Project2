
//
// Created by ori on 1/14/19.
//

#ifndef PROJECT2_MATRIXSOLUTION_H
#define PROJECT2_MATRIXSOLUTION_H

#include "GraphSolution.h"
#include "Solution.h"
#include "vector"
using std::vector;
using std::string;
using std::pair;

class MatrixSolution: public Solution{
private:
    std::string sol;

    string getDir(State from,State goal){
        pair<int,int> p1 = from.getState().get();
        pair<int,int> p2 = goal.getState().get();
        if(p1.first < p2.first){
            return "Down";
        }
        if(p1.first > p2.first){
            return "Up";
        }
        if(p1.second < p2.second){
            return "Right";
        }
        return "Left";
    }
public:
    MatrixSolution() {
        sol = "-1";
    }

    MatrixSolution(GraphSolution* gs) : Solution(){
        if(gs->isNoSolution()){
            sol = -1;
            return ;
        }
        sol = "";
        vector<State> list = gs->getList();
        sol += getDir(list[0],list[1]);
        for (int i = 2; i < list.size(); ++i) {
            sol += ',';
            sol += getDir(list[i-1],list[i]);
        }
    }

    std::string to_string() override {
        return sol;
    }

    void from_string(std::string line) override {
        sol = line;
    }

};
#endif //PROJECT2_MATRIXSOLUTION_H