#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *head=NULL;
void push(int );
int pop();
int empty();

main()
{
	int n,data;
	do
	{
		printf("\n1 to push data.\n");
		printf("2 to pop data.\n");
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
	node *p,*q;
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		p=head;
		head->data=data;
		head->link=NULL;
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
	node *p=head,*loc;
	while(p!=NULL)
	{
		loc=p;
		p=p->link;
	}
	int k=p->data;
	loc->link=NULL;
	free(p);
	p=loc;
	return k;
}
int empty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}
