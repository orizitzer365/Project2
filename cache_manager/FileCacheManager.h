//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include <unordered_map>
#include "CacheManager.h"
#include "../Problem.h"
#include "../Solution.h"
using std::unordered_map;
namespace cache_manager{
    template <class Problem,class Solution>
    class FileCacheManager: CacheManager<Problem,Solution>{
    private:
        unordered_map<Problem* ,Solution* > solMap;
    public:
        FileCacheManager();
        virtual ~FileCacheManager();
        Solution *get(Problem *problem) override;

        bool isExists(Problem *problem) override;

        void set(Problem *problem, Solution *solution) override;
    };
}
//this is the hash function for Problem
namespace std{
    template <>
    struct hash<Problem>{
        int operator()(Problem* p ){
            return hash<string>()(p->to_string());
        }
    };
}

#endif //PROJECT2_FILECACHEMANAGER_H
