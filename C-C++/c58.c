// SORTING USING INSERTION SORT

#include"stdio.h"
main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int x[n],i,j,temp;
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		temp=x[i];
		j=i;
		while(x[j-1]>temp && j>=1)
		{
			x[j]=x[j-1];
			j--;
		}
		x[j]=temp;
	}
	printf("\nArray after sorting: \n");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
}
