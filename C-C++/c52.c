#include"stdio.h"
#include"stdlib.h"
int pop();
void push(int );
int emoty();
int full();
void traverse();

int x[5],y[5],t1=-1,t2=-1;

main()
{
	int data,n;
	do
	{
		printf("\n1 for push.\n");
		printf("2 for pp.\n");
		printf("3 for traverse.\n");
		printf("0 to stop.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			if(full())
			{
				printf("Overflow.\n");
				continue;
			}
			printf("Enter data:");
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
			traverse();
		}
	}while(n!=0);
}
void push(int data)
{
	if(t1==-1)
	{
		t1++;
		x[t1]=data;
	}
	else if(data>x[t1])
	{
		t1++;
		x[t1]=data;
	}
	else
	{
		while(t1>=0 && data<x[t1])
		{
			t2++;
			y[t2]=x[t1];
			t1--;
		}
		t1++;
		x[t1]=data;
		while(t2>=0)
		{
			t1++;
			x[t1]=y[t2];
			t2--;
		}
	}
}
int pop()
{
	int k=x[t1];
		t1--;
	return k;
}
int empty()
{
	if(t1==-1)
		return 1;
	else
		return 0;
}
int full()
{
	if(t1>=4)
		return 1;
	else 
		return 0;
}
void traverse()
{
	int k=t1;
	if(empty())
	{
		printf("Underflow.\n");
	}
	else
	{
		while(k>=0)
		{
			printf("%d  ",x[k]);
			k --;
		}
	}
}
