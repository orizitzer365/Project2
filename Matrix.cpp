//
// Created by ori on 1/11/19.
//

#include "Matrix.h"

Matrix::Matrix(int rowSize) : rowSize(rowSize) {}

void Matrix::add(std::string line,int lineNumber) {
    int j = 0 ;
    std::string val;
    for (int i = 0; i < rowSize; ++i) {
        val="";
        while (line.at(j)!=','&&line.at(j)!='\0')
            val+=line.at(j);
        j++;
        matrix.at(lineNumber).push_back(stoi(val));
    }
}

void Matrix::setStart(std::pair<int, int> start) {
    Matrix::start = start;
}

void Matrix::setEnd(std::pair<int, int> end) {
    Matrix::end = end;
}
