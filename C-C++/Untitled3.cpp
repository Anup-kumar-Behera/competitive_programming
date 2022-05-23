#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *head;
void createList();
void dsp();
void rev();
main()
{
	int a=100;
	printf("Enter 1 to createList.\n");
	printf("Enter 2 to disply list.\n");
	printf("Enter 3 to reverse the list.\n");
	printf("Enter 0 to exit.\n\n");
	while(a!=0)
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
			case 3: rev();
					break;
		}
	}
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
		printf("1. Enter data: ");
		scanf("%d",&d);
		p->data=d;
		p->link=NULL;
		while(1)
		{
			printf("Do you want tc continue (Y/N): ");
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
void rev()
{
	node *pre=NULL,*next=NULL;
	while(head)
	{
		next=head->link;
		head->link=pre;
		pre=head;
		head=next;
	}
	head=pre;
	while(pre!=NULL)
	{
		printf("Data: %d\n",pre->data);
		pre=pre->link;
	}
}
