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

main()
{
	createLinkedList();
	dsp();
	del();
	dsp();
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
			if(q==NULL)
				printf("\nMemory can not be allocted.\n");
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
	node *p=head,*loc,*d;
	int r,i=0,j;
	printf("Enter roll no to delete:");
	scanf("%d",&r);
	while(p!=NULL)
	{
		i++;
		if(r==p->roll)
		{
				loc=p;
				j=i-1;
				break;
		}
		else
			p=p->link;
	}
	while(p!=NULL)
	{	i++;
		if(j==i)
		{
				d=p;
				break;
		}
		else
			p=p->link;		
	}
	d->link=loc->link;
	free(loc);
}
