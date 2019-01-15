//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_HEAPCOMPARE_H
#define PRO2_HEAPCOMPARE_H

#include <utility>

using std::pair;

template <class T> class HeapCompare{
public:
    bool operator()(const pair<T,int>& p1,const pair<T,int>& p2){
        return p1.second > p2.second;
    }
};


#endif //PRO2_HEAPCOMPARE_H
