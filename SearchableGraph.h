//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_SEARCHABLEGraph_H
#define PRO2_SEARCHABLEGraph_H

#include <list>
#include "State.h"
using std::list;

//template <class StateType>
class SearchableGraph{
public:
    virtual State getInitialState() = 0;
    virtual State getGoalState() = 0;
    virtual vector<State>* getAllPossibleStates(State s) = 0;
    virtual double heuristicFunction(State thisState,State goalState){
        return 0;
    }

    virtual double heuristicFunction(State thisState){
        return heuristicFunction(thisState,this->getGoalState());
    }
};

#endif //PRO2_SEARCHABLEGraph_H
