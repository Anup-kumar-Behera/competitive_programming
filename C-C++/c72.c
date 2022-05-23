#include"stdio.h"
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
node *create_bst(node *,int );
node *find(node *,int );
node *insert(node *,int );
void inorder(node *);
node *del(node *,int );
node *findMin(node *);

main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int i,x[n];
	printf("Enter node values:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node value: ",i+1);
		scanf("%d",&x[i]);
	}
	int key;
	printf("Enter key to search in the tree: ");
	scanf("%d",&key);
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	node *p=find(root,key);
	if(p!=0)
		printf("Search successful.\n");
	else
		printf("Search unsuccessful.\n");
	insert(root,key);
	printf("\nInorder traversal:\n");
	inorder(root);
	del(root,key);
	printf("\nInorder Traversal after Deletion:\n");
	inorder(root);
}
node *create_bst(node *p,int data)
{
	if(p==0)
	{
		p=(node *)malloc(sizeof(node));
		p->left=0;
		p->right=0;
		p->data=data;
	}
	else
	if(data>p->data)
		p->right=create_bst(p->right,data);
	else
		p->left=create_bst(p->left,data);
	return p;
}
node *find(node *p,int key)
{
	if(p==0)
		return NULL;
	else if(p!=0 && p->data==key)
		return p;
	else if(key>p->data)
		return find(p->right,key);
	else
		return find(p->left,key);
}
node *insert(node *p,int key)
{
	if(p==0)
	{
		p=(node *)malloc(sizeof(node));
		if(p==0)
		{
			printf("Overflow.\n");
			return ;
		}
		else
		{
			p->data=key;
			p->left=p->right=0;
		}
	}
	else
	{
		if(key<p->data)
			p->left=insert(p->left,key);
		else
			p->right=insert(p->right,key);
	}
}
void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d ",p->data);
		inorder(p->right);
	}
}
node *del(node *root,int key)
{
	node *temp;
	if(root==0)	
		printf("Eelement is not there.\n");
	else if(key>root->data)
		root->right=del(root->right,key);
	else if(key<root->data)
		root->left=del(root->left,key);
	else
	{
		if(root->left && root->right)
		{
			temp=findMin(root->left);
			root->data=temp->data;
			root->left=del(root->left,root->data);
		}
		else
		{
			temp=root;
			if(root->left==0)
				root=root->right;
			if(root->right==0)
				root=root->left;
			free(temp);
		}
	}
	return root;
}
node *findMin(node *root)
{
	if(root==0)
		return NULL;
	else if(root->left!=0)
		root=root->left;
	return root;	
}
