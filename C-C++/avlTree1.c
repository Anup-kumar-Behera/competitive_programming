#include<stdio.h>
#include<stdlib.h>

typedef struct avlTree{
	struct avlTree *left;
	int data;
	struct avlTree *right;
	int height;
}avl;
avl *insert(avl *,int );
int height(avl *);
//int getBf(avl *);
avl *rightRotate(avl *);
avl *leftRotate(avl *);
avl *newNode(int );
void inorder(avl *);
void preorder(avl *);
void postorder(avl *);
int getBlance(avl *);
int max(int ,int );
avl *deleteNode(avl *,int );
avl *minNode(avl *);


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
	
	avl *root=0;
	for(i=0;i<n;i++)
		root=insert(root,x[i]);
	printf("\nInorder Traversal of avl tree is : \n");
	inorder(root);
	printf("\nPreorder Traversal: \n");
	preorder(root);
	printf("\nPostorder Traversal :\n");
	postorder(root);
	
	int val;
	printf("\nEnter value to delete: ");
	scanf("%d",&val);
	deleteNode(root,val);
	printf("\nInorder Traversal after deletion: \n");
	inorder(root);
	printf("\nPreorder Traversal after deletion: \n");
	preorder(root);
	printf("\nPostorder Traversal after deletion: \n");
	postorder(root);
}
avl *newNode(int data)
{
	avl *p=(avl *)malloc(sizeof(avl));
	p->data=data;
	p->left=p->right=0;
	p->height=1;
	return p;
}
int height(avl *root)
{
	if(root==0)
		return 0;
	else 
		return root->height;
}
void preorder(avl *root)
{
	if(root)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(avl *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
void inorder(avl *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
avl *minNode(avl* p)
{
	avl *current = p;
	
	while(current && current->left != 0)
		current = current->left;
		
	return current;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int getBalance(avl *p)
{
	if(p==0)
		return 0;
	else
		return height(p->left)-height(p->right);
}
avl *insert(avl *p,int data)
{
	if(p==0)
		return newNode(data);
	if(data<p->data)
		p->left=insert(p->left,data);
	else if(data>p->data)
		p->right=insert(p->right,data);
	else
		return p;
	p->height=1+max(height(p->left),height(p->right));
	int balance=getBalance(p);
	
	if(balance>1 && data<p->left->data)
		return rightRotate(p);
	if(balance<-1 && data>p->right->data)
		return leftRotate(p);
	if(balance>1 && data>p->left->data)
	{
		p->left=leftRotate(p->left);
		return rightRotate(p);
	}
	if(balance<-1 && data<p->right->data)
	{
		p->right=rightRotate(p->right);
		return leftRotate(p);
	}
	return p;
}
avl *rightRotate(avl *p)
{
	avl *x=p->left;
	avl *y=x->right;
	
	x->right=p;
	p->left=y;
	
	p->height=max(height(p->left),height(p->right))+1;
	x->height=max(height(x->left),height(p->right))+1;
	
	return x;
}
avl *leftRotate(avl *p)
{
	avl *x=p->right;
	avl *y=x->left;
	
	x->left=p;
	p->right=y;
	
	p->height=max(height(p->left),height(p->right))	+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}

avl *deleteNode(avl *root,int data)
{
	if(root==0)
		return NULL;
	if(data>root->data)
		root->right=deleteNode(root->right,data);
	else if(data < root->data)
		root->left = deleteNode(root->left,data);
	else
	{
		if((root->left == 0) || (root->right == 0))
		{
			avl *temp = root->left ? root->left : root->right;
			
			if(temp == 0)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			avl *temp = minNode(root->right);
			
			root->data = temp->data;
			
			root->right = deleteNode(root->right,temp->data);
		}
	}
	
	if(root == 0)
		return root;
		
	root->height = max(height(root->left),height(root->right))+1;
	int balance = getBalance(root);
	
	if(balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if(balance > 1 && getBalance(root->right) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	if(balance < -1 && getBalance(root->right) > 0 )
	{
		root->right = rightRotate(root->right) ;
		return leftRotate(root);
	}
	
	return root;
}
