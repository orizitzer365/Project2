//
// Created by ori on 1/11/19.
//

#include "Matrix.h"

Matrix::Matrix(){}

int Matrix::add(std::string line,int lineNumber) {
    int j = 0;
    std::string val;

    while((line.at(j)!='\0'&&line.at(j)!='\n')) {
        while (line.at(j)!=','&&line.at(j)!='\0'&&line.at(j)!='\n'){
            //val+=line.at(j);
            val.push_back(line.at(j));
        }
        if(val!="")
            matrix.at(lineNumber).push_back(stoi(val));
        j++;
        val="";
    }
    //if couple of lines are in one buffer
    if(line.at(j+1)!='\0')
        return add(line.substr(j+1,line.size()-j-1),lineNumber+1);
    return lineNumber+1;
}

void Matrix::setStart(std::pair<int, int> start) {
    Matrix::start = start;
}

void Matrix::setEnd(std::pair<int, int> end) {
    Matrix::end = end;
}

std::pair<int, int> Matrix::getStart() const {
    return start;
}

std::pair<int, int> Matrix::getEnd() const {
    return end;
}

int Matrix::at(int row, int col) {
    return matrix.at(row).at(col);
}
std::string vectorTostring(vector<int> vec){
    std::string line;
    for(auto it:vec){
        line+=std::to_string(it) +",";
    }
    line +=" $";
    return line;
}
std::string Matrix::to_string(){
    std::string line ;
    for(auto it:matrix){
        line+=vectorTostring(it);
    }
    line += '(' + std::to_string(start.first) +  "," + std::to_string(start.second) +")";
    line += '(' + std::to_string(end.first) +  "," + std::to_string(end.second) +")";
    return line;
}
std::pair<int,int> pairFromString(std::string line, int i){
    std::string buf="";
    int x,y;
    while(line.at(i)!=','){
        buf+=line.at(i);
        i++;
    }
    x=std::stoi(buf);
    i++;
    while(line.at(i)!=')'){
        buf+=line.at(i);
        i++;
    }
    y=std::stoi(buf);
    return std::make_pair(x,y);
}
void Matrix::from_string(std::string line) {
    std::string buf;
    int i = 0;
    int j =0;
    while(line.at(i)!='(') {
        buf="";
        while (line.at(i) != '$') {
            buf+=line.at(i);
            i++;
        }
        //delete the ',' int the end
        buf.pop_back();
        add(buf,j);
        i++;
        j++;
    }
    i++;
    setStart(pairFromString(line,i));
    while(line.at(i)!=')'){
        i++;
    }
    i+=2;
    setEnd(pairFromString(line,i));
    while(line.at(i)!=')'){
        i++;
    }
}

int Matrix::rowLen() {
    return matrix.size();
}

int Matrix::colLen() {
    return matrix.at(0).size();
}