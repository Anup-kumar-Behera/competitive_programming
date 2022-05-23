#include"stdio.h"
void push(int );
int pop();
int full();
int empty();
	int x[5];
	int f=0,r=0;

main()
{
	int n,data;
	do
	{
		printf("\n1 to push data into queue.\n");
		printf("2 to pop data from queue.\n");
		printf("0 to quit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			if(full())
			{
				printf("Queue is full.\n");
				continue;
			}
			printf("Enter data: ");
			scanf("%d",&data);
			push(data);
		}
		else if(n==2)
		{
			if(empty())
			{
				printf("Queue is empty.\n");
				continue;
			}
			data=pop();
			printf("%d ",data);
		}
	}while(n!=0);
}
void push(int data)
{
	if(r==0)
	{
		f=1;
		r=1;
	}
	else
	{
		r=(r%5)+1;
	}
	x[r]=data;
}
int pop()
{
	int k=x[f];
	if(f==r)
		f=r=0;
	else
		f=(f%5)+1;
	return k;
}
int empty()
{
	if(f==0)
		return 1;
	else
		return 0;
}
int full()
{
	if(f==(r%5)+1)
		return 1;
	else
		return 0;
}
