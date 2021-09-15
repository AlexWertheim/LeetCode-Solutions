#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* detectCycle(ListNode* head) {
    if (head == nullptr)
    {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && (fast->next)->next != nullptr)
    {
        slow = slow->next;
        fast = (fast->next)->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast->next == nullptr || (fast->next)->next == nullptr)
    {
        return nullptr;
    }
    while (head != slow)
    {
        head = head->next;
        slow = slow->next;
    }
    return head;
}

int main()
{
    return 0;
}