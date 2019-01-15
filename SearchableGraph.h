//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_SEARCHABLEGraph_H
#define PRO2_SEARCHABLEGraph_H

#include <list>
#include "State.h"
using std::list;

template <class StateTipe>
class SearchableGraph{
public:
    virtual State<StateTipe> getInitialState() = 0;
    virtual State<StateTipe> getGoalState() = 0;
    virtual list<State<StateTipe>> getAllPossibleStates(State<StateTipe> s) = 0;
};

template <class StateTipe>
class SmartSearchableGraph : public SearchableGraph<StateTipe>{
public:
    virtual double heuristicFunction(State<StateTipe> thisState,State<StateTipe> goalState) = 0;
    double heuristicFunction(State<StateTipe> thisState){
        return heuristicFunction(thisState,this->getGoalState());
    }
};


#endif //PRO2_SEARCHABLEGraph_H
