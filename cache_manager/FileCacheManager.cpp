//
// Created by ori on 1/8/19.
//

#include "FileCacheManager.h"


using std::fstream;

cache_manager::FileCacheManager::FileCacheManager() {
    fstream file;
    file.open("cache_manager/solutionFile");
    //if the file doesn't exist we crete it
    if(!file){
        file.open("cache_manager/solutionFile",fstream::out|fstream::trunc);
    }
    if(file.fail())
        throw "Error in open file";
    //read from file
    Problem *p = new stringProblemAndSolution("");
    while (!file.eof()){
        Solution* x = new stringProblemAndSolution("");
        file>>*p>>*x;
        if(p->to_string()==""||x->to_string()=="")
            break;
        solMap.insert(std::make_pair(p->to_string(),x));
    }
    delete(p);
    file.close();

}

bool cache_manager::FileCacheManager::isExists(Problem *problem) {
    std::lock_guard<std::mutex> g(mut);
    return solMap.find(problem->to_string())!=solMap.end();
}


void cache_manager::FileCacheManager::set(Problem *problem, Solution *solution) {
    std::lock_guard<std::mutex> g(mut);
    solMap.insert(std::make_pair(problem->to_string(),solution));
}


Solution *cache_manager::FileCacheManager::get(Problem *problem) {
    std::lock_guard<std::mutex> g(mut);
    return solMap.at(problem->to_string());
}


cache_manager::FileCacheManager::~FileCacheManager() {
    fstream file("cache_manager/solutionFile");
    if(file.fail())
        throw "Error open file";
    int j = solMap.size()-1;
    for(auto i = solMap.begin();i!=solMap.end();++i){
        file<<"$$"<<i->first<<"$$"<<" "<<*i->second;
        if(j>0)
            file<<std::endl;
        j--;
    }
}
