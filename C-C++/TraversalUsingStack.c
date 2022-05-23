#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
node *create_bst(node *,int );
void inorder(node *);
void preorder(node *);
void postorder(node *);
void inorderStack(node *);
//void preorderStack(node *);
//void postorderStack(node *);
typedef struct sNode{
	struct node *t;
	struct sNode *next;
}sNode;

void push(sNode **,node *);
node *pop(sNode **);
bool isEmpty(sNode *);

main()
{
	int n;
	node *root=0;
	do
	{
		printf("\nEnter 1 to create BST.\n");
		printf("Enter 2 for recursive inorder Traversal.\n");
		printf("Enter 3 for recursive preorder Traversal.\n");
		printf("Enter 4 for recursive postorder Traversal.\n");
		printf("Enter 5 for inorder traversal using stack.\n");
		printf("Enter 6 for preorder traversal using stack.\n");
		printf("Enter 7 for postorder traversal using stack.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
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
			for(i=0;i<num;i++)
				root=create_bst(root,x[i]);
		}
		else if(n==2)
		{
			printf("\nRecursive Inorder Traversal: \n");
			inorder(root);
		}
		else if(n==3)
		{
			printf("\nRecursive Preorder Preorder traversal: \n");
			preorder(root);
		}
		else if(n==4)
		{
			printf("\nRecursive Postorder Traversal: \n");
			postorder(root);
		}
		else if(n==5)
		{
			printf("\nInorder Traversal using Stack: \n");
			inorderStack(root);
		}
		else if(n==6)
		{
			printf("\nPreorder Traversal using stack: \n");
			//preorderstack(root);
		}
		else if(n==7)
		{
			printf("\nPostorder Traversal using Stack: \n");
			//postorderStack(root);
		}
	}while(n!=0);
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


void inorderStack(node *p)
{
	node *current = p;
	sNode *s=0;
	bool done=0;
	
	while(!done)
	{
		if(current != 0)
		{
			push(&s, current);
			current = current->left;
		}
		else 
		{
			if(!isEmpty(s))
			{
				current = pop(&s);
				printf("%d\t",current->data);
				current = current->right;
			}
			else 
				done = 1;
		}
	}
}
void push(sNode **top_ref,node *t)
{
	sNode *newNode=(sNode *)malloc(sizeof(sNode));
	if(newNode == 0)
	{
		printf("Stack Overflow.\n");
		getchar();
		exit(0);
	}
	newNode->t = t;
	newNode->next = (*top_ref);
	(*top_ref) = newNode;
}
bool isEmpty(sNode *top)
{
	return (top == 0)? 1 : 0;
}
node *pop(sNode **top_ref)
{
	node *res;
	sNode *top;
	if(isEmpty(*top_ref))
	{
		printf("Stack Underflow.\n");
		getchar();
		exit(0);
	}
	else
	{
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return res;
	}
}
node *newNode(int data)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->left = newNode->right = 0; 
	newNode->data = data;
	
	return newNode;
}
