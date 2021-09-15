#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Slow
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
{
    int lenA = 0, lenB = 0;
    ListNode* a = headA;
    ListNode* b = headB;
    while (a->next != nullptr)
    {
        a = a->next;
        lenA++;
    }
    a = headA;
    while (b->next != nullptr)
    {
        b = b->next;
        lenB++;
    }
    b = headB;
    if (lenA > lenB)
    {
        while ((lenA - lenB) > 0)
        {
            a = a->next;
            lenA--;
        }
        while (lenA)
        {
            if (a == b)
            {
                return a;
            }
            else
            {
                a = a->next;
                b = b->next;
                lenA--;
            }
        }
    }
    else
    {
        while ((lenB - lenA) > 0)
        {
            b = b->next;
            lenB--;
        }
        while (lenB)
        {
            if (a == b)
            {
                return a;
            }
            else
            {
                a = a->next;
                b = b->next;
                lenB--;
            }
        }
    }
    return nullptr;
}

/*Even slower somehow
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if(headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }
    int lenA = 1, lenB = 1;
    ListNode* a = headA;
    ListNode* b = headB;
    while (a->next != nullptr || b->next != nullptr)
    {
        if(a->next != nullptr)
        {
            a = a->next;
            lenA++;
        }
        if(b->next != nullptr)
        {
            b = b->next;
            lenB++;
        }

    }
    if(a != b)
    {
        return nullptr;
    }
    if (lenA > lenB)
    {
        while ((lenA - lenB) > 0)
        {
            headA = headA->next;
            lenA--;
        }
        while (lenA)
        {
            if (headA == headB)
            {
                return headA;
            }
            else
            {
                headA = headA->next;
                headB = headB->next;
                lenA--;
            }
        }
    }
    else
    {
        while ((lenB - lenA) > 0)
        {
            headB = headB->next;
            lenB--;
        }
        while (lenB)
        {
            if (headA == headB)
            {
                return headA;
            }
            else
            {
                headA = headA->next;
                headB = headB->next;
                lenB--;
            }
        }
    }
    return nullptr;
}*/



int main()
{
	return 0;
}