#include"stdio.h"
int pop();
void push(int );
int empty();
int full();
int x[5];
int r=-1,f=-1;

main()
{
	int data,n;
	do
	{
		printf("\n1 to push.\n");
		printf("2 to pop.\n");
		printf("0 to exit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			if(full())
			{
				printf("Queue if full.\n");
				continue;
			}
			printf("Enter data:  ");
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
			printf("%d",data);
		}
	}while(n!=0);
}
void push(int data) 
{
	if(r==-1 && f==-1)
	{
		r=f=0;
	}
	x[r]=data;
	r++;
}
int pop()
{
	int k=x[f];
	f++;
	return k;
}
int empty()
{
	if(f==r)
	{
		f=r=-1;
		return 1;
	}
	else 
		return 0;
}
int full()
{
	if(r>4)
		return 1;
	else 
		return 0;
}
