#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
node *create_bst(node *,int );

main()
{
	int n;
	printf("Enter the no of nodes: ");
	scanf("%d",&n);
	
	int i,x[n];
	node *root=0;
	printf("Enter node values:  \n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
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
	if(data<p->data)
		p->left=create_bst(p->left,data);
	else
		p->right=create_bst(p->right,data);
}
void iterative_preorder(node *root,n)
{
	node *p=root;
	int s[n],top=-1;
	printf("%d ",p->data);
	push(p->data);
	while(p!=0)
	{
		p=p->left;
	}
	if(p==0 && top==-1)
		printf("Thats it.\n");
	else
	{
		s[top]=pop();
		
	}
		
}
