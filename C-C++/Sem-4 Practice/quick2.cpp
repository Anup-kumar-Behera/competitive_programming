#include<stdio.h>

void quicksort(int arr[],int high,int low)
{
	if(low < high)
	{
		int pivot = partition(arr,low,high);
		
		quicksort(arr,low,pivot-1);
		quicksort(arr,pivot+1,high);
	}
}

int partition(int arr[],int low,int high)
{
	int pivot = arr[high];
	int l = (low-1);
	
	while(low < high)
	{
		if(arr[low] < arr[high])
			l++;
		else
		{
			
		}
	}
}

main()
{
	int n;
	printf("Enter size if array:");
	scanf("%d",&n);
	
	int i,arr[n];
	printf("Enter array elements:\n");
	for(i = 0;i < n;i++)
	{
		printf("Enter %d array data: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nArray elements are: \n");
	for(i = 0;i < n;i++)
		printf("%d ",arr[i]);
}
