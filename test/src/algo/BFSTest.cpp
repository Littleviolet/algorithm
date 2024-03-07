#include<gtest/gtest.h>
#include<algo/BFS.h>

using namespace std;

TEST(BFSTest, numIslands_case1)
{
	BFS bfs;
	vector<vector<char>> grid = {
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'}};
	EXPECT_EQ(bfs.numIslands(grid), 1);
}

TEST(BFSTest, numIslands_case2)
{
	BFS bfs;
	vector<vector<char>> grid = {
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '1'} };
	EXPECT_EQ(bfs.numIslands(grid), 3);
}