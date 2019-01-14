//
// Created by ori on 1/11/19.
//

#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include <string>
#include <vector>
#include "Problem.h"

using std::vector;
class Matrix: public Problem {
private:
    vector<vector<int> > matrix;
    int rowSize;
    std::pair<int,int> start;
    std::pair<int,int> end;
public:
    Matrix();
    void add(std::string line,int lineNumber);

    void setStart(std::pair<int, int> start);

    void setEnd(std::pair<int, int> end);

    std::pair<int, int> getStart() const;

    std::pair<int, int> getEnd() const;

    int at(int row ,int col);

    std::string to_string() override;

    void from_string(std::string string) override;
};


#endif //PROJECT2_MATRIX_H
