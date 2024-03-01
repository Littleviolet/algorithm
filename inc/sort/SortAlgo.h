#ifndef SORT_ALGO_H
#define SORT_ALGO_H
#include <vector>
namespace sort
{
    class SortAlgo
    {
    public:
        SortAlgo(/* args */) = default;
        ~SortAlgo() = default;
        virtual void Execute(std::vector<int>& nums) = 0;
    };
}
#endif