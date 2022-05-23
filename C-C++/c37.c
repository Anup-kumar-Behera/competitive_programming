//	GCD OF TWO NUMBERS	
#include<stdio.h>
int gcd(int ,int );
main()
{
	int a,b;
	printf("Enter two integers: ");
	scanf("%d %d ",&a,&b);
	int g=gcd(a,b);
	printf("gcd of two numbers %d \n",g);
}
int gcd(int a,int b)
{
	int c;
	while((c=a%b)!=0)
	{
		a=b;
		b=c;
	}
	return b;
}
