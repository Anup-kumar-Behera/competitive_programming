#include"stdio.h"
main()
{
	int n=8;
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter %d array element : ",i+1);
		scanf("%d",&a[i]);
	}
	int j;
	printf("\nEnter the delete position");
	scanf("%d",&j);
	if(j>=n)
		printf("Invalid Key\n");
	else
	{
		while(j<=n)
		{
			a[j-1]=a[j];
				j++;
		}
		n--;
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
