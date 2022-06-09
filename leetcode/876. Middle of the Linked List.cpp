#include <bits/stdc++.h>
using namespace std;

// * Definition for singly-linked list.
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *a = head, *b = head;

        while (a && a->next)
        {
            a = a->next->next;
            b = b->next;
        }
        return b;
    }
};
int main()
{
    ListNode *head;
    head = new ListNode(12);
    head->next = new ListNode(1);
    head->next->next = new ListNode(8);

    Solution s;
    cout<<s.middleNode(head)->val<<endl;
}