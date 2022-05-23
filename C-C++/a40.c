#include"stdio.h"
main()
{
	int n=8;
	int a[n];
	printf("Enter the array elements:	\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter %d array element 	:",i+1);
		scanf("%d",&a[i]);
	}
	int j=n,m;
	printf("Enter the position to insert an element:");
	scanf("%d",&m);
	int k;
	printf("\nEnter the element to insert: ");
	scanf("%d",&k);

	if(m>n)
		printf("\nInvalid Key!\n");
	else
	{
		while(j>m)
		{
			a[j]=a[j-1];
				j--;
		}
		n=n+1;
	}

	a[m]=k;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
