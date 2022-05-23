#include<stdio.h>
#include<string.h>
main()
{
	char n1[20];
	char n2[20];
	printf("Enter name	:");
	scanf("%[^\n]s",n1);
	strcpy(n2,n1);
	printf("%s	 ,	%s \n",n1,n2);
}
