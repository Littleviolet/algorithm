#ifndef NESTED_LIST_H
#define NESTED_LIST_H
#include <vector>
#include <queue>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const
	{
		return m_isInteger;
	}

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const
	{
		return m_integer;
	}

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const std::vector<NestedInteger>& getList() const
	{
		return m_list;
	}

	NestedInteger(int);
	NestedInteger(const std::vector<NestedInteger>& list);

private:
	bool m_isInteger{ true };
	int m_integer{ -1 };
	std::vector<NestedInteger> m_list;
};

// 341
class NestedIterator {
public:
	NestedIterator(std::vector<NestedInteger>& nestedList) {
		saveItem(nestedList);
	}

	int next() {
		auto firstItem = items.front();
		items.pop();
		return firstItem;
	}

	bool hasNext() {
		return !items.empty();
	}
private:
	void saveItem(const std::vector<NestedInteger>& nestedList)
	{
		for (auto& item : nestedList)
		{
			if (item.isInteger())
			{
				items.push(item.getInteger());
			}
			else
			{
				saveItem(item.getList());
			}
		}
	}
	std::queue<int> items;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
#endif // NESTED_LIST_H