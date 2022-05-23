#include"stdio.h"
#include<stdlib.h>

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
void iterative_Preorder(node *);
int HeightOfTree(node *);
void inorder(node *);
void NonRecursivePreorder(node *);
void posto(node *);
void nposto(node *);
	
 main()
 {
 
	int x[10]={12,8,6,69,49,3,16,1,23,9};
 	node *root=0;
 	int n=10,i;
 	
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	printf("Iterative Preorder: \n");
	iterative_Preorder(root);
	printf("\nNon Recursive Preorder: \n");
	NonRecursivePreorder(root);
	printf("\nInorder :\n");
	inorder(root);
	printf("\n");
	printf("\npostorder: \n");
	posto(root);
	printf("\nNon-recursive postorder:\n");
	nposto(root);
	printf("\n");
//	int h=HeightOfTree(root);
//	printf("Height Of the tree is: %d \n",h);
 }
 
 node *create_bst(node *p,int data)
 {
 	if(p==0)
 	{
 		p=(node *)malloc(sizeof(node));
 		p->left=0;
 		p->data=data;
 		p->right=0;
	}
	else
	if(data>p->data)
		p->right=create_bst(p->right,data);
	else
		p->left=create_bst(p->left,data);
	return p;
 }
 
 void iterative_Preorder(node *root)
 {
 	node *p=root;
 	node *save[100];
 	int top=0;
 	if(p==0)
 		printf("Underflow.\n");
 	
 	save[top++] = p;
 	while(top != 0)
 	{
 		p = save[--top];
 		printf("%d ",p->data);
 		
 		if(p->right !=0 )
 			save[top++] = p->right;
 		if(p->left != 0)
 			save[top++] = p->left;
	}
 }
 
 void inorder(node *root)
 {
 	node *p=root;
 	if(p)
 	{
 		inorder(p->left);
 		printf("%d ",p->data);
 		inorder(p->right);
	}
 }
 
 int HeightOfTree(node *root)
 {
 	node *p=root;
 	int a=0,b=0;
 	while(p != 0)
 	{
 		a=1+HeightOfTree(p->left);
 		b=1+HeightOfTree(p->right);
	}
	if(a>b)
		return a;
	else
		return b;
 }
 void NonRecursivePreorder(node *p)
 {
 	node *stack[100];
 	int top=0;
 	while(1)
 	{
 		while(p)
 		{
 			printf("%d ",p->data);
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
