#include"stdio.h"

void push(int );
int pop();
int empty();
int full();
int x[5],y[5];
int i=-1,j=-1;

main()
{
	int n,data;
	do
	{
		printf("\n1 to push\n");
		printf("2 to pop.\n");
		printf("0 to stop.\n");
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
	i++;
	x[i]=data;
}
int pop()
{
	while(i>=0)
	{
		j++;
		y[j]=x[i];
		i--;
	}
	int k=y[j];
	j--;
	while(j>=0)
	{
		i++;
		x[i]=y[j];
		j--;
	}
	return k;
}
int empty()
{
	if(i==-1)
		return 1;
	else
		return 0;
}
int full()
{
	if(i>=4)
		return 1;
	else
		return 0;
}
