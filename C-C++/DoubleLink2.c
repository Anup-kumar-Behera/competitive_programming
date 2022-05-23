#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	struct node *back;
	int data;
	struct node *forw;
}node;

node *start;
node *last;
void createList();
void dsp();
void revDsp();

main()
{
	createList();
	dsp();
	printf("\n\n");
	revDsp();
}
void createList()
{
	start=(node *)malloc(sizeof(node));
	node *p,*q;
	p=start;
	int i=2,d;
	char x[5];
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
				q->forw=NULL;
				p->forw=q;
				p=p->forw;
				last=p->back->forw;
				i++;
			}
		}
		p->forw=NULL;
	}
}
void dsp()
{
	if(start==NULL)
		printf("List is empty.\n");
	else
	{
		node *p=start;
		while(p!=NULL)
		{
			printf("Data: %d\n",p->data);
			p=p->forw;
		}
	}
}
void revDsp()
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
