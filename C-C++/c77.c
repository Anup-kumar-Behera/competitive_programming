#include<stdio.h>
#include<stdlib.h>
typedef struct AvlNode{
	struct node *left;
	int data;
	struct node *right;
	int height;
}AvlNode;

AvlNode *create_bst(node *,int );

main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int i,x[i];
	printf("Enter node values: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node value: ",i+1);
		scanf("%d",&x[i]);
	}
	AvlNode *root=0;
	for(i=0;i<n;i++)	
		root=create_bst(root,x[i]);
	
}
AvlNode *create_bst(AvlNode *p,int )
{
	
}
