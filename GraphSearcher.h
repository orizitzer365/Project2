//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_GRAPHSEARCHER_H
#define PRO2_GRAPHSEARCHER_H

#include "MyPriorityQueue.h"
#include "SearchableGraph.h"

template <class StateTipe,class SolutionType,class SearchTipeable = SearchableGraph<StateTipe>>
class GraphSearcher{
    int evaluatedStates;
    MyPriorityQueue<StateTipe> openList;
protected:
    void pushToOpenList(State<StateTipe>& s){
        openList.push(s);
    }
    State<StateTipe> popOpenList(){
        evaluatedStates++;
        State<StateTipe> s = openList.front();
        openList.pop();
        return s;
    }
    State<StateTipe> frontOfOpenList(){
        return openList.front();
    }
    void changePriorityInOpenList(State<StateTipe> s,int newPri){
        openList.changePriority(s,newPri);
    }
public:
    GraphSearcher(): evaluatedStates(0){}

    int sizeOfOpenList(){
        return openList.getSize();
    }

    int getNumberOfStatesEvaluated(){
        return evaluatedStates;
    }

    virtual SolutionType search(SearchTipeable searchable) = 0;

};


#endif //PRO2_GRAPHSEARCHER_H
