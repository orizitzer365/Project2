//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_STATE_H
#define PRO2_STATE_H

#define DEFAULT_COST 1;

template <class StateTipe>
class State {

    StateTipe state;
    double cost;
    State<StateTipe>* cameFrom;

public:

    State(StateTipe state , double cost): state(state), cameFrom(nullptr), cost(cost){}

    State(StateTipe state): state(state), cameFrom(nullptr){
        cost = DEFAULT_COST;
    }
/*
    State(State<StateTipe>& other){
        state = other.state;
        cost = other.cost;
        cameFrom = other.cameFrom;
    }*/

    bool operator==(State<StateTipe>& other){
        return other.state == this->state;
    }

    double getCost(){
        return cost;
    }

    StateTipe& getState(){
        return StateTipe(state);
    }

    State<StateTipe>* getCameFrom(){
        return cameFrom;
    }

    void setCameFrom(State<StateTipe>* cameFrom){
        this->cameFrom = cameFrom;
    }

};




#endif //PRO2_STATE_H
