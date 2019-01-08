//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include <map>
#include "CacheManager.h"
using std::map;
namespace cache_manager{
    template <class Problem,class Solution>
    class FileCacheManager: CacheManager<Problem,Solution>{
    private:
        map<Problem* ,Solution* > solMap;
    public:
    private:
    public:
        FileCacheManager();

        virtual ~FileCacheManager();

    private:
        Solution *get(Problem *problem) override;

        bool isExists(Problem *problem) override;

        void set(Problem *problem, Solution *solution) override;
    };
}


#endif //PROJECT2_FILECACHEMANAGER_H
