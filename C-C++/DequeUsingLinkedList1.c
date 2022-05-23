#include"stdio.h"
#include"stdlib.h"

int popFront();
int popEnd();
void InsertFront(int );
void InsertEnd(int );
int empty();
typedef struct node{
	int data;
	struct node *link;
}node;
node *head=NULL,*p=NULL,*q=NULL,*last=NULL;


main()
{
	int n,data;
	do
	{
		printf("\n1 to push data at front end.\n");
		printf("2 to push data at end.\n");
		printf("3 to delete from front end.\n");
		printf("3 to delete from end.\n");
		printf("0 to quit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("Enter data: ");
			scanf("%d",&data);
			InsertFront(data);
		}
		else if(n==2)
		{
			printf("Enter data: ");
			scanf("%d",&data);
			InsertEnd(data);
		}
		else if(n==3)
		{
			if(empty())
			{
				printf("Underflow.\n");
				continue;
			}
			data=popFront();
			printf("%d",data);
		}
		else if(n==4)
		{
			if(empty())
			{
				printf("Underflow.\n");
				continue;
			}
			data=popEnd();
			printf("%d",data);
		}
	}while(n!=0);
}
void InsertEnd(int data)
{
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		last=head;
		last->data=data;
		last->link=NULL;
	}
	q=(node *)malloc(sizeof(node));
	q->data=data;
	q->link=NULL;
	last->link=q;
	last=last->link;
}
void InsertFront(int data)
{
	p=(node *)malloc(sizeof(node));
	p->data=data;
	p->link=head;
	head=p;
}
int popFront()
{
	node *f;
	int k=head->data;
	f=head;
	head=head->link;
	free(f);
	return k;
}
int popEnd()
{
	node* save=NULL,*k=head;
	while(k!=NULL)
	{
		save=k;
		k=k->link;
	}
	int d=k->data;
	k->link=NULL;
	free(k);
	return d;
}
int empty()
{
	if(head==NULL)
		return 1;
	else 		
		return 0;
}
