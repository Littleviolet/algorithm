#ifndef SLIDING_WINDOWS_H
#define SLIDING_WINDOWS_H

#include <unordered_set>
#include <string>

class SlidingWindow
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		int ans = 0;
		int left = 0, right = 0;
		std::unordered_set<char> currentChars;
		while (right < s.size())
		{
			char c = s[right];
			if (currentChars.count(c) != 0)
			{
				int currenLen = right - left;
				if (currenLen > ans)
				{
					ans = currenLen;
				}
				while (left <= right && currentChars.count(c) != 0)
				{
					currentChars.erase(s[left]);
					++left;
				}
			}
			currentChars.insert(c);
			++right;
		}
		if (right - left > ans)
		{
			ans = right - left;
		}
		return ans;
	}
};

#endif // SLIDING_WINDOWS_H