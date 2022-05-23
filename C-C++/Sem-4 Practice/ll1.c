#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int data;
	char name[20];
	struct node *next;
}node;
node *head = 0;
void printlist();
void createList();

main()
{
	int n;
	do
	{
		printf("Enter 1 to insert data\n");
		printf("Enter 2 to print list.\n");
		printf("Enter 3 to delete data\n");
		printf("Enter 4 to search data\n");
		printf("Enter 0 to stop\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		
		if(n == 1)
		{
			createList();
		}
		else if(n == 2)
		{
			printlist();
		}
		else if(n == 3)
		{
			printf("i love cse");
		}
		else if(n == 4)
		{
			printf("I love everything.");
		}
	}while(n != 0);
}
void createList()
{
	head = (node *)malloc(sizeof(node));
	node *p = head;
	
	int d,i = 2;	
	char na[20],x[5];
	
	if(p == NULL)	
		printf("Overflow.\n");
	else
	{
		printf("1. Enter roll and name: ");
		scanf("%d %s",&d,na);
		p->data=d;
		p->next = 0;
		strcpy(p->name,na);
		while(1)
		{
			printf("Do you want to continue  (Y/N): ");
			scanf("%s",x);
			
			if(strcmp(x,"N") == 0)
				break;
			node *q = (node *)malloc(sizeof(node));
			if(q == 0)
				printf("Overflow.\n");
			else
			{
				printf("%d. Enter roll and name: ",i);
				scanf("%d %s",&d,na);
				
				strcpy(q->name,na);
				q->data = d;
				q->next = 0;
				p->next = q;
				p = p->next;
				i++;
			}
		}
	}
}
void printlist()
{
	if(head == 0)
		printf("Underflow.\n");
	else
	{
		node *p = head;
		while(p != 0)
		{
			printf("roll: %d\t name: %s\n",p->data,p->name);
			p = p->next;
		}
	}
}
