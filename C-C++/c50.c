#include"stdio.h"
int fact_r(int );

main()
{
	int n;
	printf("Enter integer whose factorial is to be calculated: ");
	scanf("%d",&n);
	int k=fact_r(n);
	printf("Factorial of %d is : %d\n",n,k);
}

int fact_r(int n)
{
	int k;
	int fact;
	if(n==0)
	{
		fact=1;
		return fact;
	}
	fact=fact_r(n-1);
	fact=n*fact;
	return fact;
}
