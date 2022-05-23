//	ACTIVITY SELECTION PROBLEM

#include<bits/stdc++.h>
using namespace std;

/*void printMaxActivities(int start[],int finish[],int n)
{
	cout<<"Following activities are selected:\n";
	
	int i,j = 0;
	
	cout<<j<<" ";
	for(i = 1;i < n;i++)
	{
		if(start[i] >= finish[j])
		{
			cout<<i<<" ";
			j = i;
		}
	}
}
int main()
{
	int start[] = {1,3,0,5,8,5};
	int finish[] = {2,4,6,7,9,9};
	int n = sizeof(start)/sizeof(start[0]);
	printMaxActivities(start,finish,n);
	
	return 0;
}*/

// If not sorted

struct Activities{
	int start,finish;
};

bool comparator(Activities a,Activities b){
	return a.finish < b.finish;
}
void printMaxActivity(Activities arr[],int n)
{
	sort(arr,arr+n,comparator);
	cout<<"Following Activities are selected:\n";
	
	int i = 0;
	cout<<"("<<arr[i].start<<","<<arr[i].finish<<")"<<" ";
	
	for(int j = 1;j < n;j++)
	{
		if(arr[j].start >= arr[i].finish)
		{
			cout<<"("<<arr[j].start<<","<<arr[j].finish<<")"<<" ";
			i = j;
		}
	}
	
}
int main()
{
	Activities arr[] = {{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printMaxActivity(arr,n);
	
	return 0;
}
