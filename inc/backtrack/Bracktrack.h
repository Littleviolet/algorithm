#ifndef BACKTRACK_H
#define BACKTRACK_H
#include <vector>
#include <Common.h>

class BackTrackAlgo
{
public:
	BackTrackAlgo() = default;
	~BackTrackAlgo() = default;

	std::vector<std::vector<int>> permute(std::vector<int>& nums) 
	{
		std::vector<std::vector<int>> res;
		BackTrack(nums, res, 0, nums.size());
		return res;
	}

	void BackTrack(std::vector<int>& nums, std::vector<std::vector<int>>& res, int index, int length)
	{
		if (index == length)
		{
			res.push_back(nums);
			return;
		}
		for (int i = index; i < length; ++i)
		{
			utils::Swap(nums[index], nums[i]);
			BackTrack(nums, res, index + 1, length);
			utils::Swap(nums[index], nums[i]);
		}
	}
};
#endif // !BACKTRACK_H
