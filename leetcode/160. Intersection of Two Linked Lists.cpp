#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int l1 = 0, l2 = 0;
    ListNode *p = headA;

    while (p)
    {
        l1++;
        p = p->next;
    }
    p = headB;

    while (p)
    {
        l2++;
        p = p->next;
    }
    ListNode *p1 = NULL, *q1 = NULL;
    p1 = headA;
    q1 = headB;

    if (l1 > l2)
    {
        int d = l1 - l2;
        for (int i = 0; i < d; i++)
            p1 = p1->next;
    }
    else if (l1 < l2)
    {
        int d = l2 - l1;
        for (int i = 0; i < d; i++)
            q1 = q1->next;
    }

    while (p1 != NULL && q1 != NULL)
    {
        if (p1 == q1)
            return p1;
        p1 = p1->next, q1 = q1->next;
    }
    return NULL;
}
int main()
{
    
}