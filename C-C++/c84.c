#include<stdio.h>
main()
{
	int a;
	printf("Enter a number: ");
	scanf("%d",&a);
	int i;
	long int fact=1;
	for(i=1;i<=a;i++)
	{
		fact=fact*i;
	}
	printf("fact: %d\n",fact);
}
