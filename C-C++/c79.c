#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *left,*right;
	int data;
}node;
node *create_bst(node *,int );
void preorder(node *);
void pre(node *);
void inorder(node *);
void in(node *);
void post(node *);
void postorder(node *);

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
	
	printf("\nRecursive preorder: \n");
	pre(root);
	printf("\nPreorder traversal: \n");
	preorder(root);
	printf("\nRecursive inorder: \n");
	in(root);
	printf("\nInorder traversal: \n");
	inorder(root);
	printf("\nRecursive postorder: \n");
	post(root);
	printf("\nPostorder traversal: \n");
	postorder(root);
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
void preorder(node *root)
{
	node *stack[100];
	int top=1;
	stack[1]=NULL;
	node *p=root;
	while(p!=0)
	{
		printf("%d\t",p->data);
		if(p->right!=0)
		{
			top++;
			stack[top]=p->right;
		}
		if(p->left!=0)
		{
			p=p->left;
		}
		else
		
		{
			
			p=stack[top];
			top--;
		}
	}
}
void pre(node *p)
{
	if(p)
	{
		printf("%d\t",p->data);
		pre(p->left);
		pre(p->right);
	}
}
void in(node *p)
{
	if(p)
	{
		in(p->left);
		printf("%d\t",p->data);
		in(p->right);
	}
}
void inorder(node *root)
{
	node *stack[100];
	int top=1;
	stack[1]=NULL;
	node *p=root;
	while(p!=0)
	{
		top++;
		stack[top]=p;
		p=p->left;
	}
	p=stack[top];
		top--;
	while(p!=0)
	{
		printf("%d\t",p->data);
		if(p->right!=0)
		{
			p=p->right;
			while(p!=0)
			{
				top++;
				stack[top]=p;
				p=p->left;
			}
		}
		p=stack[top];
		top--;
	}
} 
void post(node *p)
{
	if(p)
	{
		post(p->left);
		printf("%d\t",p->data);
		post(p->right);
	}
}
void postorder(node *root)
{
	node *stack[100];
	int top=1;
	stack[1]=NULL;
	node *p=root;
	while(p!=0)
	{
		top++;
		stack[top]=p;
	
		if(p->right!=0)
		{
			top++;
			stack[top]=
			-(p->right);
		}
		p=p->left;
	}
	p=stack[top];
	top--;
	while(p>0)
	{
		printf("%d\t",p->data);
		p=stack[top];
		top--;
	}
	if(p<0)
	{
		p=-1*p;
		while(p!=0)
		{
			top++;
			stack[top]=p;
			if(p->right!=0)
			{
				top++;
				stack[top]=-1*p->right;
			}
			p=p->left;
		}
	}
}
