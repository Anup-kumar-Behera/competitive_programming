#include"stdio.h"
#include<stdlib.h>

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
void PreorderUsingStack(node *);
int isEmptyStack();
void pop();
void push(int );
	int s[50];
	int top=-1;

 main()
 {
 	int n;
 	printf("Enter number of nodes: ");
 	scanf("%d",&n);
 	int i,x[n];
 	node *root=0;
 	
 	printf("Enter node values: \n");
 	for(i=0;i<n;i++)
 	{
 		printf("Enter %d node value: ",i+1);
 		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	PreorderUsingStack(root);
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
 }
 
 void PreorderUsingStack(node *p)
 {
 	while(1)
 	{
 		while(p)
 		{
 			printf("%d ",p->data);
 			push(p);
 			p=p->left;
		}
		if(isEmptyStack())
			break;
		p=pop();
		p=p->right;
	}
 }
 
 void push(int data)
 {
 	if(top==-1)
 		top++;
 	s[top]=data;
 }
 
 void pop()
 {
 	top--;	
 }
 
 int isEmptyStack()
 {
 	if(top==-1)
 	return 1;
 }
