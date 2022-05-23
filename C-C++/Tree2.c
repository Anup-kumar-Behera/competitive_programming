#include"stdio.h"
#include"stdlib.h"

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_heap_tree(node *,int ,int ,int );
void inorder(node *);
void preorder(node *);
void postorder(node *);

 main()
 {
 	node *root=0;
 	int n;
 	printf("Enter number of nodes: ");
 	scanf("%d",&n);
 	
 	int i,x[n];
 	printf("Enter node values:\n");
 	for(i=0;i<n;i++)
 		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		root=create_heap_tree(root,x[i],n,i);
	printf("\nInorder Traversal:\n");
	inorder(root);
		printf("\n");
		printf("Preorder Traversal:\n");
	preorder(root);
		printf("\n");
		printf("Postorder Traversal:\n");
	postorder(root);
		printf("\n");
 }
 node *create_heap_tree(node *p,int data,int n,int i)
 {
 
 	if(i<n)
 	{
 		if(p==0)
 		{
 			p=(node *)malloc(sizeof(node));
 			p->left=0;
 			p->right=0;
 			p->data=data;
		}
		p->left=create_heap_tree(p->left,data,n,i*2+1);
		p->left=create_heap_tree(p->right,data,n,i*2+2);
	}
	return p;
 }
 void inorder(node *p)
 {
 	if(p!=0)
 	{
 		inorder(p->left);
 		printf("%d\t",p->data);
 		inorder(p->right);
 	}
 }
 void preorder(node *p)
 {
 	if(p!=0)
 	{
 		printf("%d\t",p->data);
 		preorder(p->left);
 		preorder(p->right);
	}
 }
 void postorder(node *p)
 {
 	if(p!=0)
 	{
 		postorder(p->left);
 		postorder(p->right);
 		printf("%d\t",p->data);
	}
 }
