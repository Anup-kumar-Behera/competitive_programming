#include"stdio.h"
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
int search(node *,int );

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
	int key;
	printf("Enter item to search in bst: ");
	scanf("%d",&key);
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	int s=search(root,key);
	if(s==1)
		printf("Search successful.\n");
	else
		printf("Search Unsuccessful.\n");
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
int search(node *p,int x)
{
	if(p==0)
		return 0;
	else if(p->data==x)
		return 1;
	else
		return (search(p->left,x)||search(p->right,x));
}
