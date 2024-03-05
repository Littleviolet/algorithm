#include <gtest/gtest.h>
#include <slidingwindow/SlidingWindow.h>

TEST(SlidingWindow, lengthOfLongestSubstringCase1)
{
	SlidingWindow window;
	int len = window.lengthOfLongestSubstring("abcabcbb");
	EXPECT_EQ(len, 3);
}

TEST(SlidingWindow, lengthOfLongestSubstringCase2)
{
	SlidingWindow window;
	int len = window.lengthOfLongestSubstring("bbbbbbb");
	EXPECT_EQ(len, 1);
}

TEST(SlidingWindow, lengthOfLongestSubstringCase3)
{
	SlidingWindow window;
	int len = window.lengthOfLongestSubstring("abcbabcbb");
	EXPECT_EQ(len, 3);
}

TEST(SlidingWindow, lengthOfLongestSubstringCase4)
{
	SlidingWindow window;
	int len = window.lengthOfLongestSubstring("pwwkew");
	EXPECT_EQ(len, 3);
}

TEST(SlidingWindow, lengthOfLongestSubstringCase5)
{
	SlidingWindow window;
	int len = window.lengthOfLongestSubstring("a");
	EXPECT_EQ(len, 1);
}