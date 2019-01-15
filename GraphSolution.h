//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_GRAPHSOLUTION_H
#define PRO2_GRAPHSOLUTION_H

#include "Solution.h"
#include <map>
#include "Comparator.h"
#include "State.h"
#include <vector>

template <class StateType>
class GraphSolution : public Solution{
protected:
     bool noSolution;
     std::vector<StateType> list;
public:
    GraphSolution(){
        noSolution = true;
    }
    GraphSolution(std::map<StateType,StateType,Comparator<StateType>> cameFrom,
                  StateType goal,StateType init){
        std::vector<StateType> temp;
        temp.push_back(goal);
        while(!(goal == init)){
            goal = cameFrom[goal];
            temp.push_back(goal);
        }
        for(int i= temp.size()-1;i>=0;i--){
            list.push_back(temp[i]);
        }
        noSolution = false;
    }
};

#endif //PRO2_GRAPHSOLUTION_H
