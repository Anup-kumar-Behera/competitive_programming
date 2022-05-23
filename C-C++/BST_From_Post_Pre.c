//	BST CONSTRUCTION FROM GIVEN PRE && POST-ORDER TRAVERSAL SEQUENCE

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *right;
	struct node *left;
}node;

void inorder(node *);
void postorder(node *);
void preorder(node *);
node *newNode(int );
node *create_bst(int [],int [],int );
node *construct(int [],int [],int *,int ,int ,int );

main()
{
	int n;
	node *root=0;
	do
	{
		printf("\nEnter 1 to create bst.\n");
		printf("Enter 2 for Inorder Traversal.\n");
		printf("Enter 3 for Preoder Traversal.\n");
		printf("Enter 4 for Postorder Trraversal.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			int num;
			printf("Enter number of nodes: ");
			scanf("%d",&num);
			int i,pre[num],post[num];
	
			printf("Enter Pre-Order Traversal Sequence: \n");
			for(i=0;i<num;i++)
				scanf("%d",&pre[i]);
			printf("\nEnter Post-Order Traversal Sequence: \n");
			for(i=0;i<num;i++)
				scanf("%d",&post[i]);
			
			int size=sizeof(pre)/sizeof(pre[0]);
			root=create_bst(pre,post,size);
		}
		else if(n==2)
		{
			printf("\nInorder traversal: \n");
			inorder(root);
		}
		else if(n==3)
		{
			printf("\nPreorder traversal: \n");
			preorder(root);
		}
		else if(n==4)
		{
			printf("\nPostorder Traversal: \n");
			postorder(root);
		}
	}while(n!=0);
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
void postorder(node *p)
{
	if(p)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d\t",p->data);
	}
}
node *newNode(int data)
{
	node *p=(node *)malloc(sizeof(node));
	p->left=p->right=0;
	p->data=data;
	return p;
}
node *construct(int pre[],int post[],int *preIndex,int l,int h,int size)
{
	if(*preIndex>=size || l>h)
		return 0;
		
	node *root=newNode(pre[*preIndex]);
	++*preIndex;
	
	if(l==h)
		return root;
	
	int i;
	for(i=l;i<=h;i++)
		if(pre[*preIndex] == post[i])
			break;
			
	if(i <= h)
	{
		root->left = construct(pre,post,preIndex,i+1,h,size);
		
		root->right = construct(pre,post,preIndex,i+1,h,size);
	}
	return root;
}
node *create_bst(int pre[],int post[],int size)
{
	int preIndex=0;
	return construct(pre,post,&preIndex,0,size-1,size);
}
