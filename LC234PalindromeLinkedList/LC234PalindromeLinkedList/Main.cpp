#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Slow 
bool isPalindrome(ListNode* head) {
	ListNode* iter = head;
	int len = 0;
	while (iter != nullptr)
	{
		len++;
		iter = iter->next;
	}
    cout << "len is: " << len << endl;
	int n = len / 2; 
	ListNode* newHead = head;
	ListNode* prevHead = head;
	while (n > 1)
	{
		newHead = head->next;
		head->next = newHead->next;
		newHead->next = prevHead;
		prevHead = newHead;
		n--;
	}
	if (len % 2 == 0)
	{
		n = len / 2;
	}
	else
	{
		n = (len / 2)+1;
	}
	while (n > 0)
	{
		// cout << newHead->val << endl;
		newHead = newHead->next;
		n--;
	}
	n = len / 2;
	while (n > 0)
	{
		if (newHead->val == prevHead->val)
		{
			n--;
			newHead = newHead->next;
			prevHead = prevHead->next;
		}
		else
		{
			return false;
		}
	}
	return true;
}

/* Even slower
bool isPalindrome(ListNode* head) {
	vector<int> nums;
	int len = 0;
	while (head != nullptr)
	{
		nums.push_back(head->val);
		head = head->next;
		len++;
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (nums[i] != nums[(len-1) - i])
		{
			return false;
		}
	}
	return true;
}
*/


int main()
{
	return 0;
}