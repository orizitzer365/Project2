//
// Created by ori on 1/11/19.
//

#ifndef PROJECT2_PROBLEM_H
#define PROJECT2_PROBLEM_H

#include <iostream>
#include <string>
using std::ostream;
using std::istream;
class Problem{
public:
    virtual std::string to_string() =0;
    virtual void from_string(std::string )=0;
    virtual bool operator==(Problem & x){
        return this->to_string()==x.to_string();
    }

    virtual ~Problem() {}

    friend std::ostream &operator<<(ostream& o ,Problem& p){
        o  << p.to_string() ;
        return o;
    }
    friend std::istream &operator>>(std::istream& o,Problem& p){
        std::string buf= "";
        int i =0;
        char c;
        o>>c;
        if(c!='$')
            return o;
        while (c=='$'){
            o>>c;
        }
        buf+=c;
        char pre;
        do{
            pre=c;
            o>>c;
            buf+=c;
        }while (c!='$'||pre!='$');
        buf.erase(buf.length()-1);
        buf.erase(buf.length()-1);
        p.from_string(buf);
        return o;
    }
};
#endif //PROJECT2_PROBLEM_H