//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_BESTFIRSTSEARCH_H
#define PRO2_BESTFIRSTSEARCH_H

#include "GraphSearcher.h"


//template <class StateType>
class BestFirstSearch : public GraphSearcher{
public:
    BestFirstSearch():GraphSearcher(){}

    virtual int sizeOfOpenList() {
        return GraphSearcher::sizeOfOpenList();
    }

    virtual int getNumberOfStatesEvaluated() {
        return GraphSearcher::getNumberOfStatesEvaluated();
    }

protected:
    virtual void setCameFrom(State s, State t) {
        GraphSearcher::setCameFrom(s, t);
    }

    virtual State getCameFrom(State s) {
        return GraphSearcher::getCameFrom(s);
    }

    virtual StateMap<State> *getCameFrom() {
        return GraphSearcher::getCameFrom();
    }

    virtual void pushToOpenList(State s,int priority) {
        GraphSearcher::pushToOpenList(s,priority);
    }

    virtual void pushToCloseList(State s) {
        GraphSearcher::pushToCloseList(s);
    }

    virtual State popOpenList() {
        return GraphSearcher::popOpenList();
    }

    virtual State frontOfOpenList() {
        return GraphSearcher::frontOfOpenList();
    }

    virtual int getPriority(State s) {
        return GraphSearcher::getPriority(s);
    }

    virtual void changePriorityInOpenList(State s, int newPri) {
        GraphSearcher::changePriorityInOpenList(s, newPri);
    }

    virtual bool IsOpen(State s) {
        return GraphSearcher::IsOpen(s);
    }

    virtual bool IsClose(State s) {
        return GraphSearcher::IsClose(s);
    }

public:
    void search(SearchableGraph* searchable,GraphSolution* gs) {
        // a priority queue of states to be evaluated that contains the initial state:
        this->pushToOpenList(searchable->getInitialState(),0);
        while (this->sizeOfOpenList() != 0){
            // Remove the best node from OPEN
            int nodePriority = this->getPriority(this->frontOfOpenList());
            State n = this->popOpenList();
            // so we won’t check n again:
            this->pushToCloseList(n);
            //the goal:
            if(n == searchable->getGoalState()){
                gs->set(this->getCameFrom(),n,searchable->getInitialState());
                return;
            }
            //Create n's successors:
            vector<State>* successors = searchable->getAllPossibleStates(n);
            for(int i=0;i<successors->size();++i){
                State successor = (*successors)[i];
                //s is open -> adjust its priority
                if(this->IsOpen(successor)){
                    double oldPriority = this->getPriority(successor);
                    double newPriority = nodePriority + successor.getCost();
                    if(newPriority<oldPriority){
                        this->changePriorityInOpenList(successor,newPriority);
                        this->setCameFrom(successor,n);
                    }
                    continue;
                }
                //s is close:
                if(this->IsClose(successor)){
                    continue;
                }
                if (successor.getCost() == -1){
                    continue;
                }
                //else -> adds s to the opens:
                this->setCameFrom(successor,n);
                double newPriority = nodePriority + successor.getCost();
                this->pushToOpenList(successor,newPriority);
            }
            delete successors;
        }
        gs->set();
    }
};


#endif //PRO2_BESTFIRSTSEARCH_H
