#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int data;
	struct node *link;
}node;
node *head=NULL,*p,*q;
void push(int );
int pop();
//int empty();
//nt full();

main()
{
	int data;
	int n;
	do
	{
		printf("\n1 to push.\n");
		printf("2 to pop.\n");
		printf("0 to stop.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("Enter data to insert: ");
			scanf("%d",&data);
			push(data);
		}
		else
		if(n==2)
		{
			if(data==0)
			{
				printf("stack is empty.\n");
				continue;
			}
			else
			{
				data=pop();
				printf("%d\n",data);
			}
		}
	}while(n!=0);
}
void push(int data)
{
	if(head==NULL)
	{
		node *head=(node *)malloc(sizeof(node));
		head->data=data;
		head->link=NULL;
	}
	else
	{
		p=(node *)malloc(sizeof(node));
		p->data=data;
		p->link=head;
		head=p;
	}
}
int pop()
{
	int k=head->data;
	q=head;
	head=head->link;
	free(q);
	if(head==NULL)
		return 0;
	else
		return k;
}
