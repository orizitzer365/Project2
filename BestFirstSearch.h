//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_BESTFIRSTSEARCH_H
#define PRO2_BESTFIRSTSEARCH_H

#include "GraphSearcher.h"

template <class StateTipe,class SolutionType>
class BestFirstSearch : public GraphSearcher<StateTipe,SolutionType>{
public:
    SolutionType search(SearchableGraph<StateTipe> searchable) {
        // a priority queue of states to be evaluated that contains the initial state:
        this->pushToOpenList(searchable.getInitialState());
        while (this->sizeOfOpenList() != 0){
            // Remove the best node from OPEN
            int nodePriority = this->getPriority(this->frontOfOpenList());
            auto n = this->popOpenList();
            // so we won’t check n again:
            this->pushToCloseList(n);
            //the goal:
            if(n == searchable.getGoalState()){
                return SolutionType(this->getCameFrom(),n,searchable.getInitialState());
            }
            //Create n's successors:
            auto successors = searchable.getAllPossibleStates(n);
            for(auto successor : successors){
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
                if(this->IsClose()){
                    continue;
                }
                //else -> adds s to the opens:
                this->setCameFrom(successor,n);
                double newPriority = nodePriority + successor.getCost();
                this->pushToOpenList(successor,newPriority);
            }
        }
        return new SolutionType();
    }
};


#endif //PRO2_BESTFIRSTSEARCH_H
