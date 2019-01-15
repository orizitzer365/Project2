//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_GRAPHSEARCHER_H
#define PRO2_GRAPHSEARCHER_H

#include "MyPriorityQueue.h"
#include "SearchableGraph.h"
#include "Comparator.h"
#include <map>

enum StateOfState {Open,Close,Nothing};

template <class StateTipe,class SolutionType,class SearchTipeable = SearchableGraph<StateTipe>>
class GraphSearcher{
    int evaluatedStates;
    MyPriorityQueue<StateTipe> openList;
    std::map<StateTipe,StateOfState,Comparator<StateTipe>> statesInfo;
    std::map<StateTipe,StateTipe,Comparator<StateTipe>> cameFrom;

    StateOfState stateOfState(StateTipe s){
        try {
            return statesInfo.at(s);
        } catch (...){
            return Nothing;
        }
    }

protected:
    void setCameFrom(StateTipe s,StateTipe t){
        cameFrom[s] = t;
    }
    StateTipe getCameFrom(StateTipe s){
        return cameFrom.at(s);
    }
    std::map<StateTipe,StateTipe,Comparator<StateTipe>>* getCameFrom(){
        return &cameFrom;
    }
    void pushToOpenList(StateTipe s){
        openList.push(s);
        statesInfo[s] = Open;
    }
    void pushToCloseList(StateTipe s){
        statesInfo[s] = Close;
    }
    StateTipe popOpenList(){
        evaluatedStates++;
        StateTipe s = openList.front();
        openList.pop();
        return s;
    }
    StateTipe frontOfOpenList(){
        return openList.front();
    }
    int getPriority(StateTipe s){
        return openList.getPriority();
    }
    void changePriorityInOpenList(StateTipe s,int newPri){
        openList.changePriority(s,newPri);
    }
    bool IsOpen(StateTipe s){
        return stateOfState(s) == Open;
    }
    bool IsClose(StateTipe s){
        return stateOfState(s) == Close;
    }
public:
    GraphSearcher(): evaluatedStates(0){}

    int sizeOfOpenList(){
        return openList.getSize();
    }

    int getNumberOfStatesEvaluated(){
        return evaluatedStates;
    }

    virtual SolutionType* search(SearchTipeable* searchable) = 0;

};


#endif //PRO2_GRAPHSEARCHER_H
