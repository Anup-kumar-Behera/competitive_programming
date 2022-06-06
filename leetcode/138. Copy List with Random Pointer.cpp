#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *newHead = NULL;

    if (!head)
        return head;

    Node *p = head, *q = NULL;

    unordered_map<Node *, Node *> mp;

    while (p)
    {
        if (mp.find(p) == mp.end())
        {
            mp[p] = new Node(p->val);
        }

        if (p->random)
        {
            if (mp.find(p->random) == mp.end())
                mp[p->random] = new Node(p->random->val);
        }

        p = p->next;
    }
    p = head;
    while (p)
    {
        if (!newHead)
        {
            Node *tmp = mp[p];

            if (p->random)
                tmp->random = mp[p->random];
            newHead = tmp;
            q = newHead;
        }
        else
        {
            Node *tmp = mp[p];

            if (p->random)
                tmp->random = mp[p->random];
            q->next = tmp;
            q = q->next;
        }
        p = p->next;
    }
    return newHead;
}
int main()
{
}