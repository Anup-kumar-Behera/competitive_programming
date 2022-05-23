#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *head;
void createList(node *);
void dsp(node *);
void reverse(node *);
void del(node *);

main()
{
	head=(node *)malloc(sizeof(node));
	int a=100;
	printf("Enter the following choices.\n");
	printf("1 to createeList.\n");
	printf("2 to display.\n");
	printf("3 to reverse.\n");
	printf("4 to delete.\n");
	printf("0 to exit.\n\n");
	while(a!=0)
	{
		printf("Enter choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 0: break;
				
			case 1:createList(head);
					break;
			case 2:dsp(head);
					break;
			case 3:reverse(head);
					break;
			case 4:del(head);
					break;
		}
	}
}
void createList(node *head)
{
	node *p,*q;
	p=head;
	int d,i=2;
	char x[5];
	if(p==NULL)
		printf("Memory can not be allocated.\n");
	else
	{
		printf("1. Enter data: ");
		scanf("%d",&d);
		p->data=d;
		p->link=NULL;
		while(1)
		{
			printf("Do you wnat to continue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)	
				printf("Memory can not be allocated.\n");
			else
			{
				printf("%d. Enter data: ",i);
				scanf("%d",&d);
				q->data=d;
				q->link=NULL;
				p->link=q;
				p=p->link;
				i++;
			}
		}
		p->link=NULL;
	}
}
void dsp(node *head)
{
	if(head==NULL)
		printf("List is empty.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Data: %d\n",p->data);
			p=p->link;
		}
	}
}
void reverse(node *head)
{
	node *pre=NULL,*next=NULL,*p=head;
	while(p!=NULL)
	{
		next=p->link;
		p->link=pre;
		pre=p;
		p=next;
	}
	head=pre;
	while(pre!=NULL)
	{
		printf("Data: %d\n",pre->data);
		pre=pre->link;
	}
}
void del(node *head)
{
	node *p=head,*loc,*save;
	int item;
	printf("Enter item to delete: ");
	scanf("%d",&item);
	while(p!=NULL)
	{
		if(p->data==item)
		{
			loc=p;
			save->link=p;
			p=loc->link;
			free(loc);			
		}
		save=p;
		p=p->link;
	}
}
