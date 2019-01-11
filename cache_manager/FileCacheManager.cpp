//
// Created by ori on 1/8/19.
//

#include <fstream>
#include "FileCacheManager.h"
using std::fstream;
template<class Problem, class Solution>
cache_manager::FileCacheManager<Problem, Solution>::FileCacheManager() {
    fstream file("cache_manager/solutionFile");
    std::string pro,sol;
    if(file.fail())
        throw "Error in open file";
    while (!file.eof()){
        file>>pro>>sol;
        //set()
    }
}

template<class Problem, class Solution>
bool cache_manager::FileCacheManager<Problem, Solution>::isExists(Problem *problem) {
    return solMap.find(problem)!=solMap.end();
}

template<class Problem, class Solution>
void cache_manager::FileCacheManager<Problem, Solution>::set(Problem *problem, Solution *solution) {
    solMap.insert(std::make_pair(problem,solution));
}

template<class Problem, class Solution>
Solution *cache_manager::FileCacheManager<Problem, Solution>::get(Problem *problem) {
    return solMap.at(problem);
}

template<class Problem, class Solution>
cache_manager::FileCacheManager<Problem, Solution>::~FileCacheManager() {
    fstream file("cache_manager/solutionFile");
    if(file.fail())
        throw "Error open file";
    for(auto i = solMap.begin();i!=solMap.end();++i){
        file<<i->first->to_string()<<" "<<i->second->to_string()<<std::endl;
    }
}
