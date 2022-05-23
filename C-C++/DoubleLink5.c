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
void dsp();
void dspBack();
void del();
void insert();

main()
{
	printf("Enter 1 to createList.\n");
	printf("Enter 2 to display list.\n");
	printf("Enter 3 to del item from the list.\n");
	printf("Enter 4 to insert in the list after a given item.\n");
	printf("Enter 5 to display list from back.\n");
	printf("Enter 0 to exit.\n");
	
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
			case 2: dsp();
					break;
			case 3: del();
					break;
			case 4: insert();
					break;
			case 5: dspBack();
					break;
		}
	}while(a!=0);
}
void createList()
{
	node *p,*q;
	int d,i=2;
	char x[5];
	head=(node *)malloc(sizeof(node));
	p=head;
	if(p==NULL)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter data: ");
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
				printf("%d. Enter data: ",i);
				scanf("%d",&d);
				q->data=d;
				q->back=p;
				p->forw=q;
				q->forw=NULL;
				p=p->forw;
				last=p;
				i++;
			}
		}
		p->forw=NULL;
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
			printf("Data: %d\n",p->data);
			p=p->forw;
		}
	}
}
void dspBack()
{
	if(last==NULL)
		printf("Underflow.\n");
	else
	{
		node *p=last;
		while(p!=NULL)
		{
			printf("Data: %d\n",p->data);
			p=p->back;
		}
	}
}
void insert()
{
	int item,d;
	node *p=head,*newNode,*loc;
	newNode=(node *)malloc(sizeof(node));
	
	if(newNode==NULL)
		printf("Overflow.\n");
	else
	{
		printf("Enter item after which new Node will be inserted: ");
		scanf("%d",&item);
		printf("Enter data: ");
		scanf("%d",&d);
		newNode->data=d;
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
		{
			newNode->forw=head;
			newNode->back=NULL;
			head->back=newNode;
			head=newNode;
		}
		else
		{
			newNode->forw=loc->forw;
			loc->forw->back=newNode;
			newNode->back=loc;
			loc->forw=newNode;
		}
	}
}
void del()
{
	int item;
	node *p=head,*loc,*save;
	printf("Enter item to delete from the list: ");
	scanf("%d",&item);
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
