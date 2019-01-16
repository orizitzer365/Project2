//
// Created by nadav on 1/16/19.
//

#ifndef PRO2_ASTAR_H
#define PRO2_ASTAR_H

#include "GraphSearcher.h"

class AStar : public GraphSearcher{
public:
    virtual void search(SearchableGraph *searchable, GraphSolution *gs) {
        State init = searchable->getInitialState();
        State goal = searchable->getGoalState();
        // The set of currently discovered nodes that are not evaluated yet:
        this->pushToOpenList(init,searchable->heuristicFunction(init));
        while (this->sizeOfOpenList() != 0){
            int cCost = this->frontOfOpenList().getCost();
            State current = this->popOpenList();
            if(current == goal){
                gs->set(this->getCameFrom(),goal,init);
                return;
            }
            this->pushToCloseList(current);
            vector<State>* neis = searchable->getAllPossibleStates(current);
            for (State neighbor : *neis){
                if(this->IsClose(neighbor)){
                    continue;
                }
                if(neighbor.getCost() == -1){
                    continue;
                }
                int cost = searchable->heuristicFunction(neighbor)+neighbor.getCost()+cCost;
                if(!IsOpen(neighbor)){
                    this->pushToOpenList(neighbor,cost);
                    this->setCameFrom(neighbor,current);
                    continue;
                }
                if(this->getPriority(neighbor) < cost){
                    continue;
                }
                this->changePriorityInOpenList(neighbor,cost);
                this->setCameFrom(neighbor,current);
            }
            delete neis;
        }
        gs->set();
    }
};

#endif //PRO2_ASTAR_H
