#include <gtest/gtest.h>
#include <backtrack/Bracktrack.h>

TEST(BackTrackTest, permuteCase)
{
	std::vector<int> nums = { 1, 2, 3 };
	BackTrackAlgo backtrack;
	auto result = backtrack.permute(nums);
	EXPECT_EQ(6, result.size());
	for (auto& item : result)
	{
		for (auto& num : item)
		{
			std::cout << num << ",";
		}
		std::cout << std::endl;
	}
}