#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* slow = head;
    int diff = right - left;
    while (left > 2)
    {
        slow = slow->next;
        left--;
        right--;
    }
    ListNode* hitch = new ListNode(0);
    if (left != 1)
    {
        hitch = slow;
        slow = slow->next;
    }
    ListNode* fast = slow;
    ListNode* connect = slow;
    // fast = fast->next; 
    while (diff > 0)
    {
        fast = slow->next;
        slow->next = fast->next;
        fast->next = connect;
        connect = fast;
        diff--;
    }
    if (left != 1)
    {
        hitch->next = connect;
        return head;
    }
    return connect;
}

int main()
{
    return 0;
}