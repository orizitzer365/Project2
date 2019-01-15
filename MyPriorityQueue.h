//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_MYPRIORITYQUEUE_H
#define PRO2_MYPRIORITYQUEUE_H

#define INVALID_STATE -1

#include <vector>
#include <algorithm>
#include "State.h"
#include "HeapCompare.h"

using std::vector;
using std::pair;

template <class StateTipe>
class MyPriorityQueue{
    vector<pair<State<StateTipe>,int>> vec;
    HeapCompare<State<StateTipe>> h;
public:

    void push(State<StateTipe>& s,int priority){
        vec.push_back(pair<State<StateTipe>,int>(State<StateTipe>(s),priority));
        std::push_heap(vec.begin(), vec.end(),h);
    }

    void pop(){
        std::pop_heap(vec.begin(), vec.end(),h);
        vec.pop_back();
    }

    State<StateTipe> front(){
        return vec.front().first;
    }

    int getSize(){
        return vec.size();
    }

    int getPriority(State<StateTipe> s){
        for(pair<State<StateTipe>,int> p : vec){
            if(p.first == s){
                return p.second;
            }
        }
        return INVALID_STATE;
    }

    void remove(State<StateTipe> s){
        auto start = vec.begin();
        auto end = vec.end();
        while (start != end){
            if(s == start->first){
                vec.erase(start);
                return;
            }
            start++;
        }
    }

    void changePriority(State<StateTipe> s,int newPri){
        remove(s);
        std::make_heap(vec.begin(),vec.end(),h);
        push(s,newPri);
    }

};

#endif //PRO2_MYPRIORITYQUEUE_H