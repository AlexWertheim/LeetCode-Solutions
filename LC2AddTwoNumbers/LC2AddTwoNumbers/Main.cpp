#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void InsertNode(ListNode*& l, int v)
{
    ListNode* n = new ListNode(v);
    l->next = n;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int add = 0;
    add = (l1->val) + (l2->val);
    ListNode* sum = new ListNode((add % 10));
    int carry = add > 9;
    ListNode* head = sum;
    l1 = l1->next;
    l2 = l2->next;
    while (l1 != nullptr && l2 != nullptr)
    {
        add = (l1->val) + (l2->val) + carry;
        InsertNode(head, (add % 10));
        carry = (add > 9);
        head = head->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l2 != nullptr)
    {
        add = (l2->val) + carry;
        InsertNode(head, (add % 10));
        carry = (add > 9);
        head = head->next;
        l2 = l2->next;
    }
    while (l1 != nullptr)
    {
        add = (l1->val) + carry;
        InsertNode(head, (add % 10));
        carry = (add > 9);
        head = head->next;
        l1 = l1->next;
    }
    if (carry)
    {
        InsertNode(head, 1);
    }
    return sum;
}


int main()
{
	return 0;
}