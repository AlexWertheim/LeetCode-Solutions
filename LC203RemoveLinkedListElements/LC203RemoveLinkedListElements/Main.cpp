#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    while (head != nullptr && head->val == val)
    {
        head = head->next;
    }
    if (head == nullptr)
    {
        return head;
    }
    ListNode* t = head;
    ListNode* m = head->next;
    while (t->next != nullptr && m != nullptr)
    {
        while (m != nullptr && m->val == val)
        {
            m = m->next;
        }
        if (m == nullptr)
        {
            t->next = nullptr;
        }
        else if (m->val != val)
        {
            t->next = m;
            t = m;
            m = m->next;
        }
    }
    return head;
}

int main()
{
    return 0;
}