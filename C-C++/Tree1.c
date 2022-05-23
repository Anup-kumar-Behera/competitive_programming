#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
node *create_bst(node *,int );
void preorder(node *);
void inorder(node *);
//void PreorderNonRecursive(node *);
void MorrisTraversal(node *);

int main()
{
	int n;
	printf("Enter the no of nodes: ");;
	scanf("%d",&n);
	int x[n];
	int i;
	node *root=0;
	printf("Enter node values: \n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	preorder(root);
		printf("\n");
	inorder(root);
		printf("\n");
	MorrisTraversal(root);
		printf("\n");
	return 0;
}
node *create_bst(node *root,int data)
{
	if(root==0)
	{
		root=(node *)malloc(sizeof(node));
		root->left=0;
		root->data=data;
		root->right=0;
	}
	else 
	if(data>root->data)
		root->right=create_bst(root->right,data);
	else 
		root->left=create_bst(root->left,data);
	return root;
}
void preorder(node *root)
{
	if(root!=0)
	{
		printf("%d \t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *p)
{
	if(p!=0)
	{
		inorder(p->left);
		inorder(p->right);
		printf("%d \t",p->data);
	}
}
void MorrisTraversal(node *root)
{
	node *p = root;
	while(p != 0)
	{
		if(!p->left)
		{
			printf("%d ",p->data);
			p = p->right;
		}
		else
		{
			node *pre = p->left;
			while(pre->right != 0 && p->right != p)
				pre = pre->right;
				
			if(pre->right == 0)
			{
				pre->right = p;
				p = p->left;		
			}
			else
			{
				pre->right = 0;
				printf("%d ",p->data);
				p = p->right;
			}
		}
	}
}
