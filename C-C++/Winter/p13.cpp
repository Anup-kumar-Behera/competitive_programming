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
	for(i = 0;i<n;i++)
	{
		temp = a[i];
		j = i;
		while(a[j-1] > temp && j >= 1)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
	}
	printf("\nArray after bubble sort: \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
