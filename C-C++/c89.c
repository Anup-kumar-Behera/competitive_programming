#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node *createBst(node *,int data);
void inorder();
void preorder();
void postorder();

int main()
{
	int n;
	printf("Enter no of nodes: ");
	scanf("%d",&n);

	node *root = 0;	
	int i,arr[n];
	printf("Enter node values: \n");
	
	for(i = 0;i < n;i++)
	{
		printf("Enter %d array element: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	for(i = 0;i < n;i++)
		root = createBst(root,arr[i]);
		
	printf("\nInorder Traversal:\n");
	inorder(root);
	
	printf("\nPreorder Traversal:\n");
	preorder(root);
	
	printf("\nPostorder Traversal:\n");
	postorder(root);
	
	return 0;
}
node *createBst(node *root,int data)
{
	if(root == 0)
	{
		root = (node *)malloc(sizeof(node));
		root->data = data;
		root->left = 0, root->right = 0;
	}
	else
		if(data > root->data)
			root->right = createBst(root->right,data);
		else
			root->left = createBst(root->left,data);
	
	return root;
}

void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
