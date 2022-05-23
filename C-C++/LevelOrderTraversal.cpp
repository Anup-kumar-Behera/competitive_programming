#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node *left,*right = NULL;
}node;

node *newNode(int data)
{
	node *newnode = new node();
	newnode->data = data;
	newnode->left = newnode->right = 0;
	
	return new node;
}
node *bst(node *root,int data)
{
	if(root == 0)
	{
		root = newNode(data);
	}
	else
		if(data <= root->data)
			root->left = bst(root->left,data);
		else
			root->right = bst(root->right,data);
			
	return root;
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void lot(node *root)
{
	if(root == 0) return;
	queue<node*> q;
	
	q.push(root);
	while(!q.empty())
	{
		node *current = q.front();
		cout<<current->data<<" ";
		
		if(current->left != 0)  q.push(current->left);
		if(current->right != 0)  q.push(current->right);
		
		q.pop();
	}
}

int main()
{
	node *root = 0;
	root = bst(root,15); root = bst(root,10); root = bst(root,20);
	root = bst(root,25); root = bst(root,8 ); root = bst(root,12);
		
	cout<<endl;
	inorder(root);
	cout<<endl;
	lot(root);
	cout<<endl;
	return 0;
}
