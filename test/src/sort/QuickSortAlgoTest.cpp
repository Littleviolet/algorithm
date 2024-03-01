#include <gtest/gtest.h>
#include <sort/QuickSortAlgo.h>

TEST(QuickSortTest, case1)
{
    std::vector<int> nums({ 3,5,1 });
    sort::QuickSortAlgo algo;
    algo.Execute(nums);
    //for (auto& item : nums)
    //{
    //    std::cout << item << " ";
    //}
    EXPECT_EQ(1, nums[0]);
    EXPECT_EQ(3, nums[1]);
    EXPECT_EQ(5, nums[2]);
}