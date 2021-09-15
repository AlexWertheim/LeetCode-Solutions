#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}  
};

// Clever "sentinel node" approach
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)
    {
        return head;
    }
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;
    ListNode* slowRunner = sentinel;
    ListNode* fastRunner = head;
    while (fastRunner != nullptr)
    {
        if (fastRunner->next == nullptr || (fastRunner->next != nullptr && fastRunner->val != (fastRunner->next)->val))
        {
            slowRunner->next = fastRunner;
            slowRunner = slowRunner->next;
            fastRunner = fastRunner->next;
        }
        else
        {
            while (fastRunner->next != nullptr && fastRunner->val == (fastRunner->next)->val)
            {
                fastRunner = fastRunner->next;
            }
            fastRunner = fastRunner->next;
        }
    }
    slowRunner->next = fastRunner;
    return sentinel->next;
}


/*Clumsy approach which requires separate case for removing repeats at the head
ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
        {
            return head;
        }
        bool distinct = 1, found = 0;
        while(head->next != nullptr && !found)
        {
            if(head->val == (head->next)->val)
            {
                distinct = 0;
                head = head->next;
            }
            else if(head->val != (head->next)->val && !distinct)
            {
                distinct = 1;
                head = head->next;
            }
            else if(head->val != (head->next)->val && distinct)
            {
                found = 1;
            }
        }
        if(!found)
        {
            if(distinct)
            {
                return head;
            }
            else
            {
                return nullptr;
            }
        }
        ListNode* slowRunner = head;
        ListNode* fastRunner = head->next;
        while(fastRunner != nullptr)
        {
            if(fastRunner->next == nullptr || (fastRunner->next != nullptr && fastRunner->val != (fastRunner->next)->val))
            {
                slowRunner->next = fastRunner;
                slowRunner = slowRunner->next;
                fastRunner = fastRunner->next;
            }
            else
            {
                while(fastRunner->next != nullptr && fastRunner->val == (fastRunner->next)->val)
                {
                    fastRunner = fastRunner->next;
                }
                fastRunner = fastRunner->next;
            }
        }
        slowRunner->next = fastRunner;
        return head;
    }

*/

int main()
{
	return 0;
}