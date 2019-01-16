//
// Created by nadav on 1/16/19.
//

#ifndef RO2_MYSOLVER_H
#define RO2_MYSOLVER_H

#include "Solver.h"
#include "Matrix.h"
#include "MatrixSolution.h"
#include "GraphSearcher.h"
#include "SearchableMatrixs.h"

class MySolver : public Solver<Matrix,Solution>{
    GraphSearcher* gs;
public:
    MySolver(GraphSearcher* gs) :gs(gs){}
    virtual Solution *solve(Matrix *problem) {
        SearchableMatrixs* sm = new SearchableMatrixs(problem);
        GraphSolution* gsul = new GraphSolution();
        gs->search(sm,gsul);
        MatrixSolution* matrixSolution = new MatrixSolution(gsul);
        delete sm;
        delete gsul;
        return matrixSolution;
    }
    ~MySolver(){
        delete gs;
    }
};

#endif //RO2_MYSOLVER_H