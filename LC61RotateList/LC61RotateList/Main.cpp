#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr)
    {
        return head;
    }
    int len = 1;
    ListNode* t = head;
    ListNode* u = head;
    while (t->next != nullptr)
    {
        t = t->next;
        len++;
    }
    int diff = (k % len);
    if (diff == 0)
    {
        return head;
    }
    t->next = head;
    for (int i = 0; i < (len - diff) - 1; i++)
    {
        u = u->next;
    }
    head = u->next;
    u->next = nullptr;
    return head;
}

int main()
{
    return 0;
}