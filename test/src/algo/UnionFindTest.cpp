#include <gtest/gtest.h>
#include <algo/UnionFind.h>

using namespace std;

TEST(UnionFindTest, numIslands)
{
	UnionFindIsland unionFind;
	vector<vector<char>> grid = {
	{'1', '1', '1', '1', '0'},
	{'1', '1', '0', '1', '0'},
	{'1', '1', '0', '0', '0'},
	{'0', '0', '0', '0', '0'} };
	EXPECT_EQ(unionFind.numIslands(grid), 1);
}

TEST(UnionFindTest, numIslands_case2)
{
	UnionFindIsland unionFind;
	vector<vector<char>> grid = {
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '1'} };
	EXPECT_EQ(unionFind.numIslands(grid), 3);
}

TEST(UnionFindTest, numIslands_case3)
{
	UnionFindIsland unionFind;
	vector<vector<char>> grid = { 
		{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1'},
		{'1', '0', '1', '0', '1', '1', '1', '1', '1', '1'},
		{'0', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
		{'1', '1', '0', '1', '1', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '1', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
		{'0', '0', '1', '0', '0', '1', '1', '1', '1', '0'},
		{'1', '0', '1', '1', '1', '0', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0'} };
	EXPECT_EQ(unionFind.numIslands(grid), 2);
}