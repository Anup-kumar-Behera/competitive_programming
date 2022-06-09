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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p = head, *pre = NULL, *next = pre;

        while (p)
        {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
};
int main()
{
    ListNode *head = new ListNode(12);
    head->next = new ListNode(13);
    head->next->next = new ListNode(14);
    head->next->next->next = new ListNode(15);

    Solution s;
    head = s.reverseList(head);
}