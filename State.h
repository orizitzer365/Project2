//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_STATE_H
#define PRO2_STATE_H

#define DEFAULT_COST 1;

#include "StateType.h"

//template <class StateType>
class State {

    StateType state;
    double cost;

public:

    State(StateType state , double cost): state(state), cost(cost){}

    State(StateType state): state(state){
        cost = DEFAULT_COST;
    }

    bool operator==(State other){
        return other.state == this->state;
    }

    virtual bool operator<(State other){
        return other.state < this->state;
    }

    double getCost(){
        return cost;
    }

    StateType getState(){
        return StateType(state);
    }

};




#endif //PRO2_STATE_H
