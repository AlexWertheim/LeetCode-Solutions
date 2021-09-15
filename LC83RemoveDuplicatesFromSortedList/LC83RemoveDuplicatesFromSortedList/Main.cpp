#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)
    {
        return head;
    }
    ListNode* tracker = head;
    ListNode* mover = head;
    bool equal = 0;
    while (mover->next != nullptr)
    {
        if ((mover->next)->val == mover->val)
        {
            mover = mover->next;
            equal = 1;
        }
        else
        {
            equal = 0;
            tracker->next = mover->next;
            mover = mover->next;
            tracker = mover;
        }
    }
    if (equal)
    {
        tracker->next = nullptr;
    }
    return head;
}

