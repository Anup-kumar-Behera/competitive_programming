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
    void paths(TreeNode *root, int &s, unordered_set<int> &st)
    {
        if (!root)
            return;

        s += root->val;

        if (!root->left && !root->right)
        {
            st.insert(s);
        }
        paths(root->left, s, st);
        paths(root->right, s, st);

        s -= root->val;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        unordered_set<int> s;

        int sum = 0;
        paths(root, sum, s);

        return (s.find(targetSum) != s.end());
    }
};
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    Solution s;
    int targetSum = 18;
    cout<<s.hasPathSum(root, targetSum)<<endl;
}