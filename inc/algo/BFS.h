#ifndef BFS_H
#define BFS_H
#include <queue>
#include <vector>

class BFS
{
public:
	BFS() = default;
	~BFS() = default;

    int numIslands(std::vector<std::vector<char>>& grid) 
	{
		int number = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if (grid[i][j] != '1')
				{
					continue;
				}
				++number;
				std::queue<std::pair<int, int>> neighbor;
				neighbor.push(std::make_pair(i, j));
				while (!neighbor.empty())
				{
					auto pos = neighbor.front();
					neighbor.pop();
					int r = pos.first;
					int c = pos.second;
					if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size() || grid[r][c] != '1')
					{
						continue;
					}
					grid[r][c] = '0';
					neighbor.push(std::make_pair(r - 1, c));
					neighbor.push(std::make_pair(r + 1, c));
					neighbor.push(std::make_pair(r, c - 1));
					neighbor.push(std::make_pair(r, c + 1));
				}
			}
		}
		return number;
    }
private:

};
#endif // !BFS_H
