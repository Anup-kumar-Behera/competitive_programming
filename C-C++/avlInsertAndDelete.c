#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *right,*left;
	int data,height;
}node;
node *insert(node *,int );
int max(int ,int );
int getBalance(node *);
node *minValueNode(node *);
int height(node *);
node *newNode(int );
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *leftRotate(node *);
node *rightRotate(node *);
node *deleteNode(node *,int );

main()
{
	int num;
	printf("Enter number of nodes: ");
	scanf("%d",&num);
	int i,x[num];
	printf("Enter node values: \n");
	for(i=0;i<num;i++)
	{
		printf("Enter %d node value: ",i+1);
		scanf("%d",&x[i]);
	}
	node *root=0;
	for(i=0;i<num;i++)
		root=insert(root,x[i]);
	
	printf("\nInorder Traversal: \n");
	inorder(root);
	printf("\nPreorder traversal: \n");
	preorder(root);
	printf("\nPostorder Traversal: \n");
	postorder(root);
	int val;
	printf("\nEnter value to delete:  ");
	scanf("%d",&val);
	deleteNode(root,val);
	printf("\nInorder Traversal after deletion: \n");
	inorder(root);
	printf("\nPreorder Traversal after deletion: \n");
	preorder(root);
	
}
node *insert(node *root,int data)
{
	if(root==0)
		return newNode(data);
	if(data>root->data)
		root->right=insert(root->right,data);
	else if(data<root->data)
		root->left=insert(root->left,data);
	else
		return root;
	
	root->height=1+max(height(root->left),height(root->right));
	
	int balance=getBalance(root);
	
	if(balance>1 && data<root->left->data)
		return rightRotate(root);
	if(balance<-1 && data>root->right->data)
		return leftRotate(root);
	if(balance>1 && data>root->left->data)
	{
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance<-1 && data<root->right->data)
	{
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

node *newNode(int data)
{
	node *p=(node *)malloc(sizeof(node));
	p->left=p->right=0;
	p->height=1;
	p->data=data;
	return p;
}
int height(node *p)
{
	if(p==0)
		return 0;
	else	
		return p->height;
}
int getBalance(node *p)
{
	if(p==0)
		return 0;
	else
		return height(p->left)-height(p->right);
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
node *leftRotate(node *p)
{
	node *x=p->right;
	node *y=x->left;
	
	x->left=p;
	p->right=y;
	
	p->height=max(height(p->left),height(p->right))+1;
	x->height=max(height(x->left),height(p->right))+1;
	
	return x;
}
node *rightRotate(node *p)
{
	node *x=p->left;
	node *y=x->right;
	
	x->right=p;
	p->left=y;
	
	p->height=max(height(p->left),height(p->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
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
void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d\t",p->data);
		inorder(p->right);
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
node *minValueNode(node *p)
{
	node *current = p;
	while(current && current->left != 0)
		current = current->left;
	return current;
}
node *deleteNode(node *root,int key)
{
	if(root == 0)
		return root;
	if(key < root->data)
		root->left = deleteNode(root->left,key);
	else if(key > root->data)
		root->right = deleteNode(root->right,key);
	else
	{ 
		// node with only one child or no child 
		if( (root->left == NULL) || (root->right == NULL) ) 
		{ 
			node *temp = root->left ? root->left : 
											root->right; 

			// No child case 
			if (temp == NULL) 
			{ 
				temp = root; 
				root = NULL; 
			} 
			else // One child case 
				*root = *temp; // Copy the contents of 
							// the non-empty child 
			free(temp); 
		} 
		else
		{ 
			// node with two children: Get the inorder 
			// successor (smallest in the right subtree) 
			node* temp = minValueNode(root->right); 

			// Copy the inorder successor's data to this node 
			root->data = temp->data; 

			// Delete the inorder successor 
			root->right = deleteNode(root->right, temp->data); 
		} 
	}
	// If the tree had only one node then return 
	if (root == NULL) 
	return root; 

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
	root->height = 1 + max(height(root->left), 
						height(root->right)); 

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
	// check whether this node became unbalanced) 
	int balance = getBalance(root); 

	// If this node becomes unbalanced, then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && getBalance(root->left) >= 0) 
		return rightRotate(root); 

	// Left Right Case 
	if (balance > 1 && getBalance(root->left) < 0) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Right Case 
	if (balance < -1 && getBalance(root->right) <= 0) 
		return leftRotate(root); 

	// Right Left Case 
	if (balance < -1 && getBalance(root->right) > 0) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 

	return root;  
}
