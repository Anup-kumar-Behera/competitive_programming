
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int key;
	struct node *right;
	int height;
}node;
int height(node *);
node *insert(node *,int );
int getBalance(node *);
node *rightRotate(node *); 
node *leftRotate(node *);
void inorder(node *);
node *newNode(int ); 
int max(int ,int );

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
	for(i=0;i<n;i++)
		root=insert(root,x[i]);
	inorder(root);
}
void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d\t",p->key);
		inorder(p->right);
	}
}
int height(node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 
int getBalance(node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 
node* insert(node *p, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (p == NULL) 
		return(newNode(key)); 

	if (key < p->key) 
		p->left = insert(p->left, key); 
	else if (key > p->key) 
		p->right = insert(p->right, key); 
	else // Equal keys are not allowed in BST 
		return p; 

	/* 2. Update height of this ancestor node */
	p->height = 1 + max(height(p->left), 
						height(p->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(p); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < p->left->key) 
		return rightRotate(p); 

	// Right Right Case 
	if (balance < -1 && key > p->right->key) 
		return leftRotate(p); 

	// Left Right Case 
	if (balance > 1 && key > p->left->key) 
	{ 
		p->left = leftRotate(p->left); 
		return rightRotate(p); 
	} 

	// Right Left Case 
	if (balance < -1 && key < p->right->key) 
	{ 
		p->right = rightRotate(p->right); 
		return leftRotate(p); 
	} 

	/* return the (unchanged) node pointer */
	return p; 
} 
node *rightRotate(node *y) 
{ 
	node *x = y->left; 
	node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	// Return new root 
	return x; 
} 

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
node *leftRotate(node *x) 
{ 
	node *y = x->right; 
	node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	// Return new root 
	return y; 
} 
node* newNode(int key) 
{ 
	node* p = (node *)malloc(sizeof(node)); 
	p->key = key; 
	p->left = NULL; 
	p->right = NULL; 
	p->height = 1; // new node is initially added at leaf 
	return(p); 
} 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 
