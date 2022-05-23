#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *head=NULL,*q=NULL;
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
	q=(node *)malloc(sizeof(node));
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		p=head;
		p->data=data;
		p->link=NULL;
	}
	//	q=(node *)malloc(sizeof(node));
		q->data=data;
		q->link=NULL;
		p->link=q;
}
int pop()
{
	node *p=head,*loc;
	while(p!=NULL)
	{
		loc=p;
		p=p->link;
	}
	loc->link=NULL;
	int k=p->data;
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
