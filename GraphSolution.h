//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_GRAPHSOLUTION_H
#define PRO2_GRAPHSOLUTION_H

#include "State.h"
#include <vector>

//template <class StateType>
class GraphSolution{
protected:
     bool noSolution;
     std::vector<State> list;
public:
    GraphSolution(){
        noSolution = true;
    }
    std::vector<State> getList(){
        return list;
    }
    bool isNoSolution(){
        return noSolution;
    }
    void set(){
        noSolution = true;
    }
    void set(StateMap<State>* cameFrom,
             State goal,State init){
        std::vector<State> temp;
        temp.push_back(goal);
        while(!(goal == init)){
            goal = cameFrom->at(goal);
            temp.push_back(goal);
        }
        for(int i= temp.size()-1;i>=0;i--){
            list.push_back(temp[i]);
        }
        noSolution = false;
    }
};

#endif //PRO2_GRAPHSOLUTION_H
