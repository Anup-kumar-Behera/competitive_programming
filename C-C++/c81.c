#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	struct node *left,*right;
	int data,height;
}node;
node *create_avlTree(node *,int );
node *newNode(int );
int height(node *);
int max(int ,int );
int getBF(node *);
void inorder(node *);
node *leftRotate(node *);
node *rightRotate(node *);

main()
{
	int k;
	node *root=0;
	do
	{
		printf("\nEnter 1 to create AVL tree.\n");
		printf("Enter 2 for inorder traversal of the avl tree.\n");
		printf("Enter 3 to delete item from the tree.\n");
		printf("Enter choice: ");
		scanf("%d",&k);
		if(k==1)
		{
			int n=50;
			int i,x[n],c=2,j=0;
			printf("1.Enter value: ");
			scanf("%d",&x[j]);
			char y[5];
			while(1)
			{
				printf("Do you want to continue (Y/N) :");
				scanf("%s",y);
				if(strcmp(y,"N")==0)
					break;
					
				j++;
				printf("%d.Enter value: ",c);
				scanf("%d",&x[j]);
				c++;
			}
			
			for(i=0;i<=j;i++)
			{
				root=create_avlTree(root,x[i]);
				printf("%d\t",x[i]);
			}
		}
		else if(k==2)
		{
			printf("\nInorder Traversal: \n");
			inorder(root);
		}
		else if(k==3)
		{
			
		}
	}while(k!=0);
}
node *create_avlTree(node *root,int data)
{
	if(root==0)
		return newNode(data);
	if(data>root->data)
		root->right=create_avlTree(root->right,data);
	else if(data<root->data)
		root->right=create_avlTree(root->left,data);
	else 
		return root;
	
	root->height=max(height(root->left),height(root->right))+1;
	
	int balance=getBF(root);
	
	if(balance>1 && data<root->left->data)
		return rightRotate(root);
	if(balance<-1 && data>root->right->data)
		return leftRotate(root);
	if(balance>1 && data>root->left->data)
	{
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance<-1 && data<root->right->data)
	{
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
int height(node *root)
{
	if(root==0)
		return 0;
	else
		return root->height;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
node *newNode(int data)
{
	node *newNode=(node *)malloc(sizeof(node));
	newNode->height=1;
	newNode->left=newNode->right=0;
	newNode->data=data;
	
	return newNode;
}
int getBF(node *p)
{
	if(p==0)
		return 0;
	else
		return height(p->left)-height(p->right);
}
node *leftRotate(node *p)
{
	node *x=p->right;
	node *y=x->left;
	
	p->right=y;
	x->left=p;
	
	p->height=max(height(p->left),height(p->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}
node *rightRotate(node *p)
{
	node *x=p->left;
	node *y=x->right;
	
	p->left=y;
	x->right=p;
	
	p->height=max(height(p->left),height(p->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
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
