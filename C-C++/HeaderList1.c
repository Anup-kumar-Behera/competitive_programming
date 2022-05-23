#include"stdio.h"
#include"string.h"
#include"stdlib.h"

typedef struct node{
	int data;
	struct node *link;
}node;

node *head;
void createList();
void dsp();

main()
{
	createList();
	dsp();
}
void createList()
{
	node *p,*q;
	head=(node *)malloc(sizeof(node));
	p=(node *)malloc(sizeof(node));
	head->link=p;
	node *r=p;
	if(head==NULL)
		printf("Overflow.\n");
	if(p==NULL)
		printf("Overflow.\n");
	int d;
	char x[5];
	int i=2;
	printf("1. Enter data: ");
	scanf("%d",&d);
	r->data=d;
	r->link=NULL;
	while(1)
	{
		//sleep(1);
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
			q->link=NULL;
			r->link=q;
			r=r->link;
			i++;
		}
	}
	r->link=NULL;
}
void dsp()
{
	if(head->link==NULL)
		printf("Underflow.\n");
	else
	{
		node *p=head->link;
		while(p!=NULL)
		{
			printf("Data: %d\n",p->data);
			p=p->link;
		}
	}
}
