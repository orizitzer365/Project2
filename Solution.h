//
// Created by ori on 1/11/19.
//

#ifndef PROJECT2_SOLUTION_H
#define PROJECT2_SOLUTION_H

#include <string>
using std::istream;
using std::ostream;
class Solution {
public:
    virtual std::string to_string()=0;
    virtual void from_string(std::string )=0;
    friend std::ostream &operator<<(std::ostream &o, Solution &p) {
        o << "$$" << p.to_string() << "$$";
        return o;
    }
    virtual ~Solution(){}
    friend std::istream &operator>>(std::istream &in, Solution &p) {
        std::string buf = "";
        char c;
        in>>c;
        if(c!='$')
            return in;
        while (c=='$'){
            in>>c;
        }
        buf+=c;
        char pre;
        do {
            pre = c;
            in>>c;
            buf += c;
        } while (c != '$' || pre != '$');
        buf.erase(buf.length()-1);
        buf.erase(buf.length()-1);
        p.from_string(buf);
        return in;
    }
};

#endif //PROJECT2_SOLUTION_H
