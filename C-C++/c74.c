#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
node *create_bst(node *,int );
node *del(node *,int );
void inorder(node *);
node *min(node *);

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
	node *root=0;
	int val;
	printf("Enter node value to delete: ");
	scanf("%d",&val);
	for(i=0;i<n;i++)
		root=create_bst(root,x[i]);
	printf("\nInorder Traversal :\n");
	inorder(root);
	printf("\nInorder traversal after deletion: \n");
	node *p=del(root,val);
	inorder(p);
}
node *create_bst(node *p,int data)
{
	if(p==0)
	{
		p=(node *)malloc(sizeof(node));
		if(p==0)
		{
			printf("Overflow.\n");
			return ;
		}
		else
		{
			p->left=p->right=0;
			p->data=data;
		}
	}
	else
	if(data>p->data)
		p->right=create_bst(p->right,data);
	else
		p->left=create_bst(p->left,data);
	return p;
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
node *min(node *root)
{
	node *current=root;
	if(current && current->left!=0)
		current=current->left;
	return current;
}
node *del(node *root,int key)
{
	if(root==0)
		return 0;
	if(key<root->data)
		root->left=del(root->left,key);
	else if(key>root->data)
		root->right=del(root->right,key);
	else
	{
		if(root->left==0)
		{
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==0)
		{
			free(root);
			return temp;
		}
		node *temp=min(root->right);
		root->data=temp->data;
		root->right=del(root->right,temp->data);
	}
	return root;
}
