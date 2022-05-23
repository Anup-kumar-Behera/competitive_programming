#include"stdio.h"
#include"string.h"

void pass(char []);

main()
{
	char x[20];
	printf("Enter an infix expression: ");
	scanf("%s",x);
	pass(x);
}
void pass(char x[])
{
	int n=strlen(x);
	int i,j=-1,s[n];
	for(i=0;i<n;i++)
	{
		j++;
		s[j]=x[i];
	}
	for(i=0;i<n;i++)
		printf("%c",s[i]);
	char y[20];
	/*for(i=0;i<n;i++)
	{
		strcpy(y[i],s[i]);
	}*/
	printf("\n-----------------------\n");
	printf("%s",y);
}
