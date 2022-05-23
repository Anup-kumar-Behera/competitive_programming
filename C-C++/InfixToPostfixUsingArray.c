#include"stdio.h"
#include"stdlib.h"
#include"string.h"
int pre(char );

main()
{
	char x[20];
	printf("Enter Infix Expression: ");
	scanf("%s",x);
	char opd[strlen(x)],opr[strlen(x)];
	int i,j=-1,k=-1,a,b;
	for(i=0;i<strlen(x);i++)
	{
		if(x[i]>=48 && x[i]<=57)
		{
			j++;
			opd[j]=x[i];
		}
		else
		{
			if(k==-1)
			opr[k]=x[i];
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
		printf("%c",opd[i]);
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
