#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
	if (head == nullptr)
	{
		return head;
	}
	ListNode* newHead = head;
	ListNode* prevHead = head;
	while (head->next != nullptr)
	{
		newHead = head->next;
		head->next = newHead->next;
		newHead->next = prevHead;
		prevHead = newHead;
	}
	return newHead;
}

int main()
{
	return 0;
}