#include<stdio.h>
main()
{
	int n;
	printf("enter size of the array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter array elements: \n");
	for(i = 0;i < n;i++)
	{
		printf("Enter %d array element: ",i+1);
		scanf("%d",&a[i]);
	}
	int temp;
	for(i=0;i<n;i++)
		for(j = i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	printf("\nArray after bubble sort: \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
