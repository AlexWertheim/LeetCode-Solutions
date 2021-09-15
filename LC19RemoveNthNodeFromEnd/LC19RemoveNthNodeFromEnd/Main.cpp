#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	int len = 1;
	ListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;
		len++;
	}
	int diff = len - n;
	if (head->next == nullptr && diff == 0)
	{
		return nullptr;
	}
	iter = head;
	if (n == 1)
	{
		for (int i = 0; i < diff-1; i++)
		{
			iter = iter->next;
		}
		iter->next = nullptr;
	}
	else
	{
		for (int i = 0; i < diff; i++)
		{
			iter = iter->next;
		}
		iter->val = (iter->next)->val;
		iter->next = (iter->next)->next;
	}
	return head;
}

int main()
{
	return 0;
}