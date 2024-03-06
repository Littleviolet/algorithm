#include <gtest/gtest.h>
#include <data_structure/LRUCache.h>

TEST(LRUCacheTest, case1)
{
	LRUCache* obj = new LRUCache(2);
	int param_1 = obj->get(2);
	EXPECT_EQ(param_1, -1);
	obj->put(1, 2);
	param_1 = obj->get(1);
	EXPECT_EQ(param_1, 2);
	obj->put(2, 6);
	param_1 = obj->get(2);
	EXPECT_EQ(param_1, 6);
}

TEST(LRUCacheTest, case2)
{
	LRUCache* obj = new LRUCache(2);
	int param_1 = obj->get(2);
	EXPECT_EQ(param_1, -1);
	obj->put(2, 1);
	obj->put(1, 2);
	obj->put(2, 3);
	obj->put(4, 1);
	param_1 = obj->get(1);
	EXPECT_EQ(param_1, -1);
	param_1 = obj->get(2);
	EXPECT_EQ(param_1, 3);
}