//
// Created by nadav on 1/16/19.
//

#ifndef PRO2_SEARCHABLEMATRIXS_H
#define PRO2_SEARCHABLEMATRIXS_H

#include "Matrix.h"
#include "SearchableGraph.h"
#include "math.h"

class SearchableMatrixs : public SearchableGraph{
    Matrix* mat;
public:
    SearchableMatrixs(Matrix* matrix) : SearchableGraph() , mat(matrix){}

    virtual State getInitialState() {
        return State(MyType(pair<int,int>(0,0)),mat->at(0,0) );
    }

    virtual State getGoalState() {
        int n = mat->rowLen();
        int m = mat->colLen();
        return State(MyType(pair<int,int>(n-1,m-1)),mat->at(n-1,m-1) );
    }

    virtual vector<State> *getAllPossibleStates(State s) {
        vector<State>* states = new vector<State>();
        int i = s.getState().get().first;
        int j = s.getState().get().second;
        if(i>0){
            states->push_back(State(MyType(pair<int,int>(i-1,j)),mat->at(i-1,j)));
        }
        if(j>0){
            states->push_back(State(MyType(pair<int,int>(i,j-1)),mat->at(i,j-1)));
        }
        if(i < mat->rowLen() -1){
            states->push_back(State(MyType(pair<int,int>(i+1,j)),mat->at(i+1,j)));
        }
        if(j < mat->colLen() -1){
            states->push_back(State(MyType(pair<int,int>(i,j+1)),mat->at(i,j+1)));
        }
        return states;
    }

    virtual double heuristicFunction(State thisState, State goalState) {
        int f = abs(thisState.getState().get().first - goalState.getState().get().first);
        int s = abs(thisState.getState().get().second - goalState.getState().get().second);
        return f + s;
    }

    virtual double heuristicFunction(State thisState) {
        return heuristicFunction(thisState,this->getGoalState());;
    }
};


#endif //PRO2_SEARCHABLEMATRIXS_H
