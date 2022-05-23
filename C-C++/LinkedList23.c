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
void nthNodeFromEnd();
main()
{
	int a;
	printf("Enter 1 to createList.\n");
	printf("Enter 2 to disply list.\n");
	printf("Enter 3 to display nth node from the end.\n");
	printf("Enter 0 to exit.\n\n");
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
			case 3: nthNodeFromEnd();
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
void nthNodeFromEnd()
{
	int n;
	printf("Enter nth node from the end: ");
	scanf("%d",&n);
	node *p=NULL,*q=NULL;
	int i=0;
	for(p=head;p!=NULL;)
	{
		i++;
		if(n-i==0)
			q=head;
		else if(n-i>0)
			q=q->link;
		p=p->link;
	}
	if(q==NULL)
		printf("Node not found.\n");
	else
		printf("Data: %d\n",q->data);
}
