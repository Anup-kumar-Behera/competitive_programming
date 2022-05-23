#include"stdio.h"
#include"stdlib.h"

typedef struct node{
	int data;
	struct node *link;
}node;

node *head;
void traverse();
void createList();
void insert();
void search();

main()
{	
	printf("Enter '0' to stop.\n");
	printf("Enter '1' to traverse.\n");
	printf("Enter '2' to insert.\n");
	printf("enter '3' to search.\n\n");
	
	int a=10;
	while(a!=0)
	{
		printf("\n------------------------------------\n");
		printf("Enter choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 0: break;
					
			case 1: printf("\n-------------------------------------\n");
					insert();
					break;
			case 2: printf("\n-------------------------------------\n");
					traverse();
					break;
			case 3: printf("\n-------------------------------------\n");
					search();
					break;
		}
	}
}

void insert()
{
	int d;
	head=(node *)malloc(sizeof(node));
	node *p=(node *)malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&d);
	p->data=d;
	head->link=p;
	p->link=head;
}
void traverse()
{
	if(head->link==head)
		printf("\nUnderflow.\n");
	else
	{
		node *p=head->link;
		while(p!=head)
		{
			printf("data: %d\n",p->data);
			p=p->link;
		}
	}
}
void search()
{
	int key;
	printf("Enter item to search: ");
	scanf("%d",&key);
	node *loc;
	node *p=head->link;
	while(p!=head)
	{
		if(p->data==key)
		{
			loc=p;
			break;
		}
		else
		{
			p=p->link;
			loc=NULL;
		}
	}
	if(loc==NULL)
		printf("\nItem not found.\n");
	else
		printf("\nItem found.\n");
}
