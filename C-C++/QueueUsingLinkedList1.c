#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *head=NULL;
node *q=NULL,*p;
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
		printf("0 to stop.\n");
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
		head->data=data;
		head->link=NULL;
	}
	else
	{
		q=(node *)malloc(sizeof(node));
		q->data=data;
		p->link=q;
		p=q;
		q->link=NULL;
	}
}
int pop()
{
	int k=head->data;
	node *p=head;
	head=head->link;
	free(p);
	return k;
}
int empty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}
