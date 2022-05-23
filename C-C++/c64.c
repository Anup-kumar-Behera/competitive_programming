#include"stdio.h"
#include"stdlib.h"

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
void inorder(node *);
void NRInorder(node *);

main()
{
	int x[10]={12,8,6,69,49,3,16,1,23,9};
	
	int n=10;
	node *root=0;
	int i;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	printf("\nInorder Tree traversal: \n");
	inorder(root);
	printf("\nNRInorder tree traversal: \n");
	NRInorder(root);
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

void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d\t",p->data);
		inorder(p->right);
	}
}
void NRInorder(node *p)
{
	//node *p=root;
	node *stack[100];
	int top=0;
	while(1)
	{
		while(p)
		{
			top++;
			stack[top]=p;
			p=p->left;
		}
		if(top==0)
			break;
		p=stack[top--];
		printf("%d\t",p->data);
		p=p->right;
	}
}
