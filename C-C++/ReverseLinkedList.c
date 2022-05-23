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
void del();
void rev();

main()
{
	createLinkedList();
	dsp();
	printf("\n------------------------------------------------------------------------------------------\n");\
	printf("\nLinkedList after reversed:\n");
	rev();
}
void createLinkedList()
{
	node *p,*q;
	int data,i=2;
	char n[20],x[5];
	head=(node *)malloc(sizeof(node));
	p=head;
	if(p==NULL)
		printf("\nMemory can not be allocated.\n");
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
			p=p->link;
		}
	}
}
void del()
{
	node *p=head,*loc=NULL,*save;
	int r;
	printf("Enter roll no to delete: ");
	scanf("%d",&r);
	if(r==head->roll)
	{
		head=head->link;
		free(p);
	}
	while(p!=NULL)
	{
		if(r==p->roll)
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

void rev()
{
	node *p=head,*next,*pre=NULL;
	while(p!=0)
	{
		next=p->link;
		p->link=pre;
		pre=p;
		p=next;
	}
	while(pre!=NULL)
	{
		printf("Roll: %d \t Name: %s\n",pre->roll,pre->name);
		pre=pre->link;
	}
}
