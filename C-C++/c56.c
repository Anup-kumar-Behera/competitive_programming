// 	SORTING USING BUBBLE SORT

#include"stdio.h"
main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int i,x[n],temp;
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	int j;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(x[j]>x[j+1])
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	printf("\nSorted array elements: \n");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n\n");
	
}
