#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> v;

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            vector<int> tmp;

            for (int i = 0; i < n; i++)
            {
                TreeNode *x = q.front();
                q.pop();
                tmp.push_back(x->val);

                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            v.push_back(tmp);
        }
        return v;
    }
};
int main()
{
    Solution s;
    TreeNode *root;
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    vector<vector<int>> v = s.levelOrder(root);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

}