//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include <map>
#include "CacheManager.h"
#include "../Problem.h"
#include "../Solution.h"
#include <fstream>
#include <mutex>
#include "../StringProblem&Solution.h"
using std::map;
namespace cache_manager{
    class FileCacheManager: public CacheManager<Problem,Solution>{
    private:
        map<std::string ,Solution* > solMap;
        mutable std::mutex mut;
    public:
        FileCacheManager();
        ~FileCacheManager() ;
        Solution *get(Problem *problem) override;

        bool isExists(Problem *problem) override;

        void set(Problem *problem, Solution *solution) override;
    };
}


#endif //PROJECT2_FILECACHEMANAGER_H
