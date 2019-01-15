//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_SEARCHABLEGraph_H
#define PRO2_SEARCHABLEGraph_H

#include <list>
#include "State.h"
using std::list;

template <class Stat>
class SearchableGraph{
public:
    virtual Stat getInitialState() = 0;
    virtual Stat getGoalState() = 0;
    virtual list<Stat> getAllPossibleStates(Stat s) = 0;
};

template <class Stat>
class SmartSearchableGraph : public SearchableGraph<Stat>{
public:
    virtual double heuristicFunction(Stat thisState,Stat goalState) = 0;
    double heuristicFunction(Stat thisState){
        return heuristicFunction(thisState,this->getGoalState());
    }
};


#endif //PRO2_SEARCHABLEGraph_H
