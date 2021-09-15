#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode* a = head;
    ListNode* b = head->next;
    ListNode* c = a;
    head = b;
    bool first = 1;
    while (a->next != nullptr)
    {
        a->next = b->next;
        b->next = a;
        if (first)
        {
            first = 0;
        }
        else
        {
            c->next = b;
        }
        if (a->next == nullptr)
        {
            return head;
        }
        else
        {
            c = a;
            a = a->next;
            b = a->next;
        }
    }
    return head;

}

int main()
{
    cout << (0 % 5) << endl;
    return 0;
}