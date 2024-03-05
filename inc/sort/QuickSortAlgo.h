#ifndef QUICK_SORT_ALGO_H
#define QUICK_SORT_ALGO_H
#include <vector>
#include "SortAlgo.h"
#include "Common.h"

namespace sort
{
    class QuickSortAlgo : SortAlgo
    {
    private:
        /* data */
    public:
        void Execute(std::vector<int>& nums) override
        {
            QuickSort(nums, 0, nums.size() - 1);
        }
    private:
        void QuickSort(std::vector<int>& nums, int left, int right)
        {
            if (left >= right)
            {
                return;
            }
            int mid = PartSort(nums, left, right);
            QuickSort(nums, left, mid - 1);
            QuickSort(nums, mid + 1, right);
        }

        int PartSort(std::vector<int>& nums, int left, int right) {
            int base = nums[left];
            int start = left;
            while (left < right )
            {
                if (nums[right] < base)
                {
                    // 找到左边第一个大于base的位置
                    while(left < right && nums[left] <= base)
                    {
                        ++left;
                    }
                    utils::Swap(nums[left], nums[right]);
                } else
                {
                    --right;
                }
            }
            utils::Swap(nums[left], nums[start]);
            return left;
        }
    };
}
#endif // QUICK_SORT_ALGO_H