
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
	
	printf("\nSum of leaf nodes of the bst: %d \n",sum_ofLeafNodes(root));
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
/*int sum_ofLeafNodes(node *p)
{
	if(p==0)
		return 0;
	else if(p->right==0 && p->left==0)
		return p->data;
	else
		return (sum_ofLeafNodes(p->left)+sum_ofLeafNodes(p->right));
}*/
int sum_ofLeafNodes(node *r)
{
	int sum=0;
	if(r == NULL)
		return 0;

	if(r->left==NULL && r->right==NULL)
	{
		return r->data;
//printf("%d\n",&sum);
	}

	sum+= sum_ofLeafNodes(r->left);
	sum+= sum_ofLeafNodes(r->right);
		return sum;
}
