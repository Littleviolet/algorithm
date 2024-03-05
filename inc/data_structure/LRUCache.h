#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <deque>
#include <unordered_map>

class LRUCache {
public:
	struct ListNode
	{
		int key{ 0 };
		int value{ -1 };
		ListNode* pre{ nullptr };
		ListNode* next{ nullptr };
		ListNode() {}
		ListNode(int keyPara, int valuePara) : key(keyPara), value(valuePara) {}
	};

	LRUCache(int capacity) {
		m_capacity = capacity;
		m_head.next = &m_tail;
		m_tail.pre = &m_head;
	}

	int get(int key) {
		if (m_cache.count(key) == 0)
		{
			return -1;
		}
		else
		{
			ListNode* node = m_cache.at(key);
			deleteNode(node);
			addTail(node);
			return node->value;
		}
	}

	void put(int key, int value) {
		ListNode* node = new ListNode(key, value);
		if (m_keyCount == m_capacity)
		{
			ListNode* firstNode = m_head.next;
			m_cache.erase(firstNode->key);
			m_head.next = firstNode->next;
	/*		delete firstNode;
			firstNode = nullptr;*/
			--m_keyCount;
		}
		++m_keyCount;
		m_cache[key] = node;
		addTail(node);
	}
private:
	void deleteNode(ListNode* node)
	{
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}

	void addTail(ListNode* node)
	{
		ListNode* pre = m_tail.pre;
		m_tail.pre = node;
		pre->next = node;
		node->pre = pre;
		node->next = &m_tail;
	}

	std::unordered_map<int, ListNode*> m_cache;
	ListNode m_head;
	ListNode m_tail;
	int m_capacity{ 0 };
	int m_keyCount{ 0 };
};
#endif LRU_CACHE_H