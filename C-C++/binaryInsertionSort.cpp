#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter size of the array: ";
	cin>>n;
	int arr[n];
	int i;
	cout<<endl;
	for(i = 0;i < n;i++)
	{
		cout<<"Enter "<<i+1<<" array element: ";
		cin>>arr[i];
	}
	
	int v,left,right,middle;
	for(i = 1;i <=n;i++)
	{
		v = arr[i];
		left = 0;
		right = i;
		while (left < right)
		{
			middle = (left+right)/2;
			if (v >= arr[middle])
				left = middle+1;
			else
				right = middle;
		}
		for(int j = i;j <= left+1;j++)
			arr[j] = arr[j-1];
		arr[left] = v;
		
	}
	
	for(i = 0;i < n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
