#include"stdio.h"
#include"math.h"
void binary();
main()
{
	int a;
	do
	{
		printf("\n1 to enter decimal number.\n");
		printf("0 to exit.\n");	
		printf("Enter choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 0: break;
			
			case 1: binary();
					break;
		}
	}while(a!=0);
}
void binary()
{
	int n,i=-1;
	printf("Enter decimal number: ");
	scanf("%d",&n);
	int s=log(n)/log(2)+1;
	int x[s];
	while(n>0)
	{
		i++;
		x[i]=n%2;
		n/=2;
	}
	printf("Binary of the entered Decimal number  is:	");
	while(i>=0)
	{
		printf("%d",x[i]);
		i--;
	}
	printf("\n");
}
