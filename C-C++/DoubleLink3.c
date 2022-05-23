#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	struct node *back;
	int data;
	char name[20];
	struct node *forw;
}node;
node *start;
node *last;

void createList();
void dsp1();
void dsp2();
void insert();
void del();
void search();

main()
{
	printf("Enter '1' to createList.\n");
	printf("Enter '2' to display from 1st node to last node.\n");
	printf("Enter '3' to display from last node to first node.\n");
	printf("Enter '4' to insert element after a given data element.\n");
	printf("Enter '5' to delete a node.\n");
	printf("Enter '6' to search data.\n");
	printf("Enter '0' to stop.\n\n");
	
	int a;
	do
	{
		printf("Enter choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 0: break;
			
			case 1: createList();
					break;
			case 2: dsp1();
					break;
			case 3: dsp2();
					break;
			case 4: insert();
					break;
			case 5: del();
					break;
			case 6: search();
					break;
		}
	}while(a!=0);
}
void createList()
{
	start=(node *)malloc(sizeof(node));
	node *p,*q;
	p=start;
	int d,i=2;
	char x[5],n[20];
	if(p==NULL)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter Roll and Name:  ");
		scanf("%d %[^\n]s",&d,n);
		p->data=d;
		strcpy(p->name,n);
		p->back=NULL;
		last=p->back;
		p->forw=NULL;
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
				printf("%d. Enter Roll and Name: ",i);
				scanf("%d %[^\n]s",&d,n);
				q->data=d;
				strcpy(q->name,n);
				q->back=p;
				p->forw=q;
				q->forw=NULL;
				p=p->forw;
				last=p->back->forw;
				i++;
			}
		}
		p->forw=NULL;
	}
}
void dsp1()
{
	if(start==NULL)
		printf("Underflow.\n");
	else
	{
		node *p=start;
		while(p!=NULL)
		{
			printf("Roll: %d\t Name: %s\n",p->data,p->name);
			p=p->forw;
		}
	}
}
void dsp2()
{
	if(last==NULL)
		printf("underflow.\n");
	else
	{
		node *p=last;
		while(p!=NULL)
		{
			printf("Roll: %d\t Name: %s\n",p->data,p->name);
			p=p->back;
		}
	}
}
void del()
{
	int roll;
	node *loc,*save;
	printf("Enter roll no to delete: ");
	scanf("%d",&roll);
	node *p=start;
	while(p!=NULL)
	{
		if(p->data==roll)
		{
			loc=p;
			break;
		}
		else
		{
			save=p;
			p=p->forw;
		}
	}
	if(p==NULL)
	{
		loc=p;
		printf("Entered item not found in the list.\n");
	}
	else
	{
		save->forw=loc->forw;
		loc->forw->back=save;
	}
}
void insert()
{
	node *newNode;
	int d;
	char n[200];
	int k;
	node *loc;
	printf("Enter roll after which you want to insert a new node: ");
	scanf("%d",&k);
	node *p=start;
	while(p!=NULL)
	{
		if(p->data==k)
		{
			loc=p;
			break;
		}
		else
		{
			p=p->forw;
		}
	}
	newNode=(node *)malloc(sizeof(node));
	if(newNode==NULL)
		printf("Overflow.\n");
	else
	{
		printf("Enter Roll and Name: ");
		scanf("%d %[^\n]s",&d,n);
		newNode->data=d;
		strcpy(newNode->name,n);
		newNode->back=loc;
		newNode->forw=loc->forw;
		loc->forw->back=newNode;
		loc->forw=newNode;
	}
}
void search()
{
	node *p=start;
	int d;
	node *loc;
	printf("Enter roll no to search: ");
	scanf("%d",&d);
	while(p!=NULL)
	{
		if(p->data==d)
		{
			loc=p;
			break;
		}	
		else
			p=p->forw;
	}
	printf("Roll: %d\t Name: %s\n",loc->data,loc->name);
}
