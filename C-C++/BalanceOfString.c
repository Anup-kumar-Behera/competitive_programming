#include"stdio.h"
#include"string.h"
main()
{
	char x[20];
	printf("Enter string to check it's balanced or not: ");
	scanf("%s",x);
	char s[strlen(x)];
	int i,j=-1,c=0;
	for(i=0;i<strlen(x);i++)
	{
		if(x[i]=='[' || x[i]=='{' || x[i]=='(')
		{
			j++;
			s[j]=x[i];
		}
		else
		{
			if(s[j]=='(' && x[i]==')')
				c++;
			else if(s[j]=='[' && x[i]==']')
				c++;
			else if(s[j]=='{' && x[i]=='}')
				c++;
			j--;
		}
	}
	if((c*2)==strlen(x))
		printf("Balanced.\n");
	else
		printf("Not balanced.\n");
}
