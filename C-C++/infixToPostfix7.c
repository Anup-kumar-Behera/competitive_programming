#include"stdio.h"
#include"string.h"

int pre(char );
void infixToPostfix(char []);
int evaluate(char []);

main()
{
	char x[20];
	printf("\nEnter an infix expression: ");
	scanf("%s",x);
	
	infixToPostfix(x);
	printf("Postfix Evaluation is : %d\n",evaluate(x));
}

void infixToPostfix(char x[])
{
	int n=strlen(x);
	int i,j=-1,k=-1,opd[n],opr[n],a,b;
	for(i=0;i<n;i++)
	{
		if(x[i]>=48 && x[i]<=57)
		{
			j++;
			opd[j]=x[i];
		}
		else
		{
			if(k==-1)
			{
				k++;
				opr[k]=x[i];
			}
			else
			{
				a=pre(x[i]);
				b=pre(opr[k]);
				while(k>=0 && a<=b)
				{
					j++;
					opd[j]=opr[k];
					k--;
					if(k==-1)
						break;
					b=pre(opr[k]);
				}
				k++;
				opr[k]=x[i];
			}
		}
	}
	while(k>=0)
	{
		j++;
		opd[j]=opr[k];
		k--;
	}
	for(i=0;i<=j;i++)	
	{
		printf("%c",opd[i]);
	}
}

int pre(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
	}
}

int evaluate(char x[])
{
	int n=strlen(x);
	int i,j=-1,s[n],a,b,c;
	for(i=0;i<n;i++)
	{
		if(x[i]>=48 && x[i]<=57)
		{
			j++;
			s[j]=x[i]-48;
		}
		else
		{
			b=s[j];
			j--;
			a=s[j];
			j--;
			if(x[i]=='+')
				c=a+b;
			else if(x[i]=='-')
				c=a-b;
			else if(x[i]=='*')
				c=a*b;
			else if(x[i]=='/')
				c=a/b;
			j++;
			s[j]=c;
		}
	}
	return s[j];
}
