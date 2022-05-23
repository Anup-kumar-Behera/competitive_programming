#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *left,*right;
};
node *root = 0;
node *create_bst(node *,int );
void inorder(node *);

int main()
{
	int n;
	cout<<"Enter number of elements :"; 
	cin>>n;
	int i,x[n];
	
	cout<<"Enter array elements: "<<endl;
	for(i = 0; i < n; i++)
	{
		cout<<"Enter "<<i+1<<" array element: ";
		cin>>x[i];
	}
	for(i = 0; i < n; i++)
		root = create_bst(root,x[i]);
	inorder(root);
	
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
	if(data > root->data)
		root->right = create_bst(root->right,data);
	else
		root->left = create_bst(root->left,data);
	
	return root;
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<" "<<root->data;
		inorder(root->right);
	}
}
