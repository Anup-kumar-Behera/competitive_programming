#include"stdio.h"
#include"stdlib.h"

typedef struct ndoe{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
void preo(node *);
void ino(node *);
void posto(node *);
void npreo(node *);
void nino(node *);
void nposto(node *);

main()
{
	int x[10]={12,8,6,69,49,3,16,1,23,9};
	int n=10;
	int i;
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	printf("\npreorder:\n");
	preo(root);
	printf("\nNon-recursive preorder:\n");
	nporeo(root);
	printf("\ninorder:\n\n");
	ino(root);
	printf("\nNon-recursive inorder:\n");
	nino(root);
	printf("\npostorder:\n");
	posto(root);
	printf("\nNon-recursive postorder:\n");
	nposto(root);
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
		p->left=create_bst(p->left,data);
	return p;
}
void preo(node *p)
{
	if(p)
	{
		printf("%d\t",p->data);
		preo(p->left);
		preo(p->right);
	}
}
void npreo(node *p)
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
		if(top==0)
			break;
		p=stack[top--];
		p=p->right;
	}
}
void ino(node *p)
{
	if(p)
	{
		ino(p->left);
		printf("%d\t",p->data);
		ino(p->right);
	}
}
void nino(node *p)
{
	node *stack[100];
	int top=0;
	while(1)
	{
		while(p)
		{
			top++;
			stack[top]=p;
			p=p->right;
		}
		if(top==0)
			break;
		p=stack[top--];
		printf("%d\t",p->data);
		p=p->right;
	}
}
void posto(node *p)
{
	if(p)
	{
		posto(p->left);
		posto(p->right);
		printf("%d\t",p->data);
	}
}
void nposto(node *p)
{
	node *stack[100];
	int top=0;
	while(1)
	{
		if(p)
		{
			top++;
			stack[top]=p;
			p=p->left;
		}
		else
		{
			if(top==0)
				break;
			else
				if(stack[top]->right==0)
				{
					p=stack[top--];
					printf("%d\t",p->data);
					if(p==stack[top]->right)
						printf("%d\t",p->data);
						stack[top--];
				}
		}
		if(top==0)
			p=stack[top]->right;
		else
			p=0;
	}
}
