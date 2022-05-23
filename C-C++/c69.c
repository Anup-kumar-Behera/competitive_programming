// SUM OF LEAF NODES

#include"stdio.h"
#include"stdlib.h"

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *create_bst(node *,int );
int sum_ofLeafNodes(node *);
int *inorder(node *);
	int top=0;
	int s[100];
	int min(node *);
	
main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int x[n],i;
	
	printf("Enter node values: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d node value: ",i+1);
		scanf("%d",&x[i]);
	}
	node *root=0;
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	
	int *p=inorder(root);
	while(i>0)
	{
		printf("%d ",-1*p[i]);
		i--;
	}
	if(n*2==0)
		printf("\n%f \n",(-1*(p[n/2]+p[n/2+1])));
	else 
		printf("\n%f \n",(-1*p[n/2]));
	int k=min(root);
	printf("\nMin. value is : %d \n",k);
}

node *create_bst(node *p, int data)
{
	if(p==0)
	{
		p=(node *)malloc(sizeof(node));
		p->left=0;
		p->right=0;
		p->data=-data;
	}
	else
	if(data>p->data)
		p->right=create_bst(p->right,data);
	else
		p->left=create_bst(p->left,data);
	return p;
}

int *inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		top++;
		s[top]=p->data;
		inorder(p->right);
	}
	return s;
}
int min(node *root)
{
	int *p=inorder(root);
	int i;
	
	int k=p[0];
	while(i>0)
	{
		if(k>p[i])
			k=p[i];
		i--;
	}
	return k;
}
