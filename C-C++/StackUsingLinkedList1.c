#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;
	struct node *link;
}node;
node *sp=0,*q;

void push(int );
int pop();
int empty();

main()
{
	int n,data;
	do
	{
		printf("\n1 for push.\n");
		printf("2 form pop.\n");
		printf("0 to dtop.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("enter data to insert: ");
			scanf("%d",&data);
			push(data);
		}
		else if(n==2)
		{
			if(empty())
			{
				printf("stack is empty.\n");
				continue;
			}
			data=pop();
			printf("%d\n",data);
		}
	}while(n!=0);
}
void push(int data)
{
	if(sp==0)
	{
		sp=(node *)malloc(sizeof(node));
		sp->data=data;
		sp->link=0;
	}
	else
	{
		q=(node *)malloc(sizeof(node));
		q->data=data;
		q->link=sp;
		sp=q;
	}
}
int pop()
{
	int k=sp->data;
	q=sp->link;
	free(sp);
	sp=q;
	return k;
}
int empty()
{
	if(sp==0)
		return 1;
	else
		return 0;
}
