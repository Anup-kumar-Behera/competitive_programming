#include"stdio.h"

main()
{
	int n;
	printf("Enter the size of the square matrix: ");
	scanf("%d",&n);
	int a[n][n];
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter a[%d][%d]array element:  ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>i && j<i|| j==i)
				printf("%d ",a[i][j]);
		}
	}
}
