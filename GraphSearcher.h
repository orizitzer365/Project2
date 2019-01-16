//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_GRAPHSEARCHER_H
#define PRO2_GRAPHSEARCHER_H

#include "MyPriorityQueue.h"
#include "SearchableGraph.h"
#include "StateMap.h"
#include "GraphSolution.h"

enum StateOfState {Open,Close,Nothing};

//template <class StateType>
class GraphSearcher{
    int evaluatedStates;
    MyPriorityQueue openList;
    StateMap<StateOfState> statesInfo;
    StateMap<State> cameFrom;

    StateOfState stateOfState(State s){
        try {
            return statesInfo.at(s);
        }catch (...){
            return Nothing;
        }
    }

protected:
    virtual void setCameFrom(State s,State t){
        cameFrom.add(pair<State,State>(s,t));
    }

    virtual State getCameFrom(State s){
        return cameFrom.at(s);
    }

    virtual StateMap<State>* getCameFrom(){
        return &cameFrom;
    }

    virtual void pushToOpenList(State s, int priority){
        if (priority == -1){
            return;
        }
        openList.push(s,priority);
        statesInfo.add(pair<State,StateOfState >(s,Open));
    }

    virtual void pushToCloseList(State s){
        statesInfo.add(pair<State,StateOfState >(s,Close));
    }

    virtual State popOpenList(){
        evaluatedStates++;
        State s = openList.front();
        openList.pop();
        return s;
    }

    virtual State frontOfOpenList(){
        return openList.front();
    }

    virtual int getPriority(State s){
        return openList.getPriority(s);
    }

    virtual void changePriorityInOpenList(State s,int newPri){
        openList.changePriority(s,newPri);
    }

    virtual bool IsOpen(State s){
        return stateOfState(s) == Open;
    }

    virtual bool IsClose(State s){
        return stateOfState(s) == Close;
    }
public:
    GraphSearcher(): evaluatedStates(0){}

    virtual int sizeOfOpenList(){
        return openList.getSize();
    }

    virtual int getNumberOfStatesEvaluated(){
        return evaluatedStates;
    }

    virtual void search(SearchableGraph* searchable,GraphSolution* gs) = 0;

};


#endif //PRO2_GRAPHSEARCHER_H
