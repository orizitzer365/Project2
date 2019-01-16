//
// Created by nadav on 1/16/19.
//

#ifndef PRO2_DFS_H
#define PRO2_DFS_H

#include "GraphSearcher.h"
#include <stack>
using std::stack;

class DFS : public GraphSearcher{
    stack<State>* open;
    int counter;
public:
    DFS(): GraphSearcher(){
        counter = 0;
        open = new stack<State>();
    }

    virtual void search(SearchableGraph *searchable, GraphSolution *gs) {
        int pr = 0;
        State goal = searchable->getGoalState();
        open->push(searchable->getInitialState());
        while (open->size() != 0){
            State current = open->top();
            open->pop();
            counter++;
            this->pushToCloseList(current);
            if(current == goal){
                gs->set(this->getCameFrom(),goal,searchable->getInitialState());
                return;
            }
            vector<State>* neis = searchable->getAllPossibleStates(current);
            for(State neighbor : *neis){
                if(this->IsClose(neighbor)){
                    continue;
                }
                if(neighbor.getCost() == -1){
                    continue;
                }
                if(this->IsOpen(neighbor)){
                    continue;
                }
                this->setCameFrom(neighbor,current);
                this->pushToOpenList(neighbor,pr++);
                open->push(neighbor);
            }
            delete neis;
        }
        gs->set();
    }

    virtual int sizeOfOpenList() {
        return open->size();
    }

    virtual int getNumberOfStatesEvaluated() {
        return counter;
    }

    ~DFS(){
        delete open;
    }
};


#endif //PRO2_DFS_H
