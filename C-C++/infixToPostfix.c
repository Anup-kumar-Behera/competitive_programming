// INFIX TO POSTFIX

#include"stdio.h"
#include"string.h"

int pre(char);
main()
{
	char x[20];
	printf("Enter an infix expression:");
	scanf("%s",x);
	int opr=(strlen(x)),opd=(strlen(x));
	int a,b,i,j=-1,k=-1;
	for(i=0;i<strlen(x);i++)
	{
		if(x[i]>=48 && x[i]<=57)
		{
			k++;
			opd[k]=x[i];
		}
		else
		{
			if(j==-1)
			{
				j++;
				opr[j]=x[i];
			}
			else
			{
				a=pre(x[i]);
				b=pre(opr[j];
				while(k>=0 && a<=b)
				{
					k++;
					opd[k]=opr[j];
					j--;
					if(j==-1)
						break;
					b=pre(opr[j]);
				}
				j++;
				opr[j]=x[i];
			}
		}
	}
	while(j>=0)
	{
		k++;
		opd[k]=opr[j];
		j--;
	}
	for(i=0;i<=k;i++)
	{
		printf("%c",opd[i]);
	}
}
int pre(char m)
{
	switch(m)
	{
		case '+':
		case '-':
			return 4;
		case '*':
		case '/':
			return 5;
	}
}
