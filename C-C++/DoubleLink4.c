#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	struct node *back;
	int data;
	struct node *forw;
}node;
node *head;
node *last;
void createList();
void dsp1();
void dsp2();
void insert();
void del();
void search();
void delOccurences();

main()
{
	int a;
	
	printf("Enter 1 to createList.\n");
	printf("Enter 2 to dispaly list from left to right.\n");
	printf("Enter 3 to display list from right to left.\n");
	printf("Enter 4 to insert new node.\n");
	printf("Enter 5 to del a node from the list.\n");
	printf("Enter 6 to delete Occurences of an item.\n");
	printf("Enter 7 to search for an element.\n");
	printf("Enter 0 to stop.\n\n");
	do
	{
		printf("Enter your choice: ");
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
			case 6: delOccurences();
					break;
			case 7: search();
					break;
		}
	}while(a!=0);
}
void createList()
{
	node *p,*q;
	head=(node *)malloc(sizeof(node));
	p=head;
	int d,i=2;
	char x[5];
	if(p==NULL)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter Data: ");
		scanf("%d",&d);
		p->data=d;
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
				printf("%d. Enter Data: ",i);
				scanf("%d",&d);
				q->data=d;
				q->back=p;
				p->forw=q;
				q->forw=NULL;
				p=p->forw;
				//last=p->back->forw;
				last=p;
				i++;
			}
		}
		p->forw=NULL;
	}
}
void dsp1()
{
	if(head==NULL)
		printf("Underflow.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Data: %d \n",p->data);
			p=p->forw;
		}
	}
}
void dsp2()
{
	if(last==NULL)
		printf("Underflow.\n");
	else
	{
		node *p=last;
		while(p!=NULL)
		{
			printf("Data: %d \n",p->data);
			p=p->back;
		}
	}
}
void insert()
{
	int item,d;
	node *q;
	q=(node *)malloc(sizeof(node));
	if(q==NULL)
		printf("Overflow.\n");
	else
	{
		printf("Enter item after which you want to insert: ");
		scanf("%d",&item);
		printf("Enter data to insert : ");
		scanf("%d",&d);
		q->data=d;
		node *p=head,*loc;
		while(p!=NULL)
		{
			if(p->data==item)
			{
				loc=p;
				break;
			}
			else
			{
				p=p->forw;
			}
		}
		if(p==NULL)
			loc=p;
		if(loc==NULL)
		{
			q->back=NULL;
			head->back=q;
			q->forw=head;
			head=q;
		}
		else
		{
			q->forw=loc->forw;
			q->back=loc;
			loc->forw->back=q;
			loc->forw=q;
		}
	}
}
void del()
{
	int item;
	printf("Enter item to delete: ");
	scanf("%d",&item);
	node *p=head,*loc,*save;
	if(p->data==item)
	{
		head=p->forw;
		head->back=NULL;
		free(p);
		p=head;
		
	}
	else
	{
		while(p!=NULL)
		{
			if(p->data==item)
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
			loc=p;
		if(loc==NULL)
			printf("Item not found.\n");
		else
		{
			save->forw=loc->forw;
			loc->forw->back=save;
			free(loc);
		}
	}
}
void delOccurences()
{
	int item;
	printf("Enter item to delete: ");
	scanf("%d",&item);
	node *p=head,*loc=NULL,*save=NULL;
	while(p!=NULL && p->data==item)
	{
		head=p->forw;
		p->back=NULL;
		free(p);
		p=head;
	}
	while(p!=NULL)
	{
		while(p!=NULL && p->data!=item)
		{
			save=p;
			p=p->forw;
		}
		save->forw=p->forw;
		p->forw->back=save;
		free(p);
		p=save->forw;
	}
}
void search()
{
	int item;
	printf("Enter item to search: ");
	scanf("%d",&item);
	node *p=head,*loc;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			loc=p;
			break;
		}
		else
			p=p->forw;
	}
	if(p==NULL)
		loc=p;
	if(loc==NULL)
		printf("Item not found.\n");
	else
	{
		printf("Item found.\n");
	}
}
