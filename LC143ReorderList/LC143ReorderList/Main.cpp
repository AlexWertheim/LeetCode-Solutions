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


// O(n) memory 
void reorderList(ListNode* head) {
    vector<ListNode*> nodes;
    while (head != nullptr)
    {
        nodes.push_back(head);
        head = head->next;
    }
    int i = 0, j = nodes.size() - 1;
    while (i < j)
    {
        nodes[i]->next = nodes[j];
        nodes[j]->next = nodes[i + 1];
        i++;
        j--;
    }
    nodes[i]->next = nullptr;
}

/*
// Recursive solution (slow :()
void reorderList(ListNode* head) {
    ListNode* first = head;
    if (head->next != nullptr && (head->next)->next != nullptr)
    {
        ListNode* second = head->next;
        while ((head->next)->next != nullptr)
        {
            head = head->next;
        }
        (head->next)->next = second;
        first->next = head->next;
        head->next = nullptr;
        cout << head->val << endl;
        reorderList(second);
    }
}*/

int main()
{
	return 0;
}