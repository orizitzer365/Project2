//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H
namespace cache_manager{
    template <class Problem , class Solution>
    class CacheManager{
    public:
        virtual Solution* get(Problem* problem) = 0;
        virtual bool isExists(Problem* problem) = 0;
        virtual void set(Problem* problem, Solution* solution) = 0;
    };
}
#endif //PROJECT2_CACHEMANAGER_H
