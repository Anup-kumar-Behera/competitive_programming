#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l,int h)
{
	int pivot = arr[h];
	int i = (l-1);
	
	for(int j = l;j <= h-1;j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	
	return (i+1);
}

int partition2(int arr[],int l,int h)
{
	int pivot = arr[l];
	int i = l - 1,j = h + 1;
	
	while(true){
		do
		{
			i ++;
		}while(arr[i] < pivot);
		
		
		do{
			j --;
		}while(arr[j] > pivot);
		
		if(i >= j)
			return j;
			
		swap(arr[i], arr[j]);
	}
	
}

void quickSort(int *arr,int low,int high)
{
	if(low < high)
	{
		//int pi = partition(arr,low,high);
		int pi = partition2(arr,low,high);
		
		//quickSort(arr,low,pi-1);
		quickSort(arr,low,pi);
		quickSort(arr,pi+1,high);
	}
}

int main()
{
	int n;
	cout<<"Enter size of the array: ";
	cin>>n;
	
	int i,arr[n];
	cout<<endl<<"Enter array elements: "<<endl;
	for(i = 0;i < n;i++)
	{
		cout<<"Enter "<<i+1<<" array element: ";
		cin>>arr[i];
	}
	cout<<endl<<"Array before sorting:\n";
	for(i = 0;i < n;i++)
		cout<<arr[i]<<" ";
	
	quickSort(arr,0,n-1);
	cout<<endl<<"Array after sorting\n";
	for(i = 0;i < n;i++)
		cout<<arr[i]<<" ";
		
	return 0;
}
