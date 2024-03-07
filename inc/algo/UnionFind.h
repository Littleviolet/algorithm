#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <vector>

class UnionFind
{
public:
	UnionFind() = default;
	~UnionFind() = default;
	UnionFind(const std::vector<std::vector<char>>& grid)
	{
		int n = grid[0].size();
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int pos = i * n + j;
				m_root.push_back(pos);
				if (grid[i][j] == '1')
				{
					++m_count;
				}
			}
		}
	}

	void Connect(int p, int q)
	{
		int rootP = Find(p);
		int rootQ = Find(q);
		if (rootP != rootQ)
		{
			m_root[rootP] = rootQ;
			--m_count;
		}
	}

	int Find(int p)
	{
		if (m_root[p] != p)
		{
			m_root[p] = Find(m_root[p]);
		}
		return m_root[p];
	}

	int GetCount() const
	{
		return m_count;
	}

private:
	int m_count{ 0 };
	std::vector<int> m_root;
};

class UnionFindIsland {
public:
	int numIslands(std::vector<std::vector<char>>& grid) {
		UnionFind unionFind(grid);
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] != '1')
				{
					continue;
				}
				if (i - 1 >= 0 && grid[i - 1][j] == '1')
				{
					unionFind.Connect(i * n + j, (i - 1) * n + j);
				}
				if (j - 1 >= 0 && grid[i][j - 1] == '1')
				{
					unionFind.Connect(i * n + j, i * n + j - 1);
				}
			}
		}
		return unionFind.GetCount();
	}
};
#endif // UNION_FIND_H