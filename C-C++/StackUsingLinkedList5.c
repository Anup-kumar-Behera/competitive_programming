#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *head=NULL,*q=NULL,*p;
void push(int );
int pop();
int empty();

main()
{
	int data,n;
	do
	{
		printf("\n1 to push.\n");
		printf("2 to pop.\n");
		printf("0 to quit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
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
	node *r=head,*loc;
	while(r!=NULL)
	{
		loc=r;
		r=r->link;
	}
	int k=r->data;
	loc->link=NULL;
	free(r);
	return k;
}
int empty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}
