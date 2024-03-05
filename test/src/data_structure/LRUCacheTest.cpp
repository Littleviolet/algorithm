#include <gtest/gtest.h>
#include <data_structure/LRUCache.h>

TEST(LRUCacheTest, case1)
{
	LRUCache* obj = new LRUCache(1);
	int param_1 = obj->get(1);
	EXPECT_EQ(param_1, -1);
	obj->put(1, 2);
	param_1 = obj->get(1);
	EXPECT_EQ(param_1, 2);
	obj->put(2, 2);
	param_1 = obj->get(1);
	EXPECT_EQ(param_1, -1);
}