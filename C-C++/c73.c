#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
node *create_bst(node *,int );
void inorder(node *);
node *find(node *,int );
node *insert(node *,int );
node *del(node *,int );
node *minValue(node *);

main()
{
	int n;
	printf("Enter number of nodes :");
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
		root=create_bst(root,x[i]);
	int key;
	printf("\nEnter key to search in the bst: ");
	scanf("%d",&key);
	node *p=find(root,key);
	if(p!=0)
		printf("Search successful.\n");
	else
		printf("Search Unsuccesssful.\n");
	int data;
	printf("\nEnter node value to insert: ");
	scanf("%d",&data);
	insert(root,data);
	printf("\nInorder Traversal:\n");
	inorder(root);
	int val;
	printf("\nEnter value to delete: ");
	scanf("%d",&val);
	node *q=del(root,val);
	printf("\nInorder traversal after deletion:\n");
	inorder(q);
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
node *find(node *p,int key)
{
	if(p==0)
		return 0;
	else if(p!=0 && p->data==key)
		return p;
	else if(key>p->data)
		return find(p->right,key);
	else
		return find(p->left,key);
}
void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d \t",p->data);
		inorder(p->right);
	}
}
node *insert(node *p,int data)
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
	{
		if(data>p->data)
			p->right=insert(p->right,data);
		else
			p->left=insert(p->left,data);
	}
	return p;
}
node *del(node *root,int key)
{
	if(root==0)
		return root;
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
			node *temp=root->left;
			free(root);
			return temp;
		}
		node *temp=minValue(root->right);
		root->data=temp->data;
		root->right=del(root->right,temp->data);
	}
	return root;
}
/*node *minValue(node *p)
{
	if(p==0)
		return NULL;
	else if(p!=0 && p->left==0 && p->right==0)
		return p;
	else
		return minValue(p->left);
}*/
node * minValue(node* p) 
{ 
    node* current = p; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
/*struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} */
