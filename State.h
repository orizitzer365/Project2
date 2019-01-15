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

public:

    State(StateTipe state , double cost): state(state), cost(cost){}

    State(StateTipe state): state(state){
        cost = DEFAULT_COST;
    }

    bool operator==(State<StateTipe> other){
        return other.state == this->state;
    }

    virtual bool operator<(State<StateTipe> other){
        return other.state < this->state;
    }

    double getCost(){
        return cost;
    }

    StateTipe getState(){
        return StateTipe(state);
    }

};




#endif //PRO2_STATE_H
