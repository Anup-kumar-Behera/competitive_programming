#include<stdio.h>

void leftRotate(int *arr,int n)
{
	int temp = arr[0];
	int i;
	for(i = 0;i < n-1;i++)
		arr[i] = arr[i+1];
	arr[n-1] = temp;
}

int *leftRot(int *arr,int n,int d)
{
	int i;
	for(i = 0;i < d;i++)
		leftRotate(arr,n);
	return arr;
}
main()
{
	int arr[] = {1,2,3,4,5};
	int n = 5;
	int *a = leftRot(arr,n,4);
	
	int i;
	//leftRotate(arr,n);
	for(i = 0;i < n;i++)
		printf("%d ",a[i]);
}
