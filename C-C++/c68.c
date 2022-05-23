#include<stdio.h>
#include<stdlib.h>
#include"string.h"

typedef struct node{
	int data;
	struct node *link;
}node;

node *head=0,*q=0;
void cl();
void dsp();
void segregate();

main()
{
	int n;
	do
	{
		printf("\nEnter 1 to insert data: \n");
		printf("Enter 2 to display data: \n");
		printf("Enter 3 to segregate data: \n");
		printf("Enter 0 to stop: \n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			cl();
		}
		else if(n==2)
		{
			dsp();
		}
		else if(n==3)
		{
			segregate();
		}
	}while(n!=0);
}
void cl()
{
	if(head==0)
	head=(node *)malloc(sizeof(node));
	node *p=head;
	int data,i=2;
	char x[5];
	if(p==0)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter data: ");
		scanf("%d",&data);
		p->data=data;
		p->link=0;
		while(1)
		{
			printf("Do you want to continue (Y/N):");
			scanf("%s",x);
			if((strcmp(x,"N"))==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==0)
				printf("Overflow.\n");
			else
			{
				printf("%d. Enter data: ",i);
				scanf("%d",&data);
				q->data=data;
				q->link=0;
				p->link=q;
				p=p->link;
				i++;
			}
		}
		p->link=0;
	}
}
void dsp()
{
	if(head==0)
		printf("Underflow.\n");
	else
	{
		node *p=head;
		while(p!=0)
		{
			printf("%d ",p->data);
			p=p->link;
		}
	}
}
void segregate()
{
	node *p=head;
	int s=100;
	int x[s],y[s],t1=0,t2=0;
	while(p!=0)
	{
		if((p->data)%2==0)
		{
			t1++;
			x[t1]=p->data;
		}
		else
		{
			t2++;
			y[t2]=p->data;
		}
	}
	p=head;
	while(p!=0)
	{
		p->data=x[t1];
		t1--;
		p=p->link;
	}
	while(p!=0)
	{
		p->data=y[t2];
		t2--;
		p=p->link;
	}
}
