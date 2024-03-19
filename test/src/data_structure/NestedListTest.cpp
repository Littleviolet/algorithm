#include<gtest/gtest.h>
#include<data_structure/NestedList.h>

TEST(NestedListTest, normalCase1)
{
	std::vector<NestedInteger> nestedList = { NestedInteger({ NestedInteger(1), NestedInteger(1) }),  NestedInteger(2), NestedInteger({ NestedInteger(1), NestedInteger(1) }) };
	NestedIterator iterator(nestedList);
	std::vector<int> list;
	while (iterator.hasNext())
	{
		list.push_back(iterator.next());
	}
	ASSERT_EQ(list.size(), 5);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[2], 2);
	EXPECT_EQ(list[4], 1);
}

TEST(NestedListTest, emptyCase1)
{
	std::vector<NestedInteger> nestedList;
	NestedIterator iterator(nestedList);
	std::vector<int> list;
	while (iterator.hasNext())
	{
		list.push_back(iterator.next());
	}
	ASSERT_EQ(list.size(), 0);
}