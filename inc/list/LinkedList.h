#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace list
{
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class List
	{
	public:
		List() = default;
		~List() = default;
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
		{
            ListNode* node1 = list1;
            ListNode* node2 = list2;
            ListNode* newList = new ListNode(-1);
            ListNode* current = newList;
            while (node1 != nullptr && node2 != nullptr) {
                if (node1->val <= node2->val) {
                    current->next = node1;
                    node1 = node1->next;
                }
                else {
                    current->next = node2;
                    node2 = node2->next;
                }
                current = current->next;
            }
            current->next = (node1 != nullptr) ? node1 : node2;
            ListNode* ret = newList->next;
            newList = nullptr;
            delete newList;
            return ret;
		}

        ListNode* reverseList(ListNode* head)
        {
            ListNode* pre = nullptr;
            while (head != nullptr)
            {
                ListNode* next = head->next;
                head->next = pre;
                pre = head;
                head = next;
            }
            return pre;
        }
	};
}
#endif // !LINKED_LIST_H
