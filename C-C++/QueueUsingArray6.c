#include"stdio.h"
void push(int );
int pop();
int empty();
int full();

int x[5];
int s=5,r=0,f=0;

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
	if(f==0)
	{
		f=r=1;
	}
	else
	{
		r=(r%s)+1;
	}
	x[r]=data;
}
int pop()
{
	int k=x[f];
	if(f==r)
	{
		f=r=0;
	}
	else
	{
		f=(f%s)+1;
	}
	return k;
}
int full()
{
	if(f==(r%s)+1)
		return 1;
	else
		return 0;
}
int empty()
{
	if(f==0)
		return 1;
	else
		return 0;
}
