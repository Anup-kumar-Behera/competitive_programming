#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int data;
	char name[20];
	struct node *next;
}node;

void createList();
void dsp();
node *root = 0;

main()
{
	int n;
	do
	{
		printf("\nEnter 1 to create list.\n");
		printf("Enter 2 to display list.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n == 1)
		{
			createList();
		}
		else if(n == 2)
		{
			dsp();
		}
	}while(n != 0);
}

void createList()
{
	root = (node *)malloc(sizeof(node));
	node *p = root;
	int data,i = 2;
	char na[20],x[5];
	if(root == 0)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter roll and name : ");
		scanf("%d%s",&data,na);
		p->data = data;
		strcpy(p->name,na);
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
				printf("%d. Enter roll and name : ",i);
				scanf("%d %s",&data,na);
				q->data = data;
				strcpy(q->name,na);
				q->next = 0;
				p->next = q;
				p = p->next;
				i++;
			}
		}
		p->next = 0;
	}	
}
void dsp()
{
	node *p = root;
	if(p == 0)
		printf("Underflow.\n");
	else
	{
		while(p != 0)
		{
			printf("Name: %s\tRoll: %d\n",p->name,p->data);
			p = p->next;
		}
	}
}
