#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left,*right;
	int data,height;
}node;
node *insert(node *,int );
node *search(node *,int );
node *newNode(int );
int height(node *);
int getBf(node *);
int max(int ,int );
node *leftRotate(node *);
node *rightRotate(node *);
void inorder(node *);
void preorder(node *);
node *root=0;
int sumOfLeafNodes(node *);

main()
{
	int k;
	do
	{
		printf("\nEnter 1 to create AVL tree.\n");
		printf("Enter 2 for inorder traversal.\n");
		printf("Enter 3 for preorder Traversal.\n");
		printf("Enter 4 to insert new node.\n");
		printf("Enter 5 to search an item.\n");
		printf("Enter 6 for sum of leaf nodes.\n");
		printf("Enter choice: ");
		scanf("%d",&k);
		if(k==1)
		{
			int n;
			printf("Enter number of nodes: ");
			scanf("%d",&n);
			int i,x[n];
			printf("Enter node values:\n");
			for(i=0;i<n;i++)
			{
				printf("Enter %d node value: ",i+1);
				scanf("%d",&x[i]);
			}
			
			for(i=0;i<n;i++)
				root=insert(root,x[i]);
		}
		else if(k==2)
		{
			printf("\nInorder Traversal: \n");
			inorder(root);
		}
		else if(k==3)
		{
			printf("\nPreorder Traversal: \n");
			preorder(root);
		}
		else if(k==4)
		{
			int data;
			printf("Enter data to insert in the AVL tree: ");
			scanf("%d",&data);
			insert(root,data);
		}
		else if(k==5)
		{
			int key;
			printf("Enter key to search: ");
			scanf("%d",&key);
			node *p=search(root,key);
			if(p==0)
				printf("Search Unsuccessful.\n");
			else
				printf("Search successful.\n");
		}
		else if(k==6)
		{
			int sum=sumOfLeafNodes(root);
			printf("\nSum of leaf nodes of bst: %d \n",sum);
		}
	}while(k!=0);
}
node *newNode(int data)
{
	node *p=(node *)malloc(sizeof(node));
	p->left=p->right=0;
	p->data=data;
	p->height=1;
	return p;
}
void preorder(node *p)
{
	if(p)
	{
		printf("%d\t",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
int height(node *p)
{
	if(p==0)
		return 0;
	else
		return p->height;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
int getBf(node *p)
{
	if(p==0)
		return 0;
	else
		return height(p->left)-height(p->right);
}
node *insert(node *root,int data)
{
	if(root==0)
		return newNode(data);
	if(data>root->data)
		root->right=insert(root->right,data);
	else if(data<root->data)
		root->left=insert(root->left,data);
	else 
		return root;
	
	root->height=1+max(height(root->right),height(root->left));

	int balance=getBf(root);
	
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
node *leftRotate(node *p)
{
	node *x=p->right;
	node *y=x->left;
	
	x->left=p;
	p->right=y;
	
	p->height=max(height(p->left),height(p->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}
node *rightRotate(node *p)
{
	node *x=p->left;
	node *y=x->right;
	
	x->right=p;
	p->left=y;
	
	p->height=max(height(p->left),height(p->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}
node *search(node *p,int key)
{
	if(p==0)
		return 0;
	if(p!=0 && p->data==key)
		return p;
	if(key>p->data)	
		search(p->right,key);
	else if(key<p->data)
		search(p->left,key);
}

int sumOfLeafNodes(node *p)
{
	int s=0;
	if(p==0)
		return 0;
	if(p!=0 && p->left==0 && p->right==0)
		return p->data;
	else
		return s+sumOfLeafNodes(p->left)+sumOfLeafNodes(p->right);
}
