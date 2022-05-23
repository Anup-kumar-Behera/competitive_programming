#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int roll;
	char name[20];
	struct node *next;
}node;

node *head;
void createLinkedList();
void dsp();
void search(int );

main()
{
	createLinkedList();
	dsp();
	int key;
	printf("Enter roll no to search:");
	scanf("%d",&key);
	search(key);
}
void createLinkedList()
{
	node *p,*q;
	head=(node *)malloc(sizeof(node));
	p=head;
	int data,i=2;
	char n[20],x[5];
	if(p==NULL)
		printf("\nMemory can not be allocated.\n");
	else
	{
		printf("1. Enter roll and name: ");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		p->next=NULL;
		while(1)
		{
			printf("Do you wnat to continue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("\nMemory can not be allocated.\n");
			else
			{
				printf("%d. Enter roll and name: ",i);
				scanf("%d %[^\n]s",&data,n);
				q->roll=data;
				strcpy(q->name,n);
				q->next=NULL;
				p->next=q;
				p=p->next;
			}
		}
		p->next=NULL;
	}
}
void dsp()
{
	if(head==NULL)
		printf("\nList is empty.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Roll: %d \t Name: %s\n",p->roll,p->name);
			p=p->next;
		}
	}
}
void search(int key)
{
	node *p=head,*loc;
	while(p!=NULL)
	{
		if(key==p->roll)
		{
			loc=p;
			break;
		}
		else
			p=p->next;
	}
	if(p==NULL)
		loc=NULL;
	if(loc==NULL)
		printf("\nItem not found!\n");
	else
	{
		printf("\nSearch results for:\n");
		printf("Roll: %d \t Name: %s\n",loc->roll,loc->name);
	}
}
