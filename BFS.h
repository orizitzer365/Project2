//
// Created by nadav on 1/16/19.
//

#ifndef PRO2_BFS_H
#define PRO2_BFS_H

#include "GraphSearcher.h"

class BFS : public GraphSearcher{
public:
    virtual void search(SearchableGraph *searchable, GraphSolution *gs) {
        int pr = 0;
        State goal = searchable->getGoalState();
        this->pushToOpenList(searchable->getInitialState(),pr++);
        while (this->sizeOfOpenList() != 0){
            State current = this->popOpenList();
            this->pushToCloseList(current);
            if(current == goal){
                gs->set(this->getCameFrom(),goal,searchable->getInitialState());
                return;;
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
            }
            delete neis;
        }
        gs->set();
    }
};

#endif //PRO2_BFS_H
