#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int c = 0;

void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void Sort(int arr[],int n)
{
	int i,j;
	for(i = 0;i < n;i++)
		for(j = 0;j < n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				c += 1;
				swap(&arr[j],&arr[j+1]);		
			}
		}
}
void printArray(int arr[],int n)
{
	for(int i = 0;i < n;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int n;
	cout<<"Enter size of the array: ";
	cin>>n;
	
	int i,arr[n];
	cout<<"Enter array elementd: \n";
	for(i = 0;i < n;i++)
	{
		cout<<"Enter "<<i+1<<"array element: ";
		cin>>arr[i];
	}
	cout<<"Array before sorting: \n";
	printArray(arr,n);
	
	Sort(arr,n);
	cout<<"\nArray after sorting:\n";
	printArray(arr,n);
	
	cout<<endl<<"No of inversions: "<<c<<endl;
	return 0;
}
