#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	char name[20];
	struct node *next;
}node;
node *head = 0;

void createlist();
void dsp();
void del(int );

main()
{
	int n;
	do
	{
		printf("\nEnter 1 to create List.\n");
		printf("Enter 2 to display list.\n");
		printf("Enter 3 to delete item from the list.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		
		if( n == 1)
			createlist();
		else if(n == 2)
		{
			printf("List elements: \n");
			dsp();
		}
		else if(n == 3)
		{
			int item;
			printf("Enter item to delete: ");
			scanf("%d",&item);
			del(item);
		}
	}while(n != 0);
}
void createlist()
{
	head = (node *)malloc(sizeof(node));
	node *p = head;
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
				p = p->next;
				i++;
			}
		}
		p->next = 0;
	}
}
void dsp()
{
	if(head == 0)
		printf("Underflow.\n");
	else
	{
		node *p = head;
		while(p != 0)
		{
			printf("Roll: %d\tName: %s\n",p->data,p->name);
			p = p->next;
		}
	}
}
void del(int item)
{
	node *p = head,*save = 0,*temp = 0;
	while(p != 0)
	{
		if(p->data == item)
		{
			save = p;
			break;
		}
		p = p->next;
	}
	p = save;
	if(save  == 0)
		printf("Item does not exist in the list.\n");
	else
	{
		while(p != 0)
		{
			p->data = p->next->data;
			strcpy(p->name,p->next->name);
			temp = p;
			//save->next = save->next->next;
			p = p->next;
		}
		free(temp);
	}
}
