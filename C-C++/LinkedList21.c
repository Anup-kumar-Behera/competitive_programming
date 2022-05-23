#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int data;
	struct node *link;
}node;
node *head;
void createLinkedList();
void dsp();
void mid();

main()
{
	createLinkedList();
	dsp();
	mid();
}
void createLinkedList()
{
	node *p,*q;
	head=(node *)malloc(sizeof(node));
	p=head;
	char x[5];
	int d,i=2;
	if(p==NULL)
		printf("\nOverflow.\n");
	else
	{
		printf("1. Enter data: ");
		scanf("%d",&d);
		p->data=d;
		p->link=NULL;
		while(1)
		{
			printf("Do you want to continue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("\nOverflow.\n");
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
void dsp()
{
	if(head==NULL)
		printf("\nList is empty.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("data: %d\n",p->data);
			p=p->link;
		}
	}
}
void mid()
{
	node *slow=head,*fast=head;
	while(fast!=NULL)
	{
		slow=slow->link;
		fast=fast->link->link;
	}
	printf("\ndata: %d\n",slow->data);
}

