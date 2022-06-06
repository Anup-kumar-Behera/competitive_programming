#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *A)
{
    if (!A)
        return NULL;
    queue<Node *> q;
    q.push(A);

    while (!q.empty())
    {
        int n = q.size();

        Node *prev = NULL;
        for (int i = 0; i < n; i++)
        {
            Node *p = q.front();
            q.pop();

            if (prev)
                prev->next = p;
            prev = p;

            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    return A;
}
int main()
{
}