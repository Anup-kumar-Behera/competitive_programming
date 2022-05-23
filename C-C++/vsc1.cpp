#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};
node *create_bst(node *,int );
void preorder(node *);

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int i,x[n];
    cout<<"Enter the array elements:\n";
    for(i = 0; i < n;  i++)
    {
        cout<<"Enter "<<i+1<<" array element: ";
        cin>>x[i];
    }
    node *root = 0;
    for(i = 0; i < n ; i++)
        root = create_bst(root,x[i]);
    preorder(root);
    return 0;
}
node *create_bst(node *root,int data)
{
    if(root == 0)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = 0;
    }
    else
    {
        if(data > root->data)
            root->right = create_bst(root->right,data);
        else
            root->left = create_bst(root->left,data);
                    
    }
    return root;
}
void preorder(node *root)
{
    if(root)
    {
        cout<<" "<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}