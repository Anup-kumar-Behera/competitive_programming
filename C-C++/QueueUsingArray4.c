#include"stdio.h"
int pop();
void push(int );
int empty();
int full();
	int queue[5];
	int f=0,r=0,n=5;

main()
{
	int k,data;
	do
	{
		printf("\n1 to push.\n");
		printf("2 to pop.\n");
		printf("0 to stop.\n");
		printf("Enter choice: ");
		scanf("%d",&k);
		if(k==1)
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
		else if(k==2)
		{
			if(empty())
			{
				printf("Underflow.\n");
				continue;
			}
			data=pop();
			printf("%d",data);
		}
	}while(k!=0);
}
void push(int data)
{
	if(f==0)
	{
		f=r=1;
	}
	else
	{
		r=(r%n)+1;
	}
	queue[r]=data;
}
int pop()
{
	int k=queue[f];
	if(f==r)
		f=r=0;
	else
		f=(f%n)+1;
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
	if(f==(r%n)+1)
		return 1;
	else
		return 0;
}

