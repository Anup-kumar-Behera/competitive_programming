#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int data;
	char name[20];
	struct node *link;
}node;

node *head;
void createList();
void dsp();
void insert();
void del();
void search();

main()
{
	int a=100;
	printf("Enter '1' to createList.\n");
	printf("Enter '2' to display.\n");
	printf("Enter '3' to insert after a data.\n");
	printf("Enter '4' to delete.\n");
	printf("Enter '5' to search.\n");
	printf("Enter '0' to exit.\n\n");
	
	while(a!=0)
	{
		printf("Enter your choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 0: break;
					
			case 1: createList();
					break;
			case 2: dsp();
					break;
			case 3: insert();
					break;
			case 4: del();
					break;
			case 5: search();
					break;
		}
	}
}
void createList()
{
	node *p,*q,*r;
	head=(node*)malloc(sizeof(node));
	p=(node *)malloc(sizeof(node));
	head->link=p;
	r=p;
	int d,i=2;
	char n[20],x[5];
	printf("1. Enter roll and name: ");
	scanf("%d %[^\n]s",&d,n);
	r->data=d;
	strcpy(r->name,n);
	r->link=head;
	while(1)
	{
		printf("Do you want to continue (Y/N): ");
		scanf("%s",x);
		if(strcmp(x,"N")==0)
			break;
		q=(node *)malloc(sizeof(node));
		if(q==NULL)
			printf("Overflow.\n");
		else
		{
			printf("%d. Enter roll and name: ",i);
			scanf("%d %[^\n]s",&d,n);
			q->data=d;
			strcpy(q->name,n);
			q->link=head;
			p->link=q;
			p=p->link;
			i++;
		}
	}
	p->link=head;
}
void dsp()
{
	if(head->link==head)
		printf("List is empty.\n");
	else
	{
		node *p=head->link;
		while(p!=head)
		{
			printf("Roll: %d \t Name: %s\n",p->data,p->name);
			p=p->link;
		}
	}
}
void insert()
{
	node *newNode,*p,*loc;
	newNode=(node *)malloc(sizeof(node));
	int item;
	int d;
	char n[20];
	printf("Enter the item after which the new node will be inserted: ");
	scanf("%d",&item);
	printf("Enter roll and name: ");
	scanf("%d %[^\n]s",&d,n);
	newNode->data=d;
	strcpy(newNode->name,n);
	p=head->link;
	while(p!=head)
	{
		if(p->data==item)
		{
			loc=p;
			break;
		}
		else
			p=p->link;
	}
	if(p==head)
		loc=p;
	if(loc==head)
	{
		newNode->link=head->link;
		head->link=newNode;
	}
	else
	{
		newNode->link=loc->link;
		loc->link=newNode;
	}
}
void del()
{
	int item;
	printf("Enter the item you want to delete: ");
	scanf("%d",&item);
	node *p=head->link,*loc,*save;
	if(item==p->data)
	{
		head->link=p->link;
		free(p);
	}
	else
	{
		while(p!=head)
		{
			if(p->data==item)
			{
				loc=p;
				break;
			}
			else
			{
				save=p;
				p=p->link;
			}
		}
		save->link=loc->link;
		free(loc);
	}
}
void search()
{
	int key;
	printf("Enter item to search: ");
	scanf("%d",&key);
	node *p=head->link,*loc;
	while(p!=head)
	{
		if(p->data==key)
		{
			loc=p;
			break;
		}
		else
			p=p->link;
	}
	if(p==head)
		loc=NULL;
	if(loc==NULL)
		printf("Item not found.\n");
	else
		printf("Roll: %d \t Name: %s\n",loc->data,loc->name);
}
