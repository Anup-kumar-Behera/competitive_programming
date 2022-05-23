#include"stdio.h"
#include"stdlib.h"

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
void NonRecursivePreorder(node *);
void preorder(node *);

main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	
	int x[n],i;
	printf("Enter node values for bst: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node value: ",i+1);
		scanf("%d",&x[i]);
	}
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	printf("Non Recursive preorder tree traveral :\n");
		NonRecursivePreorder(root);
	printf("\nRecursive Preorder traversal:  \n");
		preorder(root);
}
void NonRecursivePreorder(node *p)
{
	node *stack[100];
	int top=0;
	while(1)
	{
		while(p)
		{
			printf("%d\t",p->data);
			top++;
			stack[top]=p;
			p=p->left;
		}
		if(top==-1)
			break;
		p=stack[top--];
		p=p->right;
	}
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

void preorder(node *root)
{
	node *p=root;
	if(p)
	{
		printf("%d\t",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
