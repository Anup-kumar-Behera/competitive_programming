#include"stdio.h"
#include"string.h"
#include"stdlib.h"

#define size 100
char stack[size];
int top=-1;

void push(char item)
{
	if(top>=size-1)
	{
		printf("stack overflow.\n");
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
char pop()
{
	char item;
	if(top<0)
		printf("Underflow.\n");
	else
	{
		item=stack[top];
		top--;
		return (item);
	}
}
int is_operator(char symbol)
{
	if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-')
		return 1;
	else
		return 0;
}
int precedence(char symbol)
{
	if(symbol=='^')
		return 3;
	else if(symbol=='/' || symbol=='*')
		return 2;
	else if(symbol=='-' || symbol=='+')
		return 1;
	else
		return 0;
}
void InfixToPostfix(char a[],char b[])
{
	int i=0,j=0;
	char item,x;
	
	push('(');
	strcat(a,")");
	
	item=a[i];
	while(item!='\0')
	{
		if(item=='(')
			push(item);
		else if(isdigit(item) || isalpha(item))
		{
			b[j]=item;
			j++;
		}
		else if(is_operator(item)==1)
		{
			x=pop();
			while(is_operator(x)==1 && precedence(x)>=precedence(item))
			{
				b[j]=x;
				j++;
			}
			push(x);
			push(item);
		}
		else if(item==')')
		{
			x=pop();
			while(x!='(')
			{
				b[j]=x;
				j++;
				x=pop();
			}
		}
		else
			printf("Invalid Infix Expression.\n");
		i++;
		item=a[i];
	}
	if(top>0)
		printf("Invalid Expression.\n");
	b[j]='\0';
}
main()
{
	char a[size],b[size];
	printf("Enter an Infix Expression: ");
	scanf("%d",a);
	InfixToPostfix(a,b);
	printf("%s",b);
}
