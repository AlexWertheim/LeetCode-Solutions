#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* link = head->next;
    while (odd->next != nullptr && (odd->next)->next != nullptr)
    {
        // cout << odd->val << endl;
        odd->next = (odd->next)->next;
        odd = odd->next;
        if ((even->next)->next != nullptr)
        {
            even->next = (even->next)->next;
            even = even->next;
        }
    }
    even->next = nullptr;
    odd->next = link;
    return head;
}


int main()
{
    return 0;
}