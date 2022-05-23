#include"stdio.h"

int top=-1;
void push(int );
int pop();
int empty();
int full();
int stack[5];

main()
{
	int n;
	int data;
	do
	{
		printf("\n1 for push.\n");
		printf("2 to pop.\n");
		printf("0 to stop.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		if(n==1)
		{
			if(full())
			{
				printf("stack is full.\n");
				continue;
			}
			printf("Enter data to insert: ");
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
	top++;
	stack[top]=data;
}
int pop()
{
	int k=stack[top];
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
	if(top>=5)
		return 1;
	else
		return 0;
}
