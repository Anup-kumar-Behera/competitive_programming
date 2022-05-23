#include"stdio.h"
#include"math.h"

main()
{
	int n,i=-1;
	printf("Enter a number: ");
	scanf("%d",&n);
	int s=log(n)/log(2)+1;
	int x[s];
	while(n>0)
	{
		i++;
		x[i]=n%2;
		n/=2;
	}
	while(i>=0)
	{
		printf("%d",x[i]);
		i--;
	}
}
