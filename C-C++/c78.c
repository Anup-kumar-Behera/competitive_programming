#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
void inorder(node *);
node *search(node *,int );
node *newnode(int );
node *insert(node *,int );
int height(node *);
void printGivenLevel(node *,int );
void printLevelOrder(node *);
int s[100];
int top=0;
void findPreSuc(node *,int );
node *pre=0,*suc=0;

main()
{
	int n;
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	int i,x[n];
	printf("Enter node values:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node value: ",i+1);
		scanf("%d",&x[i]);
	}
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	printf("\nInorder Traversal: \n");
	inorder(root);
	printf("\nIn descending order:\n");
	while(top>=0)
	{
		printf("%d\t",s[top]);
		top--;
	}
	int key;
	printf("\nEnter  key to search in the bst : ");
	scanf("%d",&key);
	node *a=search(root,key);
	if(a==0)
		printf("\nSearch Unsuccessful.\n");
	else
		printf("Search Successful.\n");
	int data;
	printf("\nEnter data to insert in the tree: ");
	scanf("%d",&data);
	insert(root,data);
	printf("\nInorder Traversal after insertion: \n");
	inorder(root);
	printf("\nLevel Order traversal of binary tree is \n"); 
    printLevelOrder(root); 
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
		s[top]=p->data;
		top++;
		inorder(p->right);
	}
}
node *search(node *p,int key)
{
	if(p==0)
		return 0;
	if(p!=0 && p->data==key)
		return p;
	else if(key>p->data)
		return search(p->right,key);
	else if(key<p->data)
		return search(p->left,key);
}
node *insert(node *p,int data)
{
	if(p==0)
		return newnode(data);
	if(data>p->data)
		p->right=insert(p->right,data);
	else if(data<p->data)
		p->left=insert(p->left,data);
	return p;
}
node *newnode(int data)
{
	node *p=(node *)malloc(sizeof(node));
	p->left=0;
	p->right=0;
	p->data=data;
	return p;
}

void printGivenLevel(node *root,int level)
{
	if(root==0)
		return;
	if(level==1)
		printf("%d ",root->data);
	else if(level>1)
	{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}
int height(node *root)
{
	if(root==0)
		return 0;
	else
	{
		int lheight=height(root->left);
		int rheight=height(root->right);
		
		if(lheight>rheight)
			return lheight+1;
		else return rheight+1;
	}
}
void printLevelOrder(node *root)
{
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
		printGivenLevel(root,i);
}
