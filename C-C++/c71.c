// MINIMUM IN BST

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
int min(node *);
int max(node *);

main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int i,x[n];
	node *root=0;
	
	printf("Enter node values:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node values: ",i+1);
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	int mn=min(root);
		printf("\nMin value in bst is: %d \n",mn);
	int mx=max(root);
		printf("\nMax value in bst is: %d \n",mx);
}
node *create_bst(node *root,int data)
{
	if(root==0)
	{
		root=(node *)malloc(sizeof(node));
		root->left=0;
		root->right=0;
		root->data=data;
	}
	else
	if(data>root->data)
		root->right=create_bst(root->right,data);
	else
		root->left=create_bst(root->left,data);
	return root;
}
int min(node *root)
{
	if(root==0)
		return 0;
	else if(root!=0 && root->left==0)
		return root->data;
	else
		return (min(root->left));
}
int max(node *root)
{
	if(root==0)
		return 0;
	else if(root!=0 && root->right==0)
		return root->data;
	else
		return max(root->right);
}
