#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* Slow boye
bool hasCycle(ListNode* head) {
	unordered_map<ListNode*, bool> nodes;
	// int pos = 0;
	while (head != nullptr)
	{
		if (!nodes.count(head))
		{
			nodes[head] = 1;
			head = head->next;
		}
		else
		{
			return true;
		}
	}
	return false;
} */


bool hasCycle(ListNode* head) {
	ListNode* faster = head;
	while (head != nullptr && faster->next != nullptr && faster != nullptr)
	{
		head = head->next;
		faster = (faster->next)->next;
		if (head == faster)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	return 0;
}