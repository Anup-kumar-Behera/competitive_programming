#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left,*right;
	int data;
}node;
node *create_bst(node *,int );
void inorder(node *);
int sumOfLeafNodes(node *);
void  nodeWithoutSib(node *);

main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int i,x[n];
	printf("Enter node elements: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node element: ",i+1);
		scanf("%d",&x[i]);
	}
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	printf("\nInorder Traversal: \n");
	inorder(root);
	int sum=sumOfLeafNodes(root);
	printf("\nSum of leaf nodes: %d \n",sum);
	nodeWithoutSib(root);
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
void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d\t",p->data);
		inorder(p->right);
	}
}
int sumOfLeafNodes(node *p)
{
	int s=0;
	if(p==0)
		return 0;
	if(p!=0 && p->left==0 && p->right==0)
		return p->data;
	if(p)
		return s+sumOfLeafNodes(p->left)+sumOfLeafNodes(p->right);
}
void nodeWithoutSib(node *p)
{
	if(p)
	{
		nodeWithoutSib(p->left);
		if(p!=0 && p->left==0 && p->right!=0)
			printf("%d\t",p->right->data);
		else if(p!=0 && p->left!=0 && p->right==0)
		printf("%d\t",p->left->data);
		nodeWithoutSib(p->right);
	}
}
