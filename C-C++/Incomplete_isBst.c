#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
node *create_bst(node *,int );
int isBst(node *);

main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int i,x[n];
	printf("Enter node values: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node value: ",i+1);
		scanf("%d",&x[i]);
	}
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	int k=isBst(root);
	if(k==1)
		printf("It is a bst.\n");
	else
		printf("It's not a binary search tree.\n");
}
node *create_bst(node *p,int data)
{
	if(p==0)
	{
		p=(node *)malloc(sizeof(node));
		p->left=p->right=0;
		p->data=data;
	}
	else
	if(data>p->data)
		p->right=create_bst(p->right,data);
	else
		p->left=create_bst(p->left,data);
	return p;
}
int isBst(node *p)
{
	if(p==0)
		return 0;
	if(p->left!=0 && findMax(p->left)->data<p->data)
		
		return 1;
	else if(min(p)->data>p->data && max(p)->data<p->data)
		return 1;
}
