#include"stdio.h"
int top=-1;
void push(int );
int pop();
int empty();
int full();
int stk[5];
main()
{
	int c;
	int data;
	do
	{
		printf("\n 1 to push. ");
		printf("\n 2 to pop.");
		printf("\n 0 to stop.");
		printf("\nEnter choice: ");
		scanf("%d",c);
		if(c==1)
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
		else if(c==2)
		{
			if(empty())
			{
				printf("Stack is empty.\n");
				continue;
			}
			data=pop();
			printf("%d\n",data);
		}
	}while(c!=0);
}
void push(int data)
{
	top++;
	stk[top]=data;
}
int pop()
{
	int item=stk[top];
	top--;
	return item;
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
