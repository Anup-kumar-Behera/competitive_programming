#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	char name[20];
	struct node *next,*prev;
}node;
node *root = 0, *end = 0;

void createList();
void dsp1();
void dsp2();

main()
{
	int n;
	do
	{
		printf("\nEnter 1 to create List.\n");
		printf("Enter 2 to dispaly in forward.\n");
		printf("Enter 3 to dispaly in backward.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n == 1)
		{
			createList();
		}
		else if(n == 2)
		{
			printf("Displaying list in forward.\n");
			dsp1();
		}
		else if(n == 3)
		{
			printf("Displaying list in backward.\n");
			dsp2();
		}
	}while(n != 0);
}

void createList()
{
	root = (node *)malloc(sizeof(node));
	node *p = root;
	int roll,i = 2;
	char name[20], x[5];
	if(p == 0)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter roll and name: ");
		scanf("%d %s",&roll,&name);
		p->data = roll;
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
				scanf("%d %s",&roll,name);
				q->data = roll;
				strcpy(q->name,name);
				q->next = 0;
				q->prev = p;
				p->next = q;
				p = p->next;
				end = p;
				i++;
			}
		}
		p->next = 0;
	}
}
void dsp1()
{
	if( root == 0)
		printf("underflow.\n");
	else
	{
		node *p = root;
		while(p != 0)
		{
			printf("Roll: %d\tName: %s\n",p->data,p->name);
			p = p->next;
		}
	}
}
void dsp2()
{
	if(end == 0)
		printf("Underflow.\n");
	else
	{
		node *p = end;
		while(p != 0)
		{
			printf("Roll: %d\tName: %s\n",p->data,p->name);
			p = p->prev;
		}
	}
}
