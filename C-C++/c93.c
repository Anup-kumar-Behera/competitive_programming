#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node *head = 0,*p = 0;

void createCircularList()
{
	head = (node *)malloc(sizeof(node));
	p = (node *)malloc(sizeof(node));
	head->next = p;
	node *r = p;
	if(head == 0)
		printf("Overflow!");
	else
	{
		int d;
		int i = 2;
		char x[5];
		
		printf("1. Enter data: ");
		scanf("%d",&d);
		r->data = d;
		r->next = head;

		while(1)
		{
			printf("Do you want to continue (Y/N): ");
			scanf("%s",x);
			
			if(strcmp(x,"N") == 0)
				break;
			
			node *q = (node *)malloc(sizeof(node));
			
			if(q == 0)
			 	printf("Overflow!");
			else
			{
				printf("%d. Enter data: ",i);
				scanf("%d",&d);
				i ++;
				q->data = d;
				q->next = head;
				r->next = q;
				r = r->next;
			}
		}
	}
}

void traverse()
{
	if(head->next == head)
		printf("Underflow!\n");
	else
	{
		node *q = head->next;
		while(q != head)
		{
			printf("%d ",q->data);
			q = q->next;
		}
		printf("\n");
	}
}

main()
{
	int n;
	do
	{
		printf("\nEnter 1 to create circular list.\n");
		printf("Enter 2 to traverse circular list.\n");
		printf("Enter 0 to stop.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		
		if(n == 1)
			createCircularList();
		else if(n == 2)
			traverse();
	}while(n != 0);
}
