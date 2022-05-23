#include<stdio.h>
main()
{
	int n;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	int i,x[n],j,temp;
	printf("Enter array elements: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d array element: ",i+1);
		scanf("%d",&x[i]);
	}
	printf("\nArray before sort: \n");
	for(i=0;i<n;i++)
		printf("%d\t",x[i]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(x[i]<x[j])
			{
				temp=x[j];
				x[j]=x[i];
				x[i]=temp;
			}
		}
		
	printf("\nArray after sort:\n");
	for(i=0;i<n;i++)
		printf("%d\t",x[i]);
}
