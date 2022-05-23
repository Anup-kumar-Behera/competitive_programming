#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;

node *head;
void createLinkedList();
void dsp();
void insert();

main()
{
	createLinkedList();
	dsp();
	insert();
	dsp();
}
void createLinkedList()
{
	node *p,*q;
	head=(node *)malloc(sizeof(node));
	p=head;
	int data,i=2;
	char n[20],x[5];
	if(p==NULL)
		printf("\nOVERFLOW .\n");
	else
	{
		printf("1. Enter roll and name :");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		p->link=NULL;
		while(1)
		{
			printf("Do you want to continue (Y/N):");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("\nOVERFLOW. \n");
			else
			{
				printf("%d. Enter roll and name :",i);
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
		printf("\nUNDERFLOW (List is empty).\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Roll: %d \t Name: %s\n",p->roll,p->name);
			p=p->link;
		}
	}
}
void insert()
{
	node *p;
	int data;
	char n[20];
	p=(node *)malloc(sizeof(node));
	if(p==NULL)
		printf("OVERFLOW\n");
	else
	{
		printf("  Enter roll and name :");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		p->link=head;
		head=p;
	}
}
