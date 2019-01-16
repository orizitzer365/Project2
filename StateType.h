//
// Created by nadav on 1/16/19.
//

#ifndef PRO2_STATETYPE_H
#define PRO2_STATETYPE_H

using std::pair;

#define StateType MyType

class MyType{
    pair<int,int> p;
public:
    MyType(pair<int,int> p):p(p){}
    bool operator==(MyType&b){
        return (this->p.first == b.p.first)&&(this->p.second == b.p.second);
    }
    bool operator<(MyType& b){
        pair<int,int> p1 = this->p;
        pair<int,int> p2 = b.p;
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first < p1.second;
    }
    pair<int,int> get(){
        return p;
    }
};

#endif //PRO2_STATETYPE_H
