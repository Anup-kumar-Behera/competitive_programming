#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;

node *head;

void createList();
void dsp();
void insert();
void del();
void delOccurences();

main()
{
	int a;
	printf("Enter 1 to createList.\n");
	printf("Enter 2 to display.\n");
	printf("Enter 3 to insert item after a given node.\n");
	printf("Enter 4 to delete an item.\n");
	printf("Enter 5 to delete occurences.\n");
	printf("Enter 0 to exit.\n");
	
	do
	{
		printf("Enter choice: ");
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
			case 5: delOccurences();
					break;
		}
	}while(a!=0);
}
void createList()
{
	node *p,*q;
	int data,i=2;
	char n[20],x[5];
	head=(node *)malloc(sizeof(node));
	p=head;
	if(p==NULL)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter roll and name: ");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		p->link=NULL;
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
				scanf("%d %[^\n]s",&data,n);
				q->roll=data;
				strcpy(q->name,n);
				q->link=NULL;
				p->link=q;
				p=p->link;
				i++;	
			}
		}
		p->link=NULL;
	}
}
void dsp()
{
	if(head==NULL)
		printf("Underflow.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Roll: %d\t Name: %s\n",p->roll,p->name);
			p=p->link;
		}
	}
}
void insert()
{
	int item;
	int data;
	char n[20];
	node *newNode,*p=head,*loc;
	newNode=(node *)malloc(sizeof(newNode));
	if(newNode==NULL)
		printf("Overflow.\n");
	else
	{
		printf("Enter item after which newNode will be inserted: ");
		scanf("%d",&item);
		printf("Enter roll and name: ");
		scanf("%d %[^\n]s",&data,n);
		newNode->roll=data;
		strcpy(newNode->name,n);
		while(p!=NULL)
		{
			if(p->roll==item)
			{
				loc=p;
				break;
			}
			else
				p=p->link;
		}
		if(p==NULL)
			loc=NULL;
		if(loc==NULL)
		{
			newNode->link=head;
			head=newNode;
		}
		else
		{
			newNode->link=loc->link;
			loc->link=newNode;
		}
	}
}
void del()
{
	int roll;
	printf("Enter roll to delete: ");
	scanf("%d",&roll);
	node *p=head,*loc,*save;
	if(p->roll==roll)
	{
		head=p->link;
		free(p);
		p=head;
	}
	else
	{
		while(p!=NULL)
		{
			if(p->roll==roll)
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
		if(p==NULL)
			loc=NULL;
		if(loc==NULL)
			printf("Item not Found.\n");
		else
		{
			save->link=loc->link;
			free(loc);
		}
	}
}
void delOccurences()
{
	int item;
	printf("Enter item to delete all occurences: ");
	scanf("%d",&item);
	node *p=head,*save;
	while(p!=NULL && p->roll==item)
	{
		head=p->link;
		free(p);
		p=head;
	}
	while(p!=NULL)
	{
		while(p!=NULL && p->roll!=item)
		{
			save=p;
			p=p->link;
		}
		save->link=p->link;
		free(p);
		p=save->link;
	}
}
