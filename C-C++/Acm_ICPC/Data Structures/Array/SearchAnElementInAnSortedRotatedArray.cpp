#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int low,int high,int key)
{
	if(high < low) return -1;
		
	int mid = (low+high)/2;
	
	if(key = arr[mid])
		return mid;
	if(key > arr[mid])
		return binarySearch(arr,mid+1,high,key);
	else 
		return binarySearch(arr,low,mid+1,key);
	
}

int findPivot(int *arr,int low,int high)
{
	if(high < low)
		return -1;
	if(high == low)
		return low;
		
	int mid = (low+high)/2;
	if(mid < high && arr[mid] > arr[mid+1])
		return mid;
	
	if(mid > low && arr[mid] < arr[mid-1])
		return (mid-1);
	
	if(arr[low] > arr[mid])	
		return findPivot(arr,low,mid-1);
	
	return 
		findPivot(arr,mid+1,high);
}

int pivotedBinarySearch(int *a,int low,int high,int key)
{
	int pivot = findPivot(a,low,high);
	
	if(pivot == -1)
		return binarySearch(a,low,high,key);
	
	if(a[pivot] == key)
		return pivot;
	
	if(a[low] <= key)
		return binarySearch(a,low,pivot-1,key);
	
	return binarySearch(a,pivot+1,high,key);
}

int main()
{
	int arr[] = {6,7,8,1,2,3,4,5};
	int n = 8;
	
	//int k = findPivot(arr,0,n-1);
	//cout<<k<<endl;
	
	int p = pivotedBinarySearch(arr,0,7,5);
	cout<<p<<endl;
	return 0;
}

