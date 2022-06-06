#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;

    if (l1 && !l2)
        return l1;
    if (!l1 && l2)
        return l2;

    ListNode *p = l1, *q = l2;
    int c = 0;

    ListNode *head = NULL, *tmp;
    while (p && q)
    {
        int x = p->val + q->val + c;
        if (x >= 10)
            x = x % 10, c = 1;
        else
            c = 0;
        if (!head)
        {
            head = new ListNode(x);
            tmp = head;
        }
        else
        {
            ListNode *t = new ListNode(x);
            tmp->next = t;
            tmp = tmp->next;
        }
        p = p->next, q = q->next;
    }
    while (p)
    {
        int x = p->val + c;
        if (x >= 10)
            x = x % 10, c = 1;
        else
            c = 0;
        ListNode *t = new ListNode(x);
        tmp->next = t;
        tmp = tmp->next;
        p = p->next;
    }
    while (q)
    {
        int x = q->val + c;
        if (x >= 10)
            x = x % 10, c = 1;
        else
            c = 0;
        ListNode *t = new ListNode(x);
        tmp->next = t;
        tmp = tmp->next;
        q = q->next;
    }
    if (c > 0)
    {
        ListNode *t = new ListNode(c);
        tmp->next = t;
    }

    return head;
}

int main()
{
}