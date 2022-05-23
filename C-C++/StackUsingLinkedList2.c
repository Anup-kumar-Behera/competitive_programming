#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *head=NULL,*q;
int top=-1;
void push(int );
int pop();
//int full();
int empty();

main()
{
	int data,n;
	do
	{
		printf("\n1 ot push data.\n");
		printf("2 to pop data.\n");
		printf("0 to quit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
		/*	if(full())
			{
				printf("Overflow.\n");
				continue;
			}*/
			printf("Enter data: ");
			scanf("%d",&data);
			push(data);
		}
		else if(n==2)
		{
			if(empty())
			{
				printf("Underflow.\n");
				continue;
			}
			data=pop();
			printf("%d",data);
		}
	}while(n!=0);
}
void push(int data)
{
	node *p,*q;
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		p=head;
		p->data=data;
		p->link=NULL;
	}
	else
	{
		q=(node *)malloc(sizeof(node));
		q->data=data;
		q->link=NULL;
		p->link=q;
		p=q;
	}
}
int pop()
{
	node *p=head,*save;
	while(p!=NULL)
	{
		save=p;
		p=p->link;
	}
	int k=save->data;
	save->link=NULL;
	free(p);
	p=save;
	return k;
}
int empty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}
/*int full()
{
	if(q==NULL)
		return 1;
	else
		return 0;
}*/
