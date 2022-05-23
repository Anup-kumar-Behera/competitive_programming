// PROGRAM TO ROTATE AN ARRAY BY K ELEMENTS

#include<stdio.h>

void rotatebyone(int arr[],int n)
{
	int temp = arr[0], i;
	for(i = 0;i < n-1;i++)
		arr[i] = arr[i+1];
	arr[i] = temp;
}
void rotatebyk(int arr[],int n,int k)
{
	int i;
	for(i = 0;i < k;i++)
		rotatebyone(arr,n);
}
main()
{
	int n;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	
	int i,arr[n];
	printf("\nEnter array elements: \n");
	for(i = 0;i < n;i++)
	{
		printf("Enter %d array element: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	int k;
	printf("\nEnter value of k: ");
	scanf("%d",&k);
	
	rotatebyk(arr,n,k);
	printf("\narray after rotation:\n");
	for(i = 0;i < n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
