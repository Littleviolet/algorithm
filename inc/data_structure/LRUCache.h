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
			moveToTail(node);
			return node->value;
		}
	}

	void put(int key, int value) {
		if (m_cache.count(key) == 0)
		{
			ListNode* node = new ListNode(key, value);
			if (m_keyCount == m_capacity)
			{
				ListNode* firstNode = m_head.next;
				m_cache.erase(firstNode->key);
				m_head.next = firstNode->next;
				firstNode->next->pre = &m_head;
				delete firstNode;
				firstNode = nullptr;
				--m_keyCount;
			}
			addTail(node);
			m_cache[key] = node;
			++m_keyCount;
		}
		else if (m_cache.count(key) != 0)
		{
			ListNode* node = m_cache.at(key);
			node->value = value;
			moveToTail(node);
		}
	}
private:
	void deleteNode(ListNode* node)
	{
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}

	void addTail(ListNode* node)
	{
		node->next = &m_tail;
		node->pre = m_tail.pre;
		m_tail.pre->next = node;
		m_tail.pre = node;
	}

	void moveToTail(ListNode* node)
	{
		deleteNode(node);
		addTail(node);
	}

	std::unordered_map<int, ListNode*> m_cache;
	ListNode m_head;
	ListNode m_tail;
	int m_capacity{ 0 };
	int m_keyCount{ 0 };
};
#endif // LRU_CACHE_H