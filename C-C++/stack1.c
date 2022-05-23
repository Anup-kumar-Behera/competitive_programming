//#include"iostream.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
//using namespace std;

void push(int );
int pop();
int empty();
int full();
char x[5];
int i=-1;
main()
{
	int n;
	int data;
	do
	{
		printf("\n 1 for push.");
		printf("\n 2 for pop.");
		printf("\n 0 to stop.");
		scanf("%d",&n);
		if(n==1)
		{
			if(full())
			{
				printf("Stack is full.\n");
				continue;
			}
			printf("Enter data To insert: ");
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
			printf("%d\n",data);
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
	int k=x[i];
	i--;
	return k;
}
int full()
{
	if(i>=4)	
		return 1;
	else
		return 0;
}
int empty()
{
	if(i==-1)
		return 1;
	else
		return 0;
}
