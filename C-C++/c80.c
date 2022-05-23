#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left,*right;
	int data;
}node;
node *insert(node *,int );
void inorder(node *);
node *newNode(int );
void preorder(node *);
node *search(node *,int );


main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	printf("Enter node values: \n");
	int i,x[n];
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	node *root=0;
	for(i=0;i<n;i++)
		root=insert(root,x[i]);
	printf("\nInorder Traversal: \n");
	inorder(root);
	printf("\nPreorder Traversal: \n");
	preorder(root);
	int key;
	int k;
	do{printf("\nEnter 1 to search:  \n");
	printf("Enter choice: ");
	scanf("%d",&k);
	if(k==1)
	{
	printf("\nEnter key to search in the bst: ");
	scanf("%d",&key);
	node *p=search(root,key);
	if(p==0)
		printf("Search Unsuccessful.\n");
	else
		printf("Search Successful.\n");}
	}while(k!=0);
}
node *insert(node *p,int data)
{
	if(p==0)
		return newNode(data);
	if(data>p->data)
		p->right=insert(p->right,data);
	else if(data<p->data)
		p->left=insert(p->left,data);
	else
		return p;
}
node *newNode(int data)
{
	node *p=(node *)malloc(sizeof(node));
	p->left=p->right=0;
	p->data=data;
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
void preorder(node *p)
{
	if(p)
	{
		printf("%d\t",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
node *search(node *root,int key)
{
	if(root==0)
		return 0;
	if(root!=0 && root->data==key)
		return root;
	/*if(root!=0 && root->left==0 && root->right==0 && root->data==key)
		return root;*/
	if(key>root->data)
		search(root->right,key);
	else if(key<root->data)
		search(root->left,key);
	else
		return 0;
}
