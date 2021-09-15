#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
	{
		return l2;
	}
	else if (l2 == nullptr)
	{
		return l1;
	}
	ListNode* first = l1;
	ListNode* second = l2;
	ListNode* head = nullptr;
	if (first->val <= second->val)
	{
		head = l1;
	}
	else
	{
		head = l2;
	}
	while (first != nullptr && second != nullptr)
	{
		if (first->val <= second->val)
		{
			first = first->next;
			if (first == nullptr || first->val > second->val)
			{
				l1->next = l2;
				l1 = first;
			}
			else
			{
				l1 = l1->next;
			}
		}
		else
		{
			second = second->next;
			if (second == nullptr || second->val >= first->val)
			{
				l2->next = l1;
				l2 = second;
			}
			else
			{
				l2 = l2->next;
			}
		}
	}
	return head;
}

int main()
{
	return 0;
}