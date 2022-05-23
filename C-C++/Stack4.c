#include"stdio.h"
int top=-1;
int x[5];

void push(int );
int pop();
int full();
int empty();

main()
{
	int data;
	int n;
	do
	{
		printf("\n1 for push.\n");
		printf("2 to pop.\n");
		printf("0 to quit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			if(full())
			{
				printf("Stack is full.\n");
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
				printf("Stack is empty.\n");
				continue;
			}
			data=pop();
			printf("%d",data);
		}
	}while(n!=0);
}
void push(int data)
{
	top++;
	x[top]=data;
}
int pop()
{
	int k=x[top];
	top--;
	return k;
}
int empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int full()
{
	if(top==5)
		return 1;
	else
		return 0;
}
