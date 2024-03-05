#include <gtest/gtest.h>
#include <list/LinkedList.h>

using namespace list;

ListNode* CreateList(const std::vector<int>& nums)
{
	if (nums.empty())
	{
		return nullptr;
	}
}

TEST(ListTest, reverseListCase1)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	List list;
	head = list.reverseList(head);
	ASSERT_TRUE(head != nullptr);
	EXPECT_EQ(head->val, 2);
	ASSERT_TRUE(head->next != nullptr);
	EXPECT_EQ(head->next->val, 1);
}