#include"stdio.h"
#include"string.h"
int pre(char );
void evaluate(char []);
main()
{
	char x[20];
	printf("Enter an Infix: ");
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
		printf("%c",opd[i]);
	evaluate(opd);
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
void evaluate(char  x[])
{
    int i,j=-1,a,b,c;
    int n=strlen(x);
    int stack[n];
    for(i=0;i<n;i++)
    {
        if(x[i]>=48 && x[i]<=57)
        {
            j++;
            stack[j]=x[i]-48;
        }
        else
        {
            b=stack[j];
            j--;
            a=stack[j];
            j--;
            if(x[i]=='+')
                c=a+b;
            else if(x[i]=='-')
                c=a-b;
            else if(x[i]=='*')
                c=a*b;
            else
                c=a/b;
            j++;
            stack[j]=c;
        }
    }
    printf("\n%d\n",stack[j]);
}
