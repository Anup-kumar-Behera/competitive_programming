// ROTATION IN DOUBLE LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	char name[20];
	struct node *prev,*next;
}node;
node *root = 0, *end = 0;

void createList();
void dsp();
void rotate(int );

int main()
{
	int n;
	do
	{
		printf("\nEnter 1 to create list.\n");
		printf("Enter 2 to dsp.\n");
		printf("Enter 3 to Rotate list.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n == 1)
			createList();
		else if(n == 2)
			dsp();
		else if(n == 3)	
		{
			int k;
			printf("Enter data to rotate: ");
			scanf("%d",&k);
			rotate(k);
		}		
	}while(n != 0);
	
	return 0;
}
void createList()
{
	root = (node *)malloc(sizeof(node));
	node *p = root;
	int data,i = 2;
	char name[20],x[5];
	if(p == 0)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter roll and name: ");
		scanf("%d %s",&data,name);
		p->data = data;
		strcpy(p->name,name);
		p->next = 0;
		p->prev = 0;
		
		while(1)
		{
			printf("Do you want to continue (Y/N): ");
			scanf("%s",x);
			
			if(strcmp(x,"N") == 0)
				break;
			node *q = (node *)malloc(sizeof(node));
			if(q == 0)
				printf("Overflow.\n");
			else
			{
				printf("%d. Enter roll and name: ",i);
				scanf("%d %s",&data,name);
				
				q->data = data;
				strcpy(q->name,name);
				q->next = 0;
				p->next = q;
				q->prev = p;
				p = p->next;
				i++;
			}
		}
		p->next = 0;
	}
}
void dsp()
{
	if( root == 0 )
		printf("Underflow.\n");
	else
	{
		node *p = root;
		while(p != 0)
		{
			printf("Roll: %d\t Name: %s\n",p->data,p->name);
			p = p->next;
		}
	}
}
void rotate(int n)
{
	node *p = root, *save,*back;
	
	while(p != 0)
	{
		if(p->data == n)
		{
			save = p;
			break;
		}
		p = p->next;
	}
	while(p != 0)
	{
		back = p;
		p = p->next;
	}
	if(save == 0)
		printf("Invalid Input!");
	else
	{
		back->next = root;
		root->prev = back;
		root = save->next;
		root->prev = 0;
		save->next = 0;
	}
}
