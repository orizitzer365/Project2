//
// Created by nadav on 1/16/19.
//

#ifndef PRO2_STATEMAP_H
#define PRO2_STATEMAP_H

#include <vector>
#include "State.h"

using std::vector;
using std::pair;

template <class T>
class StateMap{
    vector<pair<State,T>> l;
public:
    void add(pair<State,T> p){
        for (int i = 0; i < l.size(); ++i) {
            if(l[i].first == p.first){
                l[i].second = p.second;
                return;
            }
        }
        l.push_back(p);
    }
    T at(State s){
        for (pair<State,T> p : l){
            if(p.first == s){
                return p.second;
            }
        }
        throw "mis";
    }
    void add(State s,T t){
        add(pair<State,T>(s,t));
    }
};


#endif //PRO2_STATEMAP_H
