//
// Created by ori on 1/11/19.
//

#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include <string>
#include <vector>

using std::vector;
class Matrix {
private:
    vector<vector<int> > matrix;
    int rowSize;
    std::pair<int,int> start;
    std::pair<int,int> end;
public:
    Matrix(int rowSize);
    void add(std::string line,int lineNumber);

    void setStart(std::pair<int, int> start);

    void setEnd(std::pair<int, int> end);
};


#endif //PROJECT2_MATRIX_H
