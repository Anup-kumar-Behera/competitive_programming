#include"stdio.h"
#include"stdlib.h"

typedef struct node{
	struct node *back;
	int data;
	struct node *forw;
}node;
node *head;
void createList();
void dsp1();
void dsp2();

main()
{
	createList();
	dsp1();
	dsp2();
}
void createList()
{
	head=(node *)malloc(sizeof(node));
	node *p,*q;
	p=head;
	int d;
	char x[5];
	if(p==NULL)
		printf("Overflow.\n");
	else
	{
		printf("Enter data: ");
		scanf("%d",&d);
		p->data=d;
		p->back=NULL;
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
				printf("Enter data: ");
				scanf("%d",&d);
				q->data=d;
				q->back=p;
				q->forw=NULL;
				p->forw=q;
				p=q;
			}
		}
		p->forw=NULL;
	}		
}
void dsp1()
{
	node *p=head;
	while(p->forw!=NULL)
	{
		printf("Data: %d \n",p->data);
		p=p->forw;
	}
}
void dsp2()
{
	node *p=head;
	while(p->back!=NULL)
	{
		printf("Data: %d \n",p->data);
		p=p->back;
	}
}
