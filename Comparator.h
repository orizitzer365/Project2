//
// Created by nadav on 1/15/19.
//

#ifndef PRO2_COMPARATOR_H
#define PRO2_COMPARATOR_H

template <class Comparable>
class Comparator{
public:
    bool operator()(Comparable c1,Comparable c2){
        return c1 < c2;
    }
};

#endif //PRO2_COMPARATOR_H
