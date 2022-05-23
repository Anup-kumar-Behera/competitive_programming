#include"stdio.h"
#include"stdlib.h"
int pop();
void push(int );
int empty();
int traverse();
int full();

struct node{
	int data;
	struct node *link;
};
struct node *r=0,*f=0,*q,*m;
main()
{
	int n,data;
	do
	{
		printf("\n1 for insert.\n");
		printf("2 for remove.\n");
		printf("3 for traverse.\n");
		printf("0 to stop.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("Enter data to insert: ");
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
		else if(n==3)
		{
			if(empty())
			{
				printf("Underflow.\n");
				continue;
			}
			traverse();
		}
	}while(n!=0);
}
void push(int data)
{
	if(r==0)
	{
		r=(struct node *)malloc(sizeof(struct node));
		r->data=data;
		r->link=0;
		f=r;
	}
	else if(data<r->data)
	{
		q=(struct node *)malloc(sizeof(struct node));
		q->link=r;
		q->data=data;
		r=f=q;
	}
	else
	{
		while(r!=0 && data>=r->data)
		{
			m=r;
			m=r->link;
		}
		q=(struct node *)malloc(sizeof(struct node));
		q->data=data;
		m->link=q;
		q->link=r;
		r=f;
	}
}
int traverse()
{
	q=f;
	while(q!=0)
	{
		printf("%d",q->data);
		q=q->link;
	}
}
int pop()
{
	int k=f->data;
	q=f->link;
	free(f);
	f=r=q;
	return k;
}
int empty()
{
	if(f==0)
		return 1;
	else
		return 0;
}
