#include"stdio.h"
int pop();
int empty();
int full();
void push(int );

int x[5];
int f=0,r=0,l=5;

main()
{
	int n,data;
	do
	{
		printf("\n1 to push.\n");
		printf("2 to pop.\n");
		printf("0 to quit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			if(full())
			{
				printf("Overflow.\n");
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
	if(r==0)
	{
		r=f=1;
	}
	else
	{
		r=(r%l)+1;
	}
	x[r]=data;
}
int empty()
{
	if(f==0)
		return 1;
	else 	
		return 0;
}
int pop()
{
	int k=x[f];
	if(f==r)	
		f=r=0;
	else
		f=(f%l)+1;
	return k;
}
int full()
{
	if(f==(r%l)+1)
		return 1;
	else
		return 0;
}
