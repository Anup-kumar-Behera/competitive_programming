#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
    ListNode *l1 = head1, *l2 = head2;

    if (!l1 && !l2)
        return NULL;

    if (!l1)
        return l2;
    else if (!l2)
        return l1;

    ListNode *h = NULL, *p = NULL;

    while (l1 && l2)
    {
        if (!h && l1->val <= l2->val)
        {
            h = l1;
            l1 = l1->next;
            p = h;
            p->next = NULL;
        }
        else if (!h && l1->val > l2->val)
        {
            h = l2;
            l2 = l2->next;
            p = h;
            p->next = NULL;
        }
        else if (l1->val < l2->val)
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
            p->next = NULL;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
            p->next = NULL;
        }
    }

    while (l1)
    {
        p->next = l1;
        l1 = l1->next;
        p = p->next;
        p->next = NULL;
    }

    while (l2)
    {
        p->next = l2;
        l2 = l2->next;
        p = p->next;
        p->next = NULL;
    }
    return h;
}
int main()
{
}