//	SORTING WITH SELECTION SORT

#include"stdio.h"
main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int i,j,temp;
	int x[n];
	printf("Enter array elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(x[i]>x[j])
			{
				temp=x[j];
				x[j]=x[i];
				x[i]=temp;
			}
		}
	printf("\nArray after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n\n");
}
