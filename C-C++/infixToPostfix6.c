#include"stdio.h"
#include"string.h"
int pre(char );
int* InfixToPostfix(char []);
//void evaluate();

main()
{
	char x[20];
	printf("Enter an infix expression: ");
	scanf("%c",x);
	int i,*p=InfixToPostfix(x);
	for(i=0;i<strlen(x);i++)
		printf("%c",p[i]-48);
	
}
int* InfixToPostfix(char x[])
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
			}
		}
		while(k>=0)
		{
			j++;
			opd[j]=opr[k];
			k--;
		}
	}
	return opd;
}
int pre(char m)
{
	switch(m)
	{
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
	}
}
